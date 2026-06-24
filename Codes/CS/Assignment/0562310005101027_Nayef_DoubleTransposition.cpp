#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string removeSpaces(string text) {
    string result = "";
    for (char c : text) {
        if (c != ' ')
            result += c;
    }
    return result;
}

string padText(string text, int cols) {
    while (text.length() % cols != 0)
        text += 'X';
    return text;
}

string encrypt(string text, string key) {
    int cols = key.length();
    text = padText(text, cols);

    int rows = text.length() / cols;

    vector<vector<char>> matrix(rows, vector<char>(cols));

    int index = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = text[index++];

    string cipher = "";

    for (char ch : key) {
        int col = ch - '1';
        for (int i = 0; i < rows; i++)
            cipher += matrix[i][col];
    }

    return cipher;
}

string decrypt(string cipher, string key) {
    int cols = key.length();
    int rows = cipher.length() / cols;

    vector<vector<char>> matrix(rows, vector<char>(cols));

    int index = 0;

    for (char ch : key) {
        int col = ch - '1';
        for (int i = 0; i < rows; i++)
            matrix[i][col] = cipher[index++];
    }

    string text = "";

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            text += matrix[i][j];

    return text;
}

int main() {
    string message, key1, key2;

    cout << "Enter the message: ";
    getline(cin, message);

    message = removeSpaces(message);

    cout << "Enter Key 1: ";
    cin >> key1;

    cout << "Enter Key 2: ";
    cin >> key2;

    string cipher1 = encrypt(message, key1);
    string cipher2 = encrypt(cipher1, key2);

    cout << "\nIntermediate Cipher 1: " << cipher1 << endl;
    cout << "Final Encrypted Message: " << cipher2 << endl;

    string temp = decrypt(cipher2, key2);
    string original = decrypt(temp, key1);

    cout << "Decrypted Message: " << original << endl;

    return 0;
}