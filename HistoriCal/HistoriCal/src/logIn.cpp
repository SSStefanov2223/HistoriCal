#include "../include/logIn.h"

void loginUser() {
    system("CLS");
    char ch;
    const std::string enter = R"(Enter your password: )";
    std::cout << "Welcome back! Log in here!" << std::endl;

    std::cout << "Enter your username: ";
    std::cin >> credentials::username;

    std::cout << enter;
    credentials::password.clear(); 
    
	// Use _getch() to read the password without echoing it and '\r' to check for Enter key
    while ((ch = _getch()) != '\r') {
		if (ch == '\b') { // '\b' checks for backspace
            if (!credentials::password.empty()) {
				credentials::password.pop_back(); //pop_back removes the last character
				std::cout << "\b \b"; 
            }
        }
        else {
			//When the last character is removed, the push_back function adds a new '*' to the end of the string
            credentials::password.push_back(ch);
            std::cout << "*";
        }
    }

    std::cout << std::endl;

	//checks if the user is authenticated
    while (!authenticateUser(credentials::username, credentials::password)) {

        std::cout << "Enter your username: ";
        std::cin >> credentials::username;

        std::cout << enter;
        credentials::password.clear();
        // Use _getch() to read the password without echoing it and '\r' to check for Enter key
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') {// '\b' checks for backspace
                if (!credentials::password.empty()) {
                    credentials::password.pop_back();//pop_back removes the last character
                    std::cout << "\b \b";
                }
            }
            else {
                //When the last character is removed, the push_back function adds a new '*' to the end of the string
                credentials::password.push_back(ch);
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    dashboardPage();
}