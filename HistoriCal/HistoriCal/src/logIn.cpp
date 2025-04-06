#include "../include/logIn.h"

void loginUser() {
    system("CLS");

    std::cout << "Welcome back! Log in here!" << std::endl;

    std::cout << "Enter your username: ";
    std::cin >> credentials::username;

    std::cout << "Enter your password: ";
    std::cin >> credentials::password;

    while (!authenticateUser(credentials::username, credentials::password)) {
        std::cout << "Enter your username: ";
        std::cin >> credentials::username;

        std::cout << "Enter your password: ";
        std::cin >> credentials::password;
    }
    
    if(authenticateUser(credentials::username, credentials::password))
    {
		dashboardPage();
	}
}