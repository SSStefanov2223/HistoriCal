#include "../include/App.h"

void App() {
	char choice;
	std::string registerText = "[R] Register / [L] Log In";
	const int consoleWidth = 105;
	int registerTextSpace = (consoleWidth - registerText.length()) / 2; //Adds spaces to the left of the text
	std::string choiceText(registerTextSpace, ' ');

	//Const char* logo = R"( is used to create a raw string literal
	const char* logo = R"(
 __          __  _                            _           _    _ _     _             _  _____      _ _ 
 \ \        / / | |                          | |         | |  | (_)   | |           (_)/ ____|    | | |
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___    | |__| |_ ___| |_ ___  _ __ _| |     __ _| | |
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \   |  __  | / __| __/ _ \| '__| | |    / _` | | |
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |  | |  | | \__ \ || (_) | |  | | |___| (_| | |_| 
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___( ) |_|  |_|_|___/\__\___/|_|  |_|\_____\__,_|_(_)
                                                     |/                                                
    )";
	std::cout << logo << std::endl;
	std::cout << choiceText << registerText << std::endl;
	std::cin >> choice;

	if (tolower(choice) == 'r') registerUser();
	if (tolower(choice) == 'l') loginUser();
}