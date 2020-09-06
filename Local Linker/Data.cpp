#include <iostream>

#include "Data.h"

Data::Data(const string& user, const string& pass): year_of_passing(0), graph_id(0), school_adr(nullptr)
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

void Data::set_school(School* adr)
{
	this->school_adr = adr;
}

void Data::add_new_school(const string& name, const int start, const int end)
{
	School* ptr = this->school_adr;
	School* n_node = new School();
	n_node->set_name(name);
	n_node->set_start_year(start);
	n_node->set_end_year(end);
	if (ptr->get_end_year() <= start)
	{
		n_node->set_next_school(ptr);
		this->school_adr = n_node;
	}
	else
	{
		School* prev = ptr;
		while (ptr && ptr->get_end_year() > start)
		{
			prev = ptr;
			ptr = ptr->get_next_school();
		}
		if (ptr)
		{
			n_node->set_next_school(ptr);
			prev->set_next_school(n_node);
		}
		else
		{
			prev->set_next_school(n_node);
		}
	}
}

void Data::print_schools() const
{
	School* ptr = this->school_adr;
	if (ptr)
	{
		int i = 1;
		while (ptr)
		{
			cout << i << ". " << ptr->get_name() << " " << ptr->get_start_year() << "-" << ptr->get_end_year() << endl;
			ptr = ptr->get_next_school();
			i++;
		}
	}
	else
	{
		cout << "No Schools to show!" << endl;
	}
}

void Data::delete_school(int n)
{
	School* ptr = this->school_adr;

	if (n == 1)
	{
		this->school_adr = this->get_school_adr();
	}
	else
	{
		while (ptr && n != 2)
		{
			ptr = ptr->get_next_school();
			n--;
		}
		if (ptr)
		{
			School* prev = ptr;
			ptr = ptr->get_next_school();
			if (ptr)
			{
				prev->set_next_school(ptr->get_next_school());
			}
			else
			{
				prev->set_next_school(nullptr);
			}
		}
		else
		{
			cout << "Please select correct option!!" << endl;
		}
	}
}

School* Data::get_school_adr() const
{
	return this->school_adr;
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
