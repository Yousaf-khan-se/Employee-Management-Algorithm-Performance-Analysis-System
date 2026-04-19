//Muhammad Yousaf
//22i-8797
//Assignment 1
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Date
{
    unsigned short int year;
    unsigned short int month;
    unsigned short int day;

    Date();
};

class Employee
{
    string name;
    string id;
    unsigned int salary;
    Date joining_date;
    string designation;
    static size_t number_of_employees;

public:
    Employee();

    // Parameterized constructor to initialize Employee
    Employee(const string& n, const string& empId, unsigned int sal, const Date& date, const string& desig);

    //Copy constructor
    Employee(const Employee& other);

    // Getter functions
    string getName() const;
    string getEmployeeID() const;
    unsigned int getSalary() const;
    Date getJoiningDate() const;
    string getDesignation() const;
	size_t getNumberOfEmployees() const;

	// Setter functions
    void setName(const string name);
	void setEmployeeID(const string id);
    void setSalary(const unsigned int salary);
	void setJoiningDate(const Date date);
    void setDesignation(const string designation);
    void setNumberOfEmployees(size_t num);

    void printData();
    void printNameAndSalary();
    void printNameAndTenure();
};

#endif
