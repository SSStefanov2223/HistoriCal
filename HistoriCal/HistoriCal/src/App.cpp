#include "../include/pch.h"
#include "../include/register.h"
#include "../include/logIn.h"

void App() {
	char choice;
	
	std::cout << "Welcome to HistoriCal! Would you like to register or login? (R/L): ";
	std::cin >> choice;

	if (tolower(choice) == 'r') registerUser();
	if (tolower(choice) == 'l') loginUser();
}