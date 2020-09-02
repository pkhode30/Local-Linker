#include<iostream>

#include"Functions.h"

using namespace std;

int main()
{
	const int users = 100;
	int choice;
	Graph graph = Graph(users);
	Data* user;
	string crt_user = "Guest";
	bool repeat = true, login_ok = false;
	cout << "\t\t\t\t\t\t~~~~~Local Linker~~~~~" << endl;
																													//Interface Start
	while (repeat) 
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCurrent User-" << crt_user << endl;
		cout << "Select one option below:" << endl;
		cout << "1-->Sign up (for new users)" << endl;
		cout << "2-->Log in" << endl;
		cout << "3-->Admin Login" << endl;
		cout << "4-->Quit" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			create_new_user(graph);
			cout << "\n###~New user created~###" << endl;
			break;
		case 2:
			user = user_login(graph);
			if(user)
			{
				login_ok = true;
																									//Interface 1.1 :- (After Login)
				while (login_ok)
				{
					cout << "\t\t\t\t\t\t\t\t\t\t\t\tCurrent User-" << user->get_userID() << endl;
					cout << "Select one option below:" << endl;
					cout << "1-->Your Profile" << endl;
					cout << "2-->Update Info" << endl;
					cout << "3-->Search" << endl;
					cout << "4-->Add connection" << endl;
					cout << "5-->Suggestions" << endl;
					cout << "6-->Delete Account" << endl;
					cout << "7-->Log out" << endl;
					cout << "\nEnter your choice: ";
					cin >> choice;
					switch (choice) {
					case 1:
						print_user_data(user);
						break;
					case 2:
						update_user_data(user);
						break;
					case 3:

						break;
					case 4:

						break;
					case 5:

						break;
					case 6:

						break;
					case 7:
						user = nullptr;
						login_ok = false;
						break;
					default:
						std::cout << "\n###~Please enter correct choice~###" << std::endl;
						break;
					}
				}
			}
			else
			{
				cout << "\nUnable to login!!" << endl;
			}
		case 3:

			break;
		case 4:
			repeat = false;
			break;
		default:
			std::cout << "\nPlease enter correct choice" << endl;
			break;
		}
	}

	return 0;
}
