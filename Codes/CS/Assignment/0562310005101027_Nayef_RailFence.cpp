#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encryptRailFence(string text, int key) {
    if (key <= 1)
        return text;

    int n = text.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));

    bool down = false;
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        if (row == 0 || row == key - 1)
            down = !down;

        rail[row][col++] = text[i];

        if (down)
            row++;
        else
            row--;
    }

    string result = "";

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rail[i][j] != '\n')
                result += rail[i][j];
        }
    }

    return result;
}

string decryptRailFence(string cipher, int key) {
    if (key <= 1)
        return cipher;

    int n = cipher.length();
    vector<vector<char>> rail(key, vector<char>(n, '\n'));

    bool down;
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        if (row == 0)
            down = true;
        if (row == key - 1)
            down = false;

        rail[row][col++] = '*';

        if (down)
            row++;
        else
            row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rail[i][j] == '*' && index < n)
                rail[i][j] = cipher[index++];
        }
    }

    string result = "";
    row = 0;
    col = 0;

    for (int i = 0; i < n; i++) {
        if (row == 0)
            down = true;
        if (row == key - 1)
            down = false;

        result += rail[row][col++];

        if (down)
            row++;
        else
            row--;
    }

    return result;
}

int main() {
    string message;
    int depth;

    cout << "Enter the message: ";
    cin >> message;

    cout << "Enter the depth (number of rails): ";
    cin >> depth;

    string encrypted = encryptRailFence(message, depth);
    string decrypted = decryptRailFence(encrypted, depth);

    cout << "\nEncrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}