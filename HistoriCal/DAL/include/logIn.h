#pragma once
#include "pch.h"
#include "../../BLL/include/credentials.h"
#include "json.hpp"

bool authenticateUser(const std::string& username, const std::string& password);
