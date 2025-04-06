#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "../../DAL/include/register.h"
#include "../../BLL/include/register.h"
#include "json.hpp"

bool userExists(const std::string& username);
void saveUser(const std::string& username, const std::string& email, const std::string& password);
