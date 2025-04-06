#include "../include/manageProfile.h"
using json = nlohmann::json;

void editProfile() {
    std::ifstream inFile("users.json");
    if (!inFile) {
        std::cerr << "Error opening users.json file!" << std::endl;
        return;
    }

    json users;
    inFile >> users;
    inFile.close();

    if (!users.contains(credentials::username)) {
        std::cerr << "User not found!" << std::endl;
        return;
    }

    json& user = users[credentials::username];

    std::string newUsername, newEmail, newPassword;

    std::cout << "\nEnter new username (or press Enter to keep current): ";
    std::getline(std::cin, newUsername);
    if (!newUsername.empty() && newUsername != credentials::username) {
        users.erase(credentials::username);  // Remove old username
        users[newUsername] = user;           // Add new username with the same data
        credentials::username = newUsername; // Update global username
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clean the input buffer

    std::cout << std::endl;

    // Get new email if provided
    std::cout << "Enter new email (or press Enter to keep current): ";
    std::getline(std::cin, newEmail);
    if (!newEmail.empty()) {
        user["email"] = newEmail;
        credentials::email = newEmail;  // Update global email
    }

    std::cout << std::endl;

    // Get new password if provided
    std::cout << "Enter new password (or press Enter to keep current): ";
    std::getline(std::cin, newPassword);
    if (!newPassword.empty()) {
        user["password"] = newPassword;
        credentials::password = newPassword;  // Update global password
    }

    // Save updated data to the JSON file
    std::ofstream outFile("users.json");
    if (!outFile) {
        std::cerr << "Error opening users.json file for writing!" << std::endl;
        return;
    }

    outFile << users.dump(4);  // Pretty print with indentation of 4 spaces
    outFile.close();

    std::cout << "\nProfile updated successfully!" << std::endl;

    // Wait for the user to press Enter to return
    while (_getch() != 13);  // Wait for Enter key

    system("CLS");
    manageProfiles();  // Or any function to return to profile management
}

void deleteProfile() {
    std::ifstream inFile("users.json");
    if (!inFile) {
        std::cerr << "Error opening users.json file!" << std::endl;
        return;
    }

    json users;
    inFile >> users;
    inFile.close();

    if (!users.contains(credentials::username)) {
        std::cerr << "User not found!" << std::endl;
        return;
    }

    char confirm;
    std::cout << "Are you sure you want to delete your account? (Y/N): ";
    std::cin >> confirm;

    if (tolower(confirm) == 'Y') {
        users.erase(credentials::username);

        std::ofstream outFile("users.json");
        if (!outFile) {
            std::cerr << "Error opening users.json file for writing!" << std::endl;
            return;
        }

        outFile << users.dump(4);
        outFile.close();

        std::cout << "\nYour account has been deleted successfully!" << std::endl;

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