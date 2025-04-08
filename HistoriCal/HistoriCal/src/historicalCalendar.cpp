#include "../include/historicalCalendar.h"
using json = nlohmann::json;

void showDates()
{
	std::ifstream file("../../HistoriCal/DAL/Data/dates.json");

	json dates;
	file >> dates;
	file.close();

    std::string selectedYear;
    std::cout << "Enter a year to filter events: ";
    std::cin >> selectedYear;

    bool found = false;
    std::cout << "\nHistorical Events from " << selectedYear << ":\n";
    for (const auto& event : dates["events"]) {
        std::string date = event.value("date", "");
        std::string description = event.value("description", "No Description");

        if (date.substr(0, 4) == selectedYear) {

            for (size_t i = 0; i <= date.length(); i++) std::cout << "-";
            std::cout << "-------" << std::endl;
            std::cout << "|Year: " << date << "|" << std::endl;
            std::cout << "-------";
            for (size_t i = 0; i <= date.length(); i++) std::cout << "-";

            std::cout << std::endl;
            std::cout << "Description: " << description << std::endl;
            std::cout << "=======================================================================================================================" << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No events found for year: " << selectedYear << std::endl;
    }
    std::cout << "Press Enter to continue!" << std::endl;
    if (_getch() == 13) {
        system("CLS");
        viewDates();
    }
}

void showByCountry()
{
	system("CLS");
    std::ifstream file("../../HistoriCal/DAL/Data/dates.json");

    json dates;
    file >> dates;
    file.close();

    std::string selectedCountry;
    std::string selectedYear;

    std::cout << "Enter a country to filter events: ";
    std::cin >> selectedCountry;

    std::cout << "Enter the year to filter events: ";
    std::cin >> selectedYear;

    bool found = false;
    std::cout << "\nHistorical Events in " << selectedCountry << " for the year " << selectedYear << ":\n";

    for (const auto& event : dates["events"]) {
        std::string country = event.value("category2", "");
        std::string description = event.value("description", "No Description");
        std::string date = event.value("date", "Unknown Date");

        std::string year = date.substr(0, 4);

        if (country == selectedCountry && year == selectedYear) {

			for (size_t i = 0; i <= date.length(); i++) std::cout << "-";
			std::cout << "-------" << std::endl;
            std::cout << "|Year: " << date << "|" << std::endl;
            std::cout << "-------";
            for (size_t i = 0; i <= date.length(); i++) std::cout << "-";
			std::cout << std::endl;
            std::cout << "Description: " << description << std::endl;
            std::cout << "=======================================================================================================================" << std::endl;
            found = true;
        }
    }
	std::cout << "Press Enter to continue!" << std::endl;
	if (_getch() == 13) {
		system("CLS");
		viewDates();
	}

    if (!found) {
        std::cout << "No events found for country: " << selectedCountry << " in the year: " << selectedYear << std::endl;
    }
}

void displayEvents() 
{
    std::ifstream file("../../HistoriCal/DAL/Data/myEvents.json");

    json dates;
    file >> dates;
    file.close();

    if (dates["events"].empty()) {
        std::cout << "No events in the file!" << std::endl;
        return;
    }

    bool found = false;
    for (const auto& event : dates["events"]) {
        if (event.value("user", "") == credentials::username) {
            std::string date = event.value("date", "Unknown Date");
            std::string description = event.value("description", "No Description");
            std::string country = event.value("category2", "Unknown Country");

            for (size_t i = 0; i <= date.length(); i++) std::cout << "-";
            std::cout << "-------" << std::endl;
            std::cout << "|Date: " << date << "|" << std::endl;
            std::cout << "-------";
            for (size_t i = 0; i <= date.length(); i++) std::cout << "-";
            std::cout << std::endl;

            std::cout << "Description: " << description << std::endl;
            std::cout << "------------------------" << std::endl;
            std::cout << "Country: " << country << std::endl;
			std::cout << "========================" << std::endl;
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No events found!" << std::endl;
    }

    std::cout << "Press Enter to continue!" << std::endl;
    if (_getch() == 13) {
        system("CLS");
        manageDates();
    }
}

void manageDates()
{
    std::string menu = R"(
==================
|[1]  Add Event  |
|----------------|
|[2] View Events |
|----------------|
|[3]   Go Back   |
==================
)";
    system("CLS");
    EventNode* head = nullptr;  
    int choice;
	std::cout << "Welcome to the Event Management Page!" << std::endl;
	std::cout << menu << std::endl;
    do {
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            addEvent(head);
            saveEvents(head);
            viewDates();
            break;
        case 2:
            system("CLS");
            displayEvents();
            viewDates();
            break;
        case 3:
            system("CLS");
            viewDates();
            break;
        default:
			std::cout << "Invalid choice. Please try again: ";
			break;
        }
	} while (choice < 1 or choice > 3);
    std::cout << "Pess Enter to continue!" << std::endl;
    if (_getch() == 13) {
        system("CLS");
        viewDates();
    }
}
