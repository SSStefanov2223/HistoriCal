#include "../include/logIn.h"

using json = nlohmann::json;

// Function to authenticate a user by checking the username and password against a JSON file
bool authenticateUser(const std::string& username, const std::string& password) {
    std::ifstream file("../../HistoriCal/DAL/Data/users.json");

	// Check if the file opened successfully
    json users;
    file >> users;
    file.close();

	// Check if the username exists in the JSON file
    if (users.contains(username)) {
        if (users[username]["password"] == password) {
            credentials::username = username;
            credentials::password = password;
            credentials::email = users[username]["email"];  
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