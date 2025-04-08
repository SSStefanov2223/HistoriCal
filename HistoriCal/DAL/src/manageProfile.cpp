#include "../include/manageProfile.h"
using json = nlohmann::json;

// Function to edit the user's profile
void editProfile() {
    std::ifstream inFile("../../HistoriCal/DAL/Data/users.json");

    json users;
    inFile >> users;
    inFile.close();

	// Check if the user exists
    json& user = users[credentials::username];

    std::string newUsername, newEmail, newPassword;

    std::cout << "\nEnter new username (or press Enter to keep current): ";
    std::getline(std::cin, newUsername);
    if (!newUsername.empty() && newUsername != credentials::username) {
        users.erase(credentials::username);
        users[newUsername] = user;          
        credentials::username = newUsername; 
    }

	// Prompt for new email
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    std::cout << std::endl;

    std::cout << "Enter new email (or press Enter to keep current): ";
    
	// Clear the input buffer before reading the new email
    std::getline(std::cin, newEmail);
    if (!newEmail.empty()) {
        user["email"] = newEmail;
        credentials::email = newEmail;  
    }

    std::cout << std::endl;

    std::cout << "Enter new password (or press Enter to keep current): ";

	// Clear the input buffer before reading the new password
    std::getline(std::cin, newPassword);
    if (!newPassword.empty()) {
        user["password"] = newPassword;
        credentials::password = newPassword;  
    }

    std::ofstream outFile("../../HistoriCal/DAL/Data/users.json");

    outFile << users.dump(4); 
    outFile.close();

    std::cout << "\nProfile updated successfully!" << std::endl;

    while (_getch() != 13);  

    system("CLS");
    manageProfiles(); 
}

// Function to delete the user's profile
void deleteProfile() {
    std::ifstream inFile("../../HistoriCal/DAL/Data/users.json");

    json users;
    inFile >> users;
    inFile.close();

    char confirm;
    std::cout << "Are you sure you want to delete your account? (Y/N): ";
    std::cin >> confirm;

    if (tolower(confirm) == 'y') {
        users.erase(credentials::username);

        std::ofstream outFile("../../HistoriCal/DAL/Data/users.json");

        outFile << users.dump(4);
        outFile.close();

        std::cout << "\nYour account has been deleted successfully!" << std::endl;

		// Clear the credentials
        credentials::username.clear();
        credentials::password.clear();
        credentials::email.clear();

        system("CLS");
        std::cout << "Goodbye!" << std::endl;
    }
    else {
        std::cout << "\nAccount deletion canceled." << std::endl;
        std::cout << "\nPress Enter to continue." << std::endl;
        if (_getch() == 13) {
            manageProfiles();
        }
       
    }
}