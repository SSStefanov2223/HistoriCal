#include "../include/register.h"

void registerUser() {
    system("CLS");
    char ch;
    const std::string enter = R"(Enter your password: )";
    const std::string invalid = R"(Invalid password. Please enter a valid password: )";

	std::cout << "Let's create an account!" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> credentials::username;
    
    while (!checkUsername(credentials::username) || userExists(credentials::username)) {
        std::cout << "Invalid or taken username. Please enter a valid username: ";
        std::cin >> credentials::username;
    }

    std::cout << "Enter your email: ";
    std::cin >> credentials::email;
    
    while (!checkEmail(credentials::email)) {
        std::cout << "Invalid email. Please enter a valid email: ";
        std::cin >> credentials::email;
    }

    std::cout << enter;
    while ((ch = _getch()) != '\r') {  
        if (ch == '\b') { 
            if (!credentials::password.empty()) {
                credentials::password.pop_back();
                std::cout << "\b \b";
            }
        }
            else {
                credentials::password.push_back(ch);
                std::cout << "*"; 
            }
        }
    
    while (!checkPassword(credentials::password)) {
        std::cout << std::endl;
        std::cout << invalid;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {
                if (!credentials::password.empty()) {
                    credentials::password.pop_back();
                    std::cout << "\b \b";
                }
            }
            else {
                credentials::password.push_back(ch);
                std::cout << "*";
            }
        }
    }

    saveUser(credentials::username, credentials::email, credentials::password);
    
    std::cout << "Registration successful!" << std::endl;
    std::cout << "Press any key to log in..." << std::endl;

    if(_getch() > 0) loginUser();
}
