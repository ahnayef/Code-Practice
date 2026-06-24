#include <iostream>
#include <string>

using namespace std;

string caesarCipher(string text, int shift) {
    string result = "";

    shift = shift % 26;
    if (shift < 0)
        shift += 26;

    for (char ch : text) {
        if (ch >= 'A' && ch <= 'Z') {
            result += char((ch - 'A' + shift) % 26 + 'A');
        }
        else if (ch >= 'a' && ch <= 'z') {
            result += char((ch - 'a' + shift) % 26 + 'a');
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string message;
    int shift;

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the shift value: ";
    cin >> shift;

    string encrypted = caesarCipher(message, shift);

    string decrypted = caesarCipher(encrypted, -shift);

    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}