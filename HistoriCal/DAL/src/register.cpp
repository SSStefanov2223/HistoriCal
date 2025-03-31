#include "../include/pch.h"
#include "../../DAL/include/register.h"
#include "../../BLL/include/register.h"
#include "../include/json.hpp"

using json = nlohmann::json;

bool userExists(const std::string& username) {
    std::ifstream accounts("users.json");
    if (!accounts) return false;

    json users;
    accounts >> users;
    accounts.close();

    return users.contains(username);
}

void saveUser(const std::string& username, const std::string& email, const std::string& password) {
    json users;
    std::ifstream file("users.json");

    if (file) {  
        file >> users;
        file.close();
    }

    users[username] = { 
        {"email", email},
        {"password", password}
    };  

    std::ofstream outFile("users.json");
    outFile << users.dump(4);  
    outFile.close();
}