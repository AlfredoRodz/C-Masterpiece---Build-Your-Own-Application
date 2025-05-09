#// functions.cpp

#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

std::string generatePassword(int length) {
    const std::string chars =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()_+-=[]{}|;:',.<>?";
    std::string password;
    srand(time(0));
    for (int i = 0; i < length; ++i)
        password += chars[rand() % chars.size()];
    return password;
}

std::string evaluatePassword(const std::string& password) {
    int score = 0;
    if (password.length() >= 8) score++;
    if (password.find_first_of("0123456789") != std::string::npos) score++;
    if (password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) score++;
    if (password.find_first_of("!@#$%^&*()_+-=[]{}|;:',.<>?") != std::string::npos) score++;

    if (score >= 4) return "Strong";
    if (score == 3) return "Moderate";
    return "Weak";
}

std::string encrypt(const std::string& data) {
    std::string result = data;
    for (char& c : result)
        c += 3; // Simple Caesar cipher
    return result;
}

std::string encrypt(const std::string& data, char key) {
    std::string result = data;
    for (char& c : result)
        c ^= key; // XOR encryption
    return result;
}

std::string decrypt(const std::string& data) {
    std::string result = data;
    for (char& c : result)
        c -= 3;
    return result;
}

void saveCredential(const Credential& cred) {
    std::ofstream file("vault.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error: Unable to open vault.txt for writing.\n";
        return;
    }
    file << encrypt(cred.username) << "," << encrypt(cred.password) << "\n";
    file.close();
}

std::vector<Credential> loadCredentials() {
    std::vector<Credential> creds;
    std::ifstream file("vault.txt");
    if (!file) return creds;

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string encUser, encPass;
        if (getline(ss, encUser, ',') && getline(ss, encPass)) {
            Credential c;
            c.username = decrypt(encUser);
            c.password = decrypt(encPass);
            creds.push_back(c);
        }
    }
    return creds;
}

bool login(const std::string& username, const std::string& password) {
    std::vector<Credential> creds = loadCredentials();
    for (const auto& c : creds) {
        if (c.username == username && c.password == password)
            return true;
    }
    return false;
}
