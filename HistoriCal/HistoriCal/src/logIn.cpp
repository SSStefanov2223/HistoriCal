#include "../include/logIn.h"

void loginUser() {
    system("CLS");
    char ch;
    const std::string enter = R"(Enter your password: )";
    std::cout << "Welcome back! Log in here!" << std::endl;

    std::cout << "Enter your username: ";
    std::cin >> credentials::username;

    std::cout << enter;
    credentials::password.clear();  
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

    std::cout << std::endl;

    while (!authenticateUser(credentials::username, credentials::password)) {

        std::cout << "Enter your username: ";
        std::cin >> credentials::username;

        std::cout << enter;
        credentials::password.clear(); 
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
        std::cout << std::endl;
    }

    dashboardPage();
}