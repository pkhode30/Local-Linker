#include "School.h"

School::School(): s_name(""), s_year(0), e_year(0), next(nullptr)
{
}

School::~School()
= default;

void School::set_name(const string& name)
{
	this->s_name = name;
}

void School::set_start_year(const int year)
{
	this->s_year = year;
}

void School::set_end_year(const int year)
{
	this->e_year = year;
}

void School::set_next_school(School* n_adr)
{
	this->next = n_adr;
}

string School::get_name() const
{
	return this->s_name;
}

int School::get_start_year() const
{
	return this->s_year;
}

int School::get_end_year() const
{
	return this->e_year;
}

School* School::get_next_school() const
{
	return this->next;
}
