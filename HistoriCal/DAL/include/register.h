#pragma once
#include "pch.h"

bool userExists(const std::string& username);
void saveUser(const std::string& username, const std::string& email, const std::string& password);
