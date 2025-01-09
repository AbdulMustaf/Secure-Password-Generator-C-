#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool useUppercase, bool useLowercase, bool useNumbers, bool useSymbols) {
    string charSet = "";
    if (useUppercase) charSet += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useLowercase) charSet += "abcdefghijklmnopqrstuvwxyz";
    if (useNumbers) charSet += "0123456789";
    if (useSymbols) charSet += "!@#$%^&*()_+{}[]|;:,.<>?";

    if (charSet.empty()) {
        throw invalid_argument("At least one character set must be selected.");
    }

    string password = "";
    for (int i = 0; i < length; i++) {
        password += charSet[rand() % charSet.size()];
    }
    return password;
}

// Function to evaluate password strength
string evaluateStrength(const string& password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSymbol = true;
    }

    if (password.length() >= 12 && hasUpper && hasLower && hasDigit && hasSymbol) {
        return "Strong";
    } else if (password.length() >= 8 && (hasUpper || hasLower) && (hasDigit || hasSymbol)) {
        return "Moderate";
    } else {
        return "Weak";
    }
}

// Function to save password securely to a file
void savePassword(const string& password) {
    ofstream file("saved_passwords.txt", ios::app);
    if (file.is_open()) {
        file << password << endl;
        cout << "Password saved successfully!" << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
    file.close();
}

int main() {
    srand(time(0)); // Seed random number generator

    int length;
    char choice;
    bool useUppercase = false, useLowercase = false, useNumbers = false, useSymbols = false;

    cout << "Welcome to the Secure Password Generator!" << endl;
    cout << "Enter the desired password length (between 12 and 16): ";
    cin >> length;

    if (length < 12 || length > 16) {
        cerr << "Error: Password length must be between 12 and 16." << endl;
        return 1;
    }

    cout << "Include uppercase letters? (Y/N): ";
    cin >> choice;
    useUppercase = (tolower(choice) == 'y');

    cout << "Include lowercase letters? (Y/N): ";
    cin >> choice;
    useLowercase = (tolower(choice) == 'y');

    cout << "Include numbers? (Y/N): ";
    cin >> choice;
    useNumbers = (tolower(choice) == 'y');

    cout << "Include symbols? (Y/N): ";
    cin >> choice;
    useSymbols = (tolower(choice) == 'y');

    try {
        string password = generatePassword(length, useUppercase, useLowercase, useNumbers, useSymbols);
        cout << "\nGenerated Password: " << password << endl;

        string strength = evaluateStrength(password);
        cout << "Password Strength: " << strength << endl;

        cout << "Save this password? (Y/N): ";
        cin >> choice;
        if (tolower(choice) == 'y') {
            savePassword(password);
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
