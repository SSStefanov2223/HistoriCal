#include "../include/viewDates.h"
#include "../include/historicalCalendar.h"

void viewDates()
{
	int subChoice;
	std::cout << "1. Show specific historical events by years" << std::endl;
	std::cout << "2. Show historical events from specific country and date" << std::endl;
	std::cout << "3. Manage your dates" << std::endl;
	std::cin >> subChoice;

	switch (subChoice)
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
	}
}