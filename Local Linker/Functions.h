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
		cout << "Enter name of your current School/College: ";
		string s_name; cin >> s_name;
		school_address->set_name(s_name);
		cout << "Enter start and end year separated by space(in YYYY format): ";
		int s, e; cin >> s >> e;
		school_address->set_start_year(s);
		school_address->set_end_year(e);
		data_address->set_graph_id(slot);
		data_address->set_school(school_address);
		cout << "**To add further details please log in!" << endl;
		graph.register_userID(username, slot);
		graph.map_user_data(username, data_address);
	}
}

inline Data* user_login(Graph& graph)
{
	cout << "\nEnter your username: ";
	string user; cin >> user;
	while(graph.is_unique(user))
	{
		cout << "\nGiven username does not exist! Please try again" << endl;
		cout << "Enter your username: ";
		cin >> user;
	}
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
			cout << "\nEnter the correct password! "<< max_try << " Attempts left" << endl;
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
	cout << "Schools: " << endl;
	user->print_schools();
	//HOBBIES
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

inline void update_user_data(Data* user)
{
	bool repeat = true, editSchool;
	int choice, n_graduation_year, school_num, count, s, e;
	string n_name, n_password, n_department, n_userID, s_name;
	while(repeat)
	{
		cout << "\t\t\t\t\t\t\t\t\t\t\t\tCurrent User-" << user->get_userID() << endl;
		cout << "Select from following options to update?" << endl;
		cout << "1-->Name" << endl;
		cout << "2-->Password" << endl;
		cout << "3-->Department" << endl;
		cout << "4-->Year of passing" << endl;
		cout << "5-->Previous Schools" << endl;
		cout << "6-->Hobbies" << endl;			//TODO:add/delete/exit
		cout << "7-->Exit" << endl;
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
			editSchool = true;
			while(editSchool)
			{
				user->print_schools();
				cout << "\nSelect operation from the following: " << endl;
				cout << "1-->Add" << endl;
				cout << "2-->Delete" << endl;
				cout << "3-->Exit" << endl;
				cout << "\nEnter your choice: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Enter the name of the School/College: ";
					cin >> s_name;
					cout << "Enter the start and end year separated by space(in YYYY format): ";
					cin >> s >> e;
					user->add_new_school(s_name, s, e);
					break;
				case 2:
					cout << "Enter the school no. to delete: ";
					cin >> count;
					user->delete_school(count);
					break;
				case 3:
					editSchool = false;
					break;
				default:
					std::cout << "\n###~Please enter correct choice~###" << std::endl;
					break;
				}
			}
			break;
		case 6:
			//hobbies
			break;
		case 7:
			repeat = false;
			break;
		default:
			std::cout << "\n###~Please enter correct choice~###" << std::endl;
			break;
		}
	}
}
