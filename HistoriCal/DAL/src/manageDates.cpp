#include "../include/manageDates.h"
#include "../../HistoriCal/include/historicalCalendar.h"
using json = nlohmann::json;

// Function to add an event to the linked list
void addEvent(EventNode*& head) {
    std::string date, description, country;

    std::cout << "Enter the date of the event (YYYY-MM-DD): ";
    std::cin >> date;

    std::cout << "Enter a description of the event: ";
    std::cin.ignore(); 
    std::getline(std::cin, description);

    std::cout << "Enter the country where the event occurred: ";
    std::cin >> country;

	//Creates a new event node
    EventNode* newEvent = new EventNode(date, description, country);

	//Adds the new event to the end of the linked list
    if (head == nullptr) {
        head = newEvent;
    }
    else {
        EventNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newEvent;
    }

    std::cout << "Event added successfully!" << std::endl;
}

// Function to save events to a JSON file
void saveEvents(EventNode* head) {
    std::ifstream file("../../HistoriCal/DAL/Data/myEvents.json");
    json dates;
    if (file) {
        file >> dates;
        file.close();
    }
    else {
		dates["events"] = json::array(); // Initialize as an empty array
    }

	// Add the new event to the JSON object
    EventNode* current = head;
    while (current != nullptr) {
        json event = {
            {"user", credentials::username},
            {"date", current->date},
            {"description", current->description},
            {"category2", current->country}
        };
        dates["events"].push_back(event);
        current = current->next;
    }

    std::ofstream outFile("../../HistoriCal/DAL/Data/myEvents.json");
    outFile << std::setw(4) << dates;
    outFile.close();

    std::cout << "Press Enter to continue!" << std::endl;

    if (_getch() == 13) {
        manageDates();
    }
}
