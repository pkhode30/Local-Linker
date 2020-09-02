#pragma once

#include <string>
#include "School.h"

using namespace std;

class Data
{
private:
	string userID;
	string name;
	string department_name;
	int year_of_passing;
	int graph_id;
	School* school_adr;
	//LL of Hobbies
	string password;
public:
	explicit Data(const string& user, const string& pass);

	void set_name(const string& name);

	void set_department(const string& department);

	void set_passing_year(const int& year);

	void set_graph_id(const int& id);

	void set_password(const string& pass);

	void set_school(School* adr);

	School* get_school_adr() const;

	string get_password() const;

	string get_name() const;

	string get_userID() const;

	string get_department() const;

	int get_year_of_passing() const;
};
