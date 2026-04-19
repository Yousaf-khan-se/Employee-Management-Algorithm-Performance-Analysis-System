//Muhammad Yousaf
//22i-8797
//Assignment 1
#include "Employee.h"
#include <iostream>
using namespace std;

Date::Date()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
}

//______________________Employee
size_t Employee::number_of_employees = 0;
Employee::Employee() : name(""), id(""), salary(0), designation("") 
{
	Employee::number_of_employees++;
}

Employee::Employee(const std::string& n, const std::string& empId, unsigned int sal, const Date& date, const std::string& desig)
	: name(n), id(empId), salary(sal), joining_date(date), designation(desig) 
{

	Employee::number_of_employees++;
}

Employee::Employee(const Employee& other)
{
	this->name = other.name;
	this->id = other.id;
	this->salary = other.salary;
	this->joining_date = other.joining_date;
	this->designation = other.designation;
	this->number_of_employees = other.number_of_employees; // a static variable
}

string Employee::getName() const { return this->name; }
string Employee::getEmployeeID() const { return this->id; }
unsigned int Employee::getSalary() const { return this->salary; }
Date Employee::getJoiningDate() const { return this->joining_date; }
string Employee::getDesignation() const { return this->designation; }
size_t Employee::getNumberOfEmployees() const { return this->number_of_employees; }

void Employee::setName(const string name)
{
	this->name = name;
}
void Employee::setEmployeeID(const string id)
{
	this->id = id;
}
void Employee::setSalary(const unsigned int salary)
{
	this->salary = salary;
}
void Employee::setJoiningDate(const Date date)
{
	this->joining_date.day = date.day;
	this->joining_date.month = date.month;
	this->joining_date.year = date.year;
}
void Employee::setDesignation(const string designation)
{
	this->designation = designation;
}

void Employee::setNumberOfEmployees(size_t num)
{
	this->number_of_employees = num;
}

void Employee::printData()
{
	cout << "Name : " << this->name << endl;
		cout << "id : " << this->id << endl;
		cout << "Salary : $" << this->salary << endl;
		cout << "Joining Date : " << this->joining_date.year << "-" << this->joining_date.month << "-" << this->joining_date.day << endl;
	cout << "Designation : " << this->designation << endl;
	cout << endl;
}

void Employee::printNameAndSalary()
{
	cout << "Name : " << this->name << endl;
	cout << "Salary : $" << this->salary << endl;
}

void Employee::printNameAndTenure()
{
	cout << "Name : " << this->name << endl;
	cout << "Tenure : " << (2023 - this->getJoiningDate().year) << " years " << endl;
}
