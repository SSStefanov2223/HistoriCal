#include "../include/manageProfile.h"

void viewProfile() {
	system("CLS");
	std::cout << "====== Your Profile ======" << std::endl;
	std::cout << "|Username: " << credentials::username << std::endl;
	std::cout << "|Email:    " << credentials::email << std::endl;
	std::cout << "|Password: " << credentials::password << std::endl;
	std::cout << "==========================" << std::endl;

	std::cout << "\nPress Enter to go back!" << std::endl;
	if (_getch() == 13) manageProfiles();
}

void manageProfiles()
{
	std::string menu = R"(
=========================
|[1]  View your profile |
|-----------------------|
|[2]  Edit your profile |
|-----------------------|
|[3] Delete your profile|
|-----------------------|
|[4]      Go Back	|
=========================
)";
	system("CLS");
	int choice;
	std::cout << "Welcome to the Profile Management Page!" << std::endl;
	std::cout << menu << std::endl;
	do {
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			system("CLS");
			viewProfile();
			break;
		case 2:
			system("CLS");
			editProfile();
			break;
		case 3:
			system("CLS");
			deleteProfile();
			break;
		case 4:
			system("CLS");
			dashboardPage();
			break;
		default:
				std::cout << "Invalid choice. Please try again: ";
				break;
		}
	} while (choice < 1 or choice > 4);
}