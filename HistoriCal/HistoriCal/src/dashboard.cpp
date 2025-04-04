#include "../include/App.h"
#include "../../DAL/include/logIn.h"
#include "../include/historicalCalendar.h"
#include "../include/viewDates.h"

void dashboardPage(const std::string& username)
{
	system("CLS");
	int choice;
	std::cout << "Welcome, " << username << "!" << std::endl;
	std::cout << "1. View historical dates!" << std::endl;
	std::cout << "2. Manage your account!" << std::endl;
	std::cout << "3. Log Out" << std::endl;
	
	std::cin >> choice;

	switch(choice)
	{
			case 1:
				system("CLS");
				viewDates();
				break;
			case 2:
				std::cout << "You have selected to manage your account!" << std::endl;
				break;
			case 3:
				system("CLS");
				App();
				break;
			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
				break;
	}
}