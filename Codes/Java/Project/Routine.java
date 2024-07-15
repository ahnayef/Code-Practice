import java.awt.*;
import javax.swing.*;
import javax.swing.table.*;
import java.util.*;
import java.util.List;
import java.text.*;

public class Routine extends JFrame {

        private class user {
                private String userName;
                private String password;

                public user(String userName, String password) {
                        this.userName = userName;
                        this.password = password;
                }

                public String getUserName() {
                        return userName;
                }

                public String getPassword() {
                        return password;
                }
        }

        user u1 = new user("ahn", "ahn123");

        class Subject {
                String name;
                String teacher;
                String time;
                String roomNo;
                String courseCode;
                Boolean lab;

                public Subject(String name, String teacher, String time, String roomNo, String courseCode,
                                Boolean lab) {
                        this.name = name;
                        this.teacher = teacher;
                        this.time = time;
                        this.roomNo = roomNo;
                        this.courseCode = courseCode;
                        this.lab = lab;
                }
        }

        private List<Map<String, String>> courseList = new ArrayList<>(Arrays.asList(
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Object Oriented Programming Language");
                                        put("Instructor", "Mr. Pranta Sarker");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Algorithm Design & Analysis");
                                        put("Instructor", "Muthmainna Mou");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Digital Logic Design");
                                        put("Instructor", "K. M. Asif-uz-zaman");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Basic Statistics and Probability");
                                        put("Instructor", "Mr. Mohammad Salah Uddin");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Principles of Accounting");
                                        put("Instructor", "Mr. Nasir Uddin");
                                }
                        }));

        private Map<String, List<Subject>> weeklyRoutine = new HashMap<String, List<Subject>>() {
                {
                        put("sunday", new ArrayList<Subject>(Arrays.asList(
                                        new Subject("Basic Statistics and Probability", "Mr. Mohammad Salah Uddin",
                                                        "8:30 - 9:55", "R-412", "STA-05422101", false),
                                        new Subject("Digital Logic Design", "K. M. Asif-uz-zaman", "10:00 - 11:25",
                                                        "R-214", "CSE-06132115", false))));
                        put("monday", new ArrayList<Subject>(Arrays.asList(
                                        new Subject("Algorithm Design & Analysis Lab", "Muthmainna Mou", "8:30 - 11:25",
                                                        "R-309", "CSE-06132114", true),
                                        new Subject("Object Oriented Programming Language", "Mr. Pranta Sarker",
                                                        "11:30 - 12:55", "R-412", "CSE-06132111", false))));
                        put("tuesday", new ArrayList<Subject>(Arrays.asList(
                                        new Subject("Object Oriented Programming Language", "Mr. Pranta Sarker",
                                                        "10:00 - 11:25", "R-412", "CSE-06132111", false),
                                        new Subject("Digital Logic Design", "K. M. Asif-uz-zaman", "11:30 - 12:55",
                                                        "R-309", "CSE-06132115", false))));
                        put("wednesday", new ArrayList<Subject>(Arrays.asList(
                                        new Subject("Digital Logic Design Lab", "K. M. Asif-uz-zaman", "8:30 - 11:25",
                                                        "R-309", "CSE-06132116", true),
                                        new Subject("Principles of Accounting", "Mr. Nasir Uddin", "1:00 - 2:25",
                                                        "R-412", "BUS-04112101", false))));
                        put("thursday", new ArrayList<Subject>(Arrays.asList(
                                        new Subject("Basic Statistics and Probability", "Mr. Mohammad Salah Uddin",
                                                        "8:30 - 9:55", "R-412", "STA-05422101", false),
                                        new Subject("Object Oriented Programming Language Lab", "Mr. Pranta Sarker",
                                                        "10:00 - 12:55", "R-309", "CSE-06132112", true))));
                }
        };

        String[] columnNames = { "Course Title", "Instructor" };
        Object[][] data = new Object[courseList.size()][];
        {
                for (int i = 0; i < courseList.size(); i++) {
                        data[i] = new Object[] { courseList.get(i).get("Course Title"),
                                        courseList.get(i).get("Instructor") };
                }
        }
        DefaultTableModel tableModel = new DefaultTableModel(data, columnNames);

        void updateTableData(List<Map<String, String>> courseList, DefaultTableModel tableModel) {
                tableModel.setRowCount(0);
                for (Map<String, String> course : courseList) {
                        Object[] row = { course.get("Course Title"), course.get("Instructor") };
                        tableModel.addRow(row);
                }
        }

        JPanel routinePanel;

        void addSubjectToRoutinePanel(Subject course) {
                JPanel routineBox = new JPanel();
                JLabel subjectLabel = new JLabel(course.name);
                JLabel courseCodeLabel = new JLabel(course.courseCode);
                JLabel teacherLabel = new JLabel(course.teacher);
                JLabel timeLabel = new JLabel(course.time);
                JLabel roomLabel = new JLabel(course.roomNo);

                routineBox.setLayout(new BoxLayout(routineBox, BoxLayout.Y_AXIS));
                routineBox.setBackground(backgroundColor);
                routineBox.setForeground(textColor);
                routineBox.setAlignmentX(Component.CENTER_ALIGNMENT);
                routineBox.setAlignmentY(Component.CENTER_ALIGNMENT);
                routineBox.setBorder(BorderFactory.createCompoundBorder(BorderFactory.createLineBorder(primary, 1),
                                BorderFactory.createEmptyBorder(10, 10, 10, 10)));

                subjectLabel.setForeground(textColor);
                courseCodeLabel.setForeground(grayTextColor);
                teacherLabel.setForeground(textColor);
                timeLabel.setForeground(textColor);
                roomLabel.setForeground(textColor);

                subjectLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
                courseCodeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
                teacherLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
                timeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
                roomLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

                routineBox.add(subjectLabel);
                routineBox.add(courseCodeLabel);
                routineBox.add(teacherLabel);
                routineBox.add(timeLabel);
                routineBox.add(roomLabel);

                routinePanel.add(Box.createRigidArea(new Dimension(0, 20)));
                routinePanel.add(routineBox);
        }

        CardLayout cardLayout = new CardLayout();
        JPanel cardPanel = new JPanel(cardLayout);

        Color backgroundColor = new Color(28, 28, 28);
        Color textColor = new Color(253, 253, 253);
        Color grayTextColor = new Color(200, 200, 200);
        Color primary = new Color(0, 255, 127);

        Date date = new Date();

        public Routine() {
                setTitle("Academic Schedule Viewer");
                setSize(400, 620);
                setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                setLocationRelativeTo(null);

                // ----------------------------------------------
                // Home page :: Frame 1
                JPanel homePage = new JPanel();
                homePage.setBackground(backgroundColor);
                JButton viewRoutine = new JButton("View Routine");
                JButton viewCourse = new JButton("View Courses");
                JButton contactCR = new JButton("Contact CR");
                JButton login = new JButton("Admin Login");
                JButton exitButton = new JButton("Exit");

                viewRoutine.setBackground(primary);
                viewCourse.setBackground(primary);
                contactCR.setBackground(primary);
                login.setBackground(primary);
                exitButton.setBackground(Color.RED);

                homePage.setLayout(new BoxLayout(homePage, BoxLayout.Y_AXIS));
                homePage.add(Box.createVerticalGlue());
                viewRoutine.setAlignmentX(CENTER_ALIGNMENT);
                viewCourse.setAlignmentX(CENTER_ALIGNMENT);
                contactCR.setAlignmentX(CENTER_ALIGNMENT);
                login.setAlignmentX(CENTER_ALIGNMENT);
                exitButton.setAlignmentX(CENTER_ALIGNMENT);

                homePage.add(viewRoutine);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(viewCourse);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(contactCR);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(login);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(exitButton);
                homePage.add(Box.createVerticalGlue());

                // ------------------------------------------------
                // Routine page :: Frame 2

                String today = new SimpleDateFormat("EEEE").format(date).toLowerCase();
                List<Subject> todaySubjects = weeklyRoutine.getOrDefault(today, new ArrayList<>());

                JPanel routinePage = new JPanel();
                JPanel buttonPanel = new JPanel();
                JPanel headingPanel = new JPanel();
                routinePanel = new JPanel();

                routinePage.setLayout(new BoxLayout(routinePage, BoxLayout.Y_AXIS));
                buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.Y_AXIS));
                headingPanel.setLayout(new BoxLayout(headingPanel, BoxLayout.Y_AXIS));
                routinePanel.setLayout(new BoxLayout(routinePanel, BoxLayout.Y_AXIS));

                routinePage.setBackground(backgroundColor);
                routinePanel.setBackground(backgroundColor);
                headingPanel.setBackground(backgroundColor);

                routinePage.add(buttonPanel);
                routinePage.add(headingPanel);
                routinePage.add(routinePanel);

                buttonPanel.setAlignmentX(CENTER_ALIGNMENT);
                headingPanel.setAlignmentX(CENTER_ALIGNMENT);
                routinePanel.setAlignmentX(CENTER_ALIGNMENT);

                JButton backHome = new JButton("🏠");
                backHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
                backHome.setBackground(primary);
                buttonPanel.add(backHome);

                JLabel currentDay = new JLabel(new SimpleDateFormat("EEEE").format(date));
                JLabel currentDate = new JLabel(new SimpleDateFormat("MMM dd, yyyy").format(date));

                currentDay.setForeground(textColor);
                currentDate.setForeground(grayTextColor);
                currentDay.setAlignmentX(CENTER_ALIGNMENT);
                currentDate.setAlignmentX(CENTER_ALIGNMENT);

                headingPanel.add(Box.createRigidArea(new Dimension(0, 20)));
                headingPanel.add(currentDay);
                headingPanel.add(currentDate);
                headingPanel.add(Box.createRigidArea(new Dimension(0, 20)));

                for (Subject course : todaySubjects) {
                        addSubjectToRoutinePanel(course);
                }

                // ------------------------------------------------
                // Course List page :: Frame 3

                JPanel courseListPage = new JPanel();

                JButton coursebackHome = new JButton("🏠");
                coursebackHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
                coursebackHome.setBackground(primary);

                JLabel courseListLabel = new JLabel("Course List");

                courseListPage.setLayout(new BoxLayout(courseListPage, BoxLayout.Y_AXIS));
                courseListPage.setAlignmentX(CENTER_ALIGNMENT);

                coursebackHome.setAlignmentX(CENTER_ALIGNMENT);
                courseListLabel.setAlignmentX(CENTER_ALIGNMENT);

                courseListPage.setBackground(backgroundColor);
                courseListLabel.setForeground(textColor);

                courseListPage.add(coursebackHome);
                courseListPage.add(Box.createRigidArea(new Dimension(0, 20)));
                courseListPage.add(courseListLabel);
                courseListPage.add(Box.createRigidArea(new Dimension(0, 20)));

                JPanel courseListPanel = new JPanel();
                courseListPanel.setLayout(new BoxLayout(courseListPanel, BoxLayout.Y_AXIS));

                courseListPanel.setBackground(backgroundColor);
                courseListPanel.setForeground(textColor);

                JTable table = new JTable(tableModel);

                table.setBackground(backgroundColor);
                table.setForeground(textColor);
                courseListPanel.add(table.getTableHeader());
                courseListPanel.add(table);
                courseListPage.add(courseListPanel);

                // ------------------------------------------------
                // CR page :: Frame 4

                JPanel crPage = new JPanel();
                JPanel infoPanel = new JPanel();

                JLabel crLabel = new JLabel("Contact CR");
                JButton crbackHome = new JButton("🏠");
                crbackHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
                crbackHome.setBackground(primary);

                JLabel crName = new JLabel("Hrithik Dev Nath");
                JLabel tel = new JLabel("Phone: 01905078029");
                JLabel email = new JLabel("Email: hrithikdevnath0924@gmail.com");
                JLabel whatsapp = new JLabel("Whatsapp: 01905078029");

                crPage.setLayout(new BoxLayout(crPage, BoxLayout.Y_AXIS));
                infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));

                crbackHome.setAlignmentX(CENTER_ALIGNMENT);
                crLabel.setAlignmentX(CENTER_ALIGNMENT);
                crPage.setAlignmentX(CENTER_ALIGNMENT);
                infoPanel.setAlignmentX(CENTER_ALIGNMENT);
                crName.setAlignmentX(CENTER_ALIGNMENT);
                email.setAlignmentX(CENTER_ALIGNMENT);
                whatsapp.setAlignmentX(CENTER_ALIGNMENT);

                crPage.setBackground(backgroundColor);
                infoPanel.setBackground(backgroundColor);
                crLabel.setForeground(textColor);
                crPage.setForeground(textColor);
                infoPanel.setForeground(textColor);
                crName.setForeground(textColor);
                tel.setForeground(textColor);
                email.setForeground(textColor);
                whatsapp.setForeground(textColor);

                infoPanel.setBorder(
                                BorderFactory.createCompoundBorder(BorderFactory.createLineBorder(primary, 1),
                                                BorderFactory.createEmptyBorder(10, 10, 10, 10)));

                crPage.add(crbackHome);
                crPage.add(Box.createRigidArea(new Dimension(0, 20)));
                crPage.add(crLabel);
                crPage.add(Box.createRigidArea(new Dimension(0, 20)));
                crPage.add(infoPanel);
                infoPanel.add(crName);
                infoPanel.add(email);
                infoPanel.add(whatsapp);

                // ------------------------------------------------
                // Login page :: Frame 5

                JPanel LoginPage = new JPanel();

                JPanel userNamePanel = new JPanel();
                JPanel passwordPanel = new JPanel();
                JPanel actionPanel = new JPanel();

                LoginPage.setLayout(new BoxLayout(LoginPage, BoxLayout.Y_AXIS));

                userNamePanel.setLayout(new BoxLayout(userNamePanel, BoxLayout.X_AXIS));
                passwordPanel.setLayout(new BoxLayout(passwordPanel, BoxLayout.X_AXIS));
                actionPanel.setLayout(new BoxLayout(actionPanel, BoxLayout.X_AXIS));

                LoginPage.setBackground(backgroundColor);
                userNamePanel.setBackground(backgroundColor);
                passwordPanel.setBackground(backgroundColor);
                actionPanel.setBackground(backgroundColor);

                JLabel userNameLabel = new JLabel("User Name");
                JTextField userNameField = new JTextField(20);
                userNameField.setMaximumSize(new Dimension(150, 20));
                JLabel passwordLabel = new JLabel("Password");
                JPasswordField passwordField = new JPasswordField(20);
                passwordField.setMaximumSize(new Dimension(150, 20));

                JButton loginButton = new JButton("Login");
                JButton loginBackButton = new JButton("Back");
                userNameLabel.setForeground(textColor);
                passwordLabel.setForeground(textColor);

                userNameField.setBackground(backgroundColor);
                userNameField.setForeground(textColor);

                passwordField.setBackground(backgroundColor);
                passwordField.setForeground(textColor);

                loginButton.setBackground(primary);
                loginBackButton.setBackground(primary);

                userNamePanel.add(userNameLabel);
                userNamePanel.add(Box.createRigidArea(new Dimension(20, 0)));
                userNamePanel.add(userNameField);

                passwordPanel.add(passwordLabel);
                passwordPanel.add(Box.createRigidArea(new Dimension(20, 0)));
                passwordPanel.add(passwordField);

                actionPanel.add(loginButton);
                actionPanel.add(Box.createRigidArea(new Dimension(20, 0)));
                actionPanel.add(loginBackButton);

                LoginPage.add(Box.createVerticalGlue());
                LoginPage.add(userNamePanel);
                LoginPage.add(Box.createRigidArea(new Dimension(0, 20)));
                LoginPage.add(passwordPanel);
                LoginPage.add(Box.createRigidArea(new Dimension(0, 20)));
                LoginPage.add(actionPanel);
                LoginPage.add(Box.createVerticalGlue());

                loginButton.addActionListener(e -> {
                        String userName = userNameField.getText();
                        String password = new String(passwordField.getPassword());

                        if (userName.equals(u1.getUserName()) && password.equals(u1.getPassword())) {
                                cardLayout.show(cardPanel, "AdminPanelPage");
                        } else {
                                JOptionPane.showMessageDialog(null, "Invalid username or password", "Error",
                                                JOptionPane.ERROR_MESSAGE);
                        }
                });

                loginBackButton.addActionListener(e -> cardLayout.show(cardPanel, "Home"));

                // ------------------------------------------------
                // Admin panel page :: Frame 6

                JPanel AdminPanelPage = new JPanel();

                AdminPanelPage.setBackground(backgroundColor);
                JButton addRoutine = new JButton("Add a new subject");
                JButton addCourse = new JButton("Add Courses");

                JButton adminBackHome = new JButton("🏠");
                adminBackHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));

                adminBackHome.setBackground(primary);
                addRoutine.setBackground(primary);
                addCourse.setBackground(primary);

                AdminPanelPage.setLayout(new BoxLayout(AdminPanelPage, BoxLayout.Y_AXIS));
                addRoutine.setAlignmentX(CENTER_ALIGNMENT);
                addCourse.setAlignmentX(CENTER_ALIGNMENT);
                adminBackHome.setAlignmentX(CENTER_ALIGNMENT);
                AdminPanelPage.add(adminBackHome);
                AdminPanelPage.add(Box.createVerticalGlue());
                AdminPanelPage.add(addRoutine);
                AdminPanelPage.add(Box.createRigidArea(new Dimension(0, 20)));
                AdminPanelPage.add(addCourse);
                AdminPanelPage.add(Box.createVerticalGlue());

                addRoutine.addActionListener(e -> {
                        String name = JOptionPane.showInputDialog("Enter subject name");
                        String teacher = JOptionPane.showInputDialog("Enter teacher name");
                        String time = JOptionPane.showInputDialog("Enter time (e.g. 8:30 - 9:55)");
                        String roomNo = JOptionPane.showInputDialog("Enter room number");
                        String courseCode = JOptionPane.showInputDialog("Enter course code");
                        Boolean lab = JOptionPane.showConfirmDialog(null, "Is it a lab?", "Lab",
                                        JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION;

                        Subject subject = new Subject(name, teacher, time, roomNo, courseCode, lab);
                        addSubjectToRoutinePanel(subject);
                        JOptionPane.showMessageDialog(null, "Subject added successfully", "Success",
                                        JOptionPane.INFORMATION_MESSAGE);
                        cardLayout.show(cardPanel, "Home");

                });

                addCourse.addActionListener(e -> {
                        String courseTitle = JOptionPane.showInputDialog("Enter course title");
                        String instructor = JOptionPane.showInputDialog("Enter instructor name");

                        courseList.add(new HashMap<String, String>() {
                                {
                                        put("Course Title", courseTitle);
                                        put("Instructor", instructor);
                                }
                        });

                        updateTableData(courseList, tableModel);
                        JOptionPane.showMessageDialog(null, "Subject added successfully", "Success",
                                        JOptionPane.INFORMATION_MESSAGE);
                        cardLayout.show(cardPanel, "Home");
                });

                // ------------------------------------------------------
                // Handle button clicks
                viewRoutine.addActionListener(e -> cardLayout.show(cardPanel, "Routine"));
                viewCourse.addActionListener(e -> cardLayout.show(cardPanel, "Course"));
                login.addActionListener(e -> cardLayout.show(cardPanel, "Admin"));
                contactCR.addActionListener(e -> cardLayout.show(cardPanel, "CR"));
                exitButton.addActionListener(e -> System.exit(1));

                // ------------------------------------------------------
                // Add pages to cardPanel
                cardPanel.add(homePage, "Home");
                cardPanel.add(routinePage, "Routine");
                cardPanel.add(courseListPage, "Course");
                cardPanel.add(crPage, "CR");
                cardPanel.add(LoginPage, "Admin");
                cardPanel.add(AdminPanelPage, "AdminPanelPage");
                add(cardPanel);

        }

}

class Main {
        public static void main(String[] args) {
                Routine app = new Routine();
                app.setVisible(true);
        }
}

/*
 * 
 * Reference:
 * 
 * Java Swing: https://youtu.be/xn1EEozPbx0
 * 
 * App structure: https://stackoverflow.com/a/14567937
 * 
 * Java Lambda: https://stackoverflow.com/a/29441980,
 * https://www.tutorialspoint.com/how-to-implement-the-listeners-using-lambda-
 * expressions-in-java
 * 
 * Layout : https://youtu.be/JMkHA2ndook
 * 
 * Box Layout: https://www.youtube.com/watch
 * 
 * Table: https://www.geeksforgeeks.org/java-swing-jtable/
 * 
 * Data Structure: https://www.w3schools.com/java/java_arraylist.asp,
 * https://www.w3schools.com/java/java_hashmap.asp,
 * https://www.w3schools.com/java/java_howto_loop_through_arraylist.asp
 * 
 * Date format: https://www.javatpoint.com/java-simpledateformat
 * 
 */