#include "../include/dashboard.h"

void dashboardPage()
{
	std::string menu = R"(
=============================
|[1] View historical dates! |
|---------------------------|
|[2]  Manage your account!  |
|---------------------------|
|[3]        Log Out	    |
=============================
)";
	system("CLS");
	int choice;
	std::cout << "Welcome, " << credentials::username << "!" << std::endl;
	std::cout << menu << std::endl;
	std::cin >> choice;

	switch(choice)
	{
		case 1:
			system("CLS");
			viewDates();
			break;
		case 2:
			manageProfiles();
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