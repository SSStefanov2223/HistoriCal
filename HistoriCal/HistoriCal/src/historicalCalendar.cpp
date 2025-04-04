#include "../include/historicalCalendar.h"
#include "../../DAL/include/manageDates.h"
#include "../include/viewDates.h"
using json = nlohmann::json;

void showDates()
{
	std::ifstream file("dates.json");

	if (!file) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

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
            std::cout << "Year: " << date << std::endl;
            std::cout << "Description: " << description << std::endl;
            std::cout << "---------------------------" << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No events found for year: " << selectedYear << std::endl;
    }
}

void showByCountry()
{
    std::ifstream file("dates.json");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

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
            std::cout << "Date: " << date << std::endl;
            std::cout << "Description: " << description << std::endl;
            std::cout << "---------------------------" << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No events found for country: " << selectedCountry << " in the year: " << selectedYear << std::endl;
    }
}

void displayEventsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    json dates;
    file >> dates;
    file.close();

    if (dates["events"].empty()) {
        std::cout << "No events in the file!" << std::endl;
        return;
    }

    std::cout << "\nEvents from " << filename << ":\n";
    for (const auto& event : dates["events"]) {
        std::string date = event.value("date", "Unknown Date");
        std::string description = event.value("description", "No Description");
        std::string country = event.value("category2", "Unknown Country");

        std::cout << "Date: " << date << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Country: " << country << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << std::endl;
    }
}

void manageDates()
{
    EventNode* head = nullptr;  
    int choice;

    std::cout << "1. Add Event\n";
    std::cout << "2. View Events\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
			system("CLS");
            addEventToList(head);
            saveEventsToNewJson(head);
            break;
        case 2:
            system("CLS");
            displayEventsFromFile("myEvents.json");
            break;
        case 3:
            system("CLS");
            viewDates();
            break;
    default:
        break;
    }
}
