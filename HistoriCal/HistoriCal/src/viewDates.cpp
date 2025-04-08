#include "../include/viewDates.h"

void viewDates()
{
	int choice;
	std::string menu = R"(
  Learn about historical events and create your own ones!
===========================================================
|[1]      Show specific historical events by years        |
|---------------------------------------------------------|
|[2] Show historical events from specific country and date|
|---------------------------------------------------------|
|[3]		     Manage your dates			  |
|---------------------------------------------------------|
|[4]			  Go Back			  |
===========================================================
)";
	std::cout << menu << std::endl;
	do {
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			showDates();
			break;
		case 2:
			system("CLS");
			showByCountry();
			break;
		case 3:
			system("CLS");
			manageDates();
			break;
		case 4:
			system("CLS");
			dashboardPage();
			break;
		default:
			std::cout << "Invalid choice. Please try again: ";
			break;
		}
	} while (choice < 1 or choice > 4);
}