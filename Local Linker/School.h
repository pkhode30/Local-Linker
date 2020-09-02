#pragma once

#include <string>

using namespace std;

class School
{
private:
	string s_name;
	int s_year;
	int e_year;
	School* next;
	
public:

	School();

	void set_name(const string& name);

	void set_start_year(const int year);

	void set_end_year(const int year);

	void set_next_school(School* n_adr);

	string get_name() const;

	int get_start_year() const;

	int get_end_year() const;

	School* get_next_school() const;
};
