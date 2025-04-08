#include "../include/register.h"

void registerUser() {
    system("CLS");
    char ch;
    const std::string enter = R"(Enter your password: )";
    const std::string invalid = R"(Invalid password. Please enter a valid password: )";

	std::cout << "Let's create an account!" << std::endl;
    std::cout << "Enter your username: ";
    std::cin >> credentials::username;
    
	// Check if the username is valid and not already taken
    while (!checkUsername(credentials::username) || userExists(credentials::username)) {
        std::cout << "Invalid or taken username. Please enter a valid username: ";
        std::cin >> credentials::username;
    }

    std::cout << "Enter your email: ";
    std::cin >> credentials::email;
    
	// Check if the email is valid
    while (!checkEmail(credentials::email)) {
        std::cout << "Invalid email. Please enter a valid email: ";
        std::cin >> credentials::email;
    }

    std::cout << enter;
	while ((ch = _getch()) != '\r') { // '\r' checks for Enter key  
		if (ch == '\b') { // '\b' checks for backspace
            if (!credentials::password.empty()) {
				credentials::password.pop_back(); //pop_back removes the last character
                std::cout << "\b \b";
            }
        }
            else {
                credentials::password.push_back(ch); //When the last character is removed, the push_back function adds a new '*' to the end of the string
                std::cout << "*"; 
            }
        }
    
    while (!checkPassword(credentials::password)) {
        std::cout << std::endl;
        std::cout << invalid;
		while ((ch = _getch()) != '\r') { // '\r' checks for Enter key
			if (ch == '\b') { // '\b' checks for backspace
                if (!credentials::password.empty()) {
					credentials::password.pop_back(); //pop_back removes the last character
                    std::cout << "\b \b";
                }
            }
            else {
				credentials::password.push_back(ch); //When the last character is removed, the push_back function adds a new '*' to the end of the string
                std::cout << "*";
            }
        }
    }

    saveUser(credentials::username, credentials::email, credentials::password);
    
	std::cout << std::endl;
    std::cout << "Registration successful!" << std::endl;
    std::cout << "Press any key to log in..." << std::endl;

    if(_getch() > 0) loginUser();
}
