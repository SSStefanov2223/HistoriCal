#include "../include/pch.h"
#include "../../DAL/include/logIn.h"
#include "../include/dashboard.h"

void loginUser() {
    system("CLS");

    std::string username, password;

	std::cout << "Welcome back! Log in here!" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> username;

    std::cout << "Enter your password: ";
    std::cin >> password;

    if (!authenticateUser(username, password)) {
        std::cout << "Login failed.\n";
	}
	else {
		dashboardPage(username);
	}
}