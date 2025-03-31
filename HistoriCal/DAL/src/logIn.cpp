#include "../include/pch.h"
#include "../include/json.hpp"
using json = nlohmann::json;

bool authenticateUser(const std::string& username, const std::string& password) {
    std::ifstream file("users.json");
    if (!file) {
        std::cout << "No user database found. Please register first.\n";
        return false;
    }

    json users;
    file >> users;
    file.close();

    if (!users.contains(username)) {
        std::cout << "Username not found.\n";
        return false;
    }

    if (users[username]["password"] == password) {
        std::cout << "Login successful! Welcome, " << username << "!\n";
        return true;
    }
    else {
        std::cout << "Incorrect password. Please try again.\n";
        return false;
    }
}
