#include "../include/logIn.h"

using json = nlohmann::json;

bool authenticateUser(const std::string& username, const std::string& password) {
    std::ifstream file("users.json");

    json users;
    file >> users;
    file.close();

    if (users.contains(username)) {
        if (users[username]["password"] == password) {
            credentials::username = username;
            credentials::password = password;
            credentials::email = users[username]["email"];  

            std::cout << "Login successful! Welcome, " << username << "!\n";
            return true;
        }
        else {
            std::cout << "Incorrect password. Please try again.\n";
            return false;
        }
    }
    else {
        std::cout << "Username not found.\n";
        return false;
    }
}