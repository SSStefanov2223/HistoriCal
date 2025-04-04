#include "../include/pch.h"
#include "../../DAL/include/logIn.h"

void dashboardPage(const std::string& username)
{
	system("CLS");
	std::cout << "Welcome, " << username << "!" << std::endl;
	std::cout << "This is your dashboard." << std::endl;
	std::cout << "Here you can view your historical data." << std::endl;
	std::cout << "Press any key to exit the dashboard." << std::endl;
}