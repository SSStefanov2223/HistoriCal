#include "../include/pch.h"
#include "../../DAL/include/logIn.h"

void loginUser() {
    system("CLS");

    std::string username, password;

    std::cout << "Enter your username: ";
    std::cin >> username;

    std::cout << "Enter your password: ";
    std::cin >> password;

    if (!authenticateUser(username, password)) {
        std::cout << "Login failed.\n";
    }
}