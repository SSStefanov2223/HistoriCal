#pragma once

#include "pch.h"
#include "json.hpp"


struct EventNode {
    std::string date;
    std::string description;
    std::string country;
    EventNode* next;

    EventNode(std::string date, std::string description, std::string country)
        : date(date), description(description), country(country), next(nullptr) {
    }
};

void addEventToList(EventNode*& head);
void saveEventsToNewJson(EventNode* head);
