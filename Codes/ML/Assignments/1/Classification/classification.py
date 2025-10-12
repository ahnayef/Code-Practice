import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.preprocessing import StandardScaler, LabelEncoder, OneHotEncoder
from sklearn.impute import SimpleImputer
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.metrics import confusion_matrix, classification_report, roc_curve, auc
import re


# Display more detailed information about pandas dataframes
pd.set_option('display.max_columns', None)
pd.set_option('display.width', 200)

print("="*80)
print("Student Pass/Fail Classification Model")
print("="*80)

# Step 1: Load the data
print("\nStep 1: Loading the dataset...")
df = pd.read_csv('pass_fail.csv')
print(f"Dataset loaded with shape: {df.shape}")

# Step 2: Initial data exploration
print("\nStep 2: Initial data exploration")
print("\nFirst 5 rows:")
print(df.head())

print("\nBasic information:")
print(df.info())

print("\nSummary statistics:")
print(df.describe(include='all'))

# Step 3: Check for duplicate rows
print("\nStep 3: Checking for duplicates...")
duplicate_count = df.duplicated().sum()
print(f"Found {duplicate_count} duplicate rows")
if duplicate_count > 0:
    df = df.drop_duplicates()
    print(f"Duplicates removed. New shape: {df.shape}")

# Step 4: Data cleaning - handling various issues

# Step 4.1: Define custom cleaning functions
def clean_numeric(value):
    """Clean numeric values with various issues"""
    if pd.isna(value):
        return np.nan
    
    if isinstance(value, (int, float)):
        return value
    
    # Convert to string for cleaning
    value_str = str(value).strip()
    
    # Handle special placeholder values
    if value_str.lower() in ['nan', 'null', '?', '', 'none', 'na']:
        return np.nan
    
    # Try to extract numeric part
    try:
        numeric_match = re.search(r'[-+]?\d*\.?\d+', value_str)
        if numeric_match:
            return float(numeric_match.group())
        else:
            return np.nan
    except:
        return np.nan

# Step 4.2: Clean specific columns
print("\nStep 4: Cleaning data...")

# 4.2.1: Clean Student ID - remove from features but keep for reference
print("Extracting and setting Student ID as index...")
df['Student ID'] = df['Student ID'].str.strip() if df['Student ID'].dtype == 'object' else df['Student ID']
df.set_index('Student ID', inplace=True)

# 4.2.2: Clean numeric columns
numeric_cols = ['Study Hours per Week', 'Attendance Rate', 'Previous Grades']
for col in numeric_cols:
    print(f"Cleaning numeric column: {col}")
    df[col] = df[col].apply(clean_numeric)
    
    # Check for out-of-range values
    if col == 'Study Hours per Week':
        # Study hours should be positive and not unrealistically high (e.g., max 80 per week)
        df.loc[df[col] < 0, col] = np.nan
        df.loc[df[col] > 80, col] = 80
    elif col == 'Attendance Rate':
        # Attendance rate should be between 0 and 100
        df.loc[df[col] < 0, col] = 0
        df.loc[df[col] > 100, col] = 100
    elif col == 'Previous Grades':
        # Grades typically between 0 and 100
        df.loc[df[col] < 0, col] = 0
        df.loc[df[col] > 100, col] = 100

# 4.2.3: Clean categorical columns
print("Cleaning categorical columns...")

# Clean Participation in Extracurricular Activities
df['Participation in Extracurricular Activities'] = df['Participation in Extracurricular Activities'].str.strip() if df['Participation in Extracurricular Activities'].dtype == 'object' else df['Participation in Extracurricular Activities']
# Map variations to standard values and convert to 1/0
participation_mapping = {
    'Yes': 1,
    'yes': 1,
    'Y': 1,
    'y': 1,
    'True': 1,
    'true': 1,
    '1': 1,
    1: 1,
    'No': 0,
    'no': 0,
    'N': 0,
    'n': 0,
    'False': 0,
    'false': 0,
    '0': 0,
    0: 0
}
df['Participation in Extracurricular Activities'] = df['Participation in Extracurricular Activities'].map(participation_mapping)

# Clean Parent Education Level - handle inconsistent categories
if df['Parent Education Level'].dtype == 'object':
    df['Parent Education Level'] = df['Parent Education Level'].str.strip()
    # Standardize education levels
    education_mapping = {
        'Bachelor': 'Bachelor',
        'bachelor': 'Bachelor',
        'bachelors': 'Bachelor',
        'Bachelors': 'Bachelor',
        'B.S.': 'Bachelor',
        'B.A.': 'Bachelor',
        'BS': 'Bachelor',
        'BA': 'Bachelor',
        
        'Master': 'Master',
        'master': 'Master',
        'masters': 'Master',
        'Masters': 'Master',
        'M.S.': 'Master',
        'M.A.': 'Master',
        'MS': 'Master',
        'MA': 'Master',
        
        'Doctorate': 'Doctorate',
        'doctorate': 'Doctorate',
        'PhD': 'Doctorate',
        'phd': 'Doctorate',
        'Ph.D.': 'Doctorate',
        'Ph.D': 'Doctorate',
        
        'Associate': 'Associate',
        'associate': 'Associate',
        'associates': 'Associate',
        'Associates': 'Associate',
        'A.A.': 'Associate',
        'AA': 'Associate',
        
        'High School': 'High School',
        'high school': 'High School',
        'highschool': 'High School',
        'Highschool': 'High School',
        'HS': 'High School',
        'high': 'High School',
        'High': 'High School',
        'secondary': 'High School',
        'Secondary': 'High School'
    }
    df['Parent Education Level'] = df['Parent Education Level'].map(lambda x: education_mapping.get(x, x))

# Clean Passed column (target variable) and convert to 1/0
if df['Passed'].dtype == 'object':
    df['Passed'] = df['Passed'].str.strip()
    passed_mapping = {
        'Yes': 1,
        'yes': 1,
        'Y': 1,
        'y': 1,
        '1': 1,
        'true': 1,
        'True': 1,
        1: 1,
        'No': 0,
        'no': 0,
        'N': 0,
        'n': 0,
        '0': 0,
        'false': 0,
        'False': 0,
        0: 0
    }
    df['Passed'] = df['Passed'].map(passed_mapping)

# Step 5: Check for missing values
print("\nStep 5: Handling missing values...")
missing_values = df.isnull().sum()
print("Missing values per column:")
print(missing_values)

# Step 5.1: Handle missing values
print("\nHandling missing values...")

# First, drop rows where categorical columns and target have missing values
cat_cols = ['Participation in Extracurricular Activities', 'Parent Education Level', 'Passed']
rows_before = df.shape[0]
df = df.dropna(subset=cat_cols)
rows_dropped = rows_before - df.shape[0]
print(f"Dropped {rows_dropped} rows with missing values in categorical columns and target variable")

# For remaining numeric columns, fill with median
print("Filling remaining numeric missing values with median...")
for col in numeric_cols:
    median_value = df[col].median()
    print(f"  {col}: filling {df[col].isnull().sum()} missing values with median ({median_value:.2f})")
    df[col].fillna(median_value, inplace=True)

# Step 6: Handle outliers for numeric columns
print("\nStep 6: Handling outliers...")

def handle_outliers(df, column):
    """Handle outliers using IQR method"""
    Q1 = df[column].quantile(0.25)
    Q3 = df[column].quantile(0.75)
    IQR = Q3 - Q1
    lower_bound = Q1 - 1.5 * IQR
    upper_bound = Q3 + 1.5 * IQR
    
    outliers_count = ((df[column] < lower_bound) | (df[column] > upper_bound)).sum()
    print(f"  {column}: {outliers_count} outliers detected")
    
    if outliers_count > 0:
        # Cap outliers
        df[column] = np.where(df[column] < lower_bound, lower_bound, df[column])
        df[column] = np.where(df[column] > upper_bound, upper_bound, df[column])
    
    return df

for col in numeric_cols:
    df = handle_outliers(df, col)

# Step 7: Handle inconsistent data types and encode categorical features
print("\nStep 7: Encoding categorical features...")

# Note: Participation in Extracurricular Activities is already encoded as 1/0

# One-hot encode Parent Education Level
print("One-hot encoding Parent Education Level...")
edu_dummies = pd.get_dummies(df['Parent Education Level'], prefix='Education')
df = pd.concat([df, edu_dummies], axis=1)

# Note: Target variable 'Passed' is already encoded as 1/0
print(f"Target variable is already encoded as binary (0/1)")
print(f"Target distribution: {df['Passed'].value_counts().to_dict()}")

# Step 8: Feature selection
print("\nStep 8: Feature selection...")
# Drop original categorical columns
X = df.drop(['Participation in Extracurricular Activities', 'Parent Education Level', 'Passed'], axis=1)
y = df['Passed']

# Feature importance using Random Forest
rf_feat = RandomForestClassifier(n_estimators=100, random_state=42)
rf_feat.fit(X, y)

feature_importance = pd.DataFrame({
    'Feature': X.columns,
    'Importance': rf_feat.feature_importances_
})
feature_importance = feature_importance.sort_values('Importance', ascending=False)
print("\nFeature importance:")
print(feature_importance)

# Step 9: Feature scaling
print("\nStep 9: Feature scaling...")
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Step 10: Split the data
print("\nStep 10: Splitting data into train and test sets...")
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)
print(f"Training set shape: {X_train.shape}")
print(f"Test set shape: {X_test.shape}")

# Step 11: Model training and evaluation
print("\nStep 11: Training and evaluating models...")

# Define a function to evaluate models
def evaluate_model(model, X_train, X_test, y_train, y_test, model_name):
    # Train the model
    model.fit(X_train, y_train)
    
    # Make predictions
    y_pred = model.predict(X_test)
    
    # Calculate metrics
    acc = accuracy_score(y_test, y_pred)
    prec = precision_score(y_test, y_pred)
    rec = recall_score(y_test, y_pred)
    f1 = f1_score(y_test, y_pred)
    
    # Cross-validation score
    cv_scores = cross_val_score(model, X_scaled, y, cv=5, scoring='accuracy')
    
    print(f"\n{model_name} Results:")
    print(f"Accuracy: {acc:.4f}")
    print(f"Precision: {prec:.4f}")
    print(f"Recall: {rec:.4f}")
    print(f"F1 Score: {f1:.4f}")
    print(f"5-Fold CV Accuracy: {cv_scores.mean():.4f} (±{cv_scores.std():.4f})")
    
    # Confusion matrix
    cm = confusion_matrix(y_test, y_pred)
    print("\nConfusion Matrix:")
    print(cm)
    
    # Classification report
    print("\nClassification Report:")
    print(classification_report(y_test, y_pred, target_names=['Failed', 'Passed']))
    
    # Save confusion matrix plot
    plt.figure(figsize=(8, 6))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', 
                xticklabels=['Failed', 'Passed'], 
                yticklabels=['Failed', 'Passed'])
    plt.xlabel('Predicted')
    plt.ylabel('Actual')
    plt.title(f'Confusion Matrix - {model_name}')
    plt.tight_layout()
    plt.savefig(f'confusion_matrix_{model_name.replace(" ", "_").lower()}.png')
    
    # If the model supports predict_proba, create ROC curve
    if hasattr(model, "predict_proba"):
        y_prob = model.predict_proba(X_test)[:, 1]
        fpr, tpr, _ = roc_curve(y_test, y_prob)
        roc_auc = auc(fpr, tpr)
        
        plt.figure(figsize=(8, 6))
        plt.plot(fpr, tpr, label=f'ROC curve (area = {roc_auc:.2f})')
        plt.plot([0, 1], [0, 1], 'k--')
        plt.xlim([0.0, 1.0])
        plt.ylim([0.0, 1.05])
        plt.xlabel('False Positive Rate')
        plt.ylabel('True Positive Rate')
        plt.title(f'ROC Curve - {model_name}')
        plt.legend(loc="lower right")
        plt.savefig(f'roc_curve_{model_name.replace(" ", "_").lower()}.png')
    
    return model, acc

# Train and evaluate models
models = {
    'Logistic Regression': LogisticRegression(max_iter=1000, random_state=42),
    'Random Forest': RandomForestClassifier(n_estimators=100, random_state=42),
    'Gradient Boosting': GradientBoostingClassifier(n_estimators=100, random_state=42),
    'Support Vector Machine': SVC(probability=True, random_state=42)
}

results = {}
for name, model in models.items():
    print(f"\nTraining {name}...")
    trained_model, accuracy = evaluate_model(model, X_train, X_test, y_train, y_test, name)
    results[name] = (trained_model, accuracy)

# Step 12: Identify the best model
best_model_name = max(results, key=lambda k: results[k][1])
best_model, best_accuracy = results[best_model_name]

print("\nStep 12: Best model identification")
print(f"Best model: {best_model_name} with accuracy {best_accuracy:.4f}")

# Step 13: Feature importance visualization for best model (if applicable)
print("\nStep 13: Visualizing feature importance for the best model...")
if best_model_name in ['Random Forest', 'Gradient Boosting']:
    feature_importances = best_model.feature_importances_
    
    # Create a DataFrame for visualization
    importance_df = pd.DataFrame({
        'Feature': X.columns,
        'Importance': feature_importances
    })
    importance_df = importance_df.sort_values('Importance', ascending=False)
    
    # Plot feature importance
    plt.figure(figsize=(10, 6))
    sns.barplot(x='Importance', y='Feature', data=importance_df)
    plt.title(f'Feature Importance - {best_model_name}')
    plt.tight_layout()
    plt.savefig('feature_importance.png')
    print("Feature importance plot saved as 'feature_importance.png'")
    
    print("\nTop 5 important features:")
    print(importance_df.head(5))

# Step 14: Save results summary
print("\nStep 14: Saving results summary...")
with open('classification_results.txt', 'w') as f:
    f.write("Student Pass/Fail Classification Results\n")
    f.write("="*40 + "\n\n")
    f.write(f"Dataset shape after cleaning: {df.shape}\n")
    f.write(f"Features used: {', '.join(X.columns)}\n\n")
    f.write("Model Performance Summary:\n")
    for name, (_, acc) in results.items():
        f.write(f"{name}: Accuracy = {acc:.4f}\n")
    f.write(f"\nBest model: {best_model_name} with accuracy {best_accuracy:.4f}\n")

print("\nClassification analysis completed successfully!")
print("Results summary saved as 'classification_results.txt'")
print("\nVisualization files saved:")
print("- Confusion matrices for each model")
print("- ROC curves for applicable models")
print("- Feature importance plot for the best model (if applicable)")
