#include "../include/pch.h"
#include "../../BLL/include/register.h"
#include "../../DAL/include/register.h"

void registerUser() {
    system("CLS");

    std::string username, email, password;

    std::cout << "Enter your username: ";
    std::cin >> username;
    while (!checkUsername(username) || userExists(username)) {
        std::cout << "Invalid or taken username. Please enter a valid username: ";
        std::cin >> username;
    }

    std::cout << "Enter your email: ";
    std::cin >> email;
    while (!checkEmail(email)) {
        std::cout << "Invalid email. Please enter a valid email: ";
        std::cin >> email;
    }

    std::cout << "Enter your password: ";
    std::cin >> password;
    while (!checkPassword(password)) {
        std::cout << "Invalid password. Please enter a valid password: ";
        std::cin >> password;
    }

    saveUser(username, email, password); 
    std::cout << "Registration successful!" << std::endl;
}
