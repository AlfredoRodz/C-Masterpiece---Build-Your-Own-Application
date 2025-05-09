// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

struct Credential {
    std::string username;
    std::string password;
};

// Password tools
std::string generatePassword(int length = 12);
std::string evaluatePassword(const std::string& password);

// Encryption tools
std::string encrypt(const std::string& data);
std::string encrypt(const std::string& data, char key); // Overloaded
std::string decrypt(const std::string& data);

// File operations
void saveCredential(const Credential& cred);
bool login(const std::string& username, const std::string& password);
std::vector<Credential> loadCredentials();

#endif
