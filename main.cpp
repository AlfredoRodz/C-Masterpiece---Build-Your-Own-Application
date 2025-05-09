// main.cpp

#include <iostream>
#include "functions.h"

void showMenu() {
    std::cout << "\n--- SecureSafe Menu ---\n";
    std::cout << "1. Generate Password\n";
    std::cout << "2. Evaluate Password\n";
    std::cout << "3. Register (Save Credential)\n";
    std::cout << "4. Login\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    std::string username, password;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int len;
                std::cout << "Enter desired password length: ";
                std::cin >> len;
                std::string pwd = generatePassword(len);
                std::cout << "Generated Password: " << pwd << "\n";
                break;
            }
            case 2: {
                std::cout << "Enter password to evaluate: ";
                std::cin >> password;
                std::cout << "Strength: " << evaluatePassword(password) << "\n";
                break;
            }
            case 3: {
                std::cout << "Create Username: ";
                std::cin >> username;
                std::cout << "Create Password: ";
                std::cin >> password;
                Credential cred = { username, password };
                saveCredential(cred);
                std::cout << "Credential saved successfully.\n";
                break;
            }
            case 4: {
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
                if (login(username, password)) {
                    std::cout << "Login successful.\n";
                } else {
                    std::cout << "Login failed. Invalid credentials.\n";
                }
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
