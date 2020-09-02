#include "Data.h"


Data::Data(const string& user, const string& pass): year_of_passing(0)
{
	this->userID = user;
	this->password = pass;
}

void Data::set_name(const string& Name)
{
	this->name = Name;
}

void Data::set_department(const string& department)
{
	this->department_name = department;
}

void Data::set_passing_year(const int& year)
{
	this->year_of_passing = year;
}

void Data::set_graph_id(const int& id)
{
	this->graph_id = id;
}

void Data::set_password(const string& pass)
{
	this->password = pass;
}

string Data::get_password() const
{
	return password;
}

string Data::get_name() const
{
	return name;
}

string Data::get_userID() const
{
	return userID;
}

string Data::get_department() const
{
	return department_name;
}

int Data::get_year_of_passing() const
{
	return year_of_passing;
}
