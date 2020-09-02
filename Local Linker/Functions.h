#pragma once

#include "Graph.h"
#include "Data.h"
#include "School.h"

inline void create_new_user(Graph& graph){
	int slot = _MAX_INT_DIG;
	for(int i=0; i<graph.get_graph_size(); i++)
	{
		if(graph.is_slot_empty(i))
		{
			slot = i;
			break;
		}
	}
	if(slot==_MAX_INT_DIG)
	{
		cout << "DATABASE FULL!!!" << endl;
	}
	else
	{
		cout << "\nEnter username for your account: ";
		string username; cin >> username;
		while(!graph.is_unique(username))
		{
			cout << "username already in use.\nPlease use different username: ";
			cin >> username;
		}
		cout << "Enter the password for your account: ";
		string password; cin >> password;
		Data* data_address = new Data(username,password);
		School* school_address = new School();
		data_address->set_graph_id(slot);
		data_address->set_school(school_address);
		graph.register_userID(username, slot);
		graph.map_user_data(username, data_address);
		cout << "To add further details please log in!" << endl;
	}
}

inline Data* user_login(Graph& graph)
{
	cout << "\nEnter your username: ";
	string user; cin >> user;
	cout << "Enter the password: ";
	string pass; cin >> pass;
	Data* login = graph.login(user, pass);
	if(login)
	{
		cout << "\nLogged in Successfully!" << endl;
	}
	else
	{
		int max_try = 4;
		while (max_try--)
		{
			cout << "\nEnter the correct combination! "<< max_try << " Attempts left" << endl;
			cout << "Enter your username: ";
			cin >> user;
			cout << "Enter the password: ";
			cin >> pass;
			login = graph.login(user, pass);
			if (login)
			{
				cout << "\nLogged in Successfully!" << endl;
				break;
			}
		}
	}
	
	return login;
}

inline void print_user_data(Data* user)
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Name: " << user->get_name() << endl;
	cout << "Username: " << user->get_userID() << endl;
	cout << "Department: " << user->get_department() << endl;
	cout << "Year of passing: " << user->get_year_of_passing() << endl;
	//SCHOOLS
	//HOBBIES
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

inline void update_user_data(Data* user)
{
	bool repeat = true;
	int choice, n_graduation_year;
	string n_name, n_password, n_department, n_userID;
	while(repeat)
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCurrent User-" << user->get_userID() << endl;
		cout << "Select from following options to update?" << endl;
		cout << "1-->Name" << endl;
		cout << "2-->Password" << endl;
		cout << "3-->Department" << endl;
		cout << "4-->Year of passing" << endl;
		cout << "5-->Previous Schools" << endl;
		cout << "6-->Hobbies" << endl;
		cout << "7-->Exit" << endl;
		//cout << "8-->userID" << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice){
		case 1:
			cout << "Enter your Name: ";
			cin >> n_name;
			user->set_name(n_name);
			break;
		case 2:
			cout << "Enter new Password: ";
			cin >> n_password;
			user->set_password(n_password);
			break;
		case 3:
			cout << "Enter name of your department: ";
			cin >> n_department;
			user->set_department(n_department);
			break;
		case 4:
			cout << "Enter your Graduation Year: ";
			cin >> n_graduation_year;
			user->set_passing_year(n_graduation_year);
			break;
		case 5:
			//school
			break;
		case 6:
			//hobbies
			break;
		case 7:
			repeat = false;
			break;
		// case 8:
		// 	cout << "Enter new username: ";
		// 	cin >> n_userID;
		// 	//complete the function
		// 	break;
		default:
			std::cout << "\n###~Please enter correct choice~###" << std::endl;
			break;
		}
	}
}