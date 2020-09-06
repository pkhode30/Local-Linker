#pragma once

#include <string>
#include <vector>
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
	vector<string> Hobby;
	School* school_adr;
	string password;
public:
	explicit Data(const string& user, const string& pass);

	string get_userID() const;

	void set_name(const string& name);

	string get_name() const;

	void set_department(const string& department);

	string get_department() const;

	void set_passing_year(const int& year);

	int get_year_of_passing() const;

	void set_graph_id(const int& id);

	int get_graph_id() const;

	void set_password(const string& pass);

	string get_password() const;

	void add_hobby(const string& hobby);

	void delete_hobby(const string& hobby);

	void print_hobbies();

	void set_school(School* adr);

	School* get_school_adr() const;

	void add_new_school(const string& name, const int start, const int end);

	void print_schools() const;

	void delete_school(int n);

};
