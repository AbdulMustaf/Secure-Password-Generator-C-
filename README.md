# Secure Password Generator

## Overview
The **Secure Password Generator** is a C++ program designed to create strong and customizable passwords. The program allows users to specify the password length and choose character sets to include, such as uppercase letters, lowercase letters, numbers, and symbols. Additionally, it evaluates the generated password's strength and provides an option to securely save the password to a file.

---

## Features

1. **Customizable Password Generation**:
   - Choose the desired length (between 12 and 16 characters).
   - Include or exclude uppercase letters, lowercase letters, numbers, and symbols.

2. **Password Strength Evaluation**:
   - Evaluates the strength of the password as **Strong**, **Moderate**, or **Weak** based on length and character diversity.

3. **Save Password Securely**:
   - Allows users to save the generated password to a file named `saved_passwords.txt`.

4. **Error Handling**:
   - Ensures proper input validation for password length and character set selection.

---

## How to Use

### Prerequisites:
- A C++ compiler (e.g., `g++`).

### Steps:
1. Clone the repository or copy the source code into a file named `SecurePasswordGenerator.cpp`.
2. Compile the program:
   ```bash
   g++ -o SecurePasswordGenerator SecurePasswordGenerator.cpp
