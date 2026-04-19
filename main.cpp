//Muhammad Yousaf
//22i-8797
//Assignment 1
#include "Employee.h"
#include "SupportingFunctions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

    int main()
    {
        Employee employee[10];

        ifstream inputFile("Employeedata.txt");
        if (!inputFile)
        {
            cerr << "Error opening the file." << endl;
            return 1;
        }

        string current_word;
        size_t employee_no = 0;
        string details[6];
        size_t i = 0;
        while (getline(inputFile, details[i]))
        {
            details[i] += '\0';

            for (size_t j = 0; details[i][j] != '\0'; j++)
            {
                if (i == 5)
                    break;

                if (details[i][j] == ':')
                {
                    current_word = "";
                    j++;
                    while (details[i][j] != '\0')
                    {
                        j++;
                        current_word += details[i][j];
                    }
                    //current_word += '\0';

                    if (i == 0)
                        employee[employee_no].setName(current_word);
                    else if (i == 1)
                        employee[employee_no].setEmployeeID(current_word);
                    else if (i == 2)
                    {
                        string num = "";
                        for (size_t k = 0; k < lengthOf(current_word); k++)
                        {
                            if (current_word[k] == '$' || current_word[k] == ',')
                            {
                                continue;
                            }
                            else
                            {
                                num += current_word[k];
                            }
                        }
                        employee[employee_no].setSalary(static_cast<unsigned int>(stoi(num)));
                    }
                    else if (i == 3)
                    {
                        Date d;
                        string num;
                        for (size_t k = 0; k <= lengthOf(current_word); k++)
                        {
                            if (current_word[k] == '-' || k == lengthOf(current_word))
                            {
                                if (k == 4)
                                    d.year = static_cast<unsigned short int>(stoi(num));
                                else if (k == 7)
                                    d.month = static_cast<unsigned short int>(stoi(num));
                                else if (k == lengthOf(current_word))
                                    d.day = static_cast<unsigned short int>(stoi(num));

                                num = "";
                            }
                            else
                            {
                                num += current_word[k];
                            }
                        }
                        employee[employee_no].setJoiningDate(d);
                    }
                    else if (i == 4)
                    {
                        employee[employee_no].setDesignation(current_word);
                    }

                    break;
                }
            }

            i++;
            if (i == 6)
            {
                i = 0;
                employee_no++;
                for (size_t m = 0; m < 6; m++)
                    details[m] = "";
            }
        }
        inputFile.close();
        StoreDesignationsIn(employee,designations);
        // Just to check if the data is correctly stored
        /*for (int i = 0; i < 10; i++)
        {
            employee[i].printData();
        }*/

        //************************** Scenario 1 *****************************
        std::cout << "\033[32m***************************************** Initial Employee Performance Matrix \033[0m" << endl<<endl;
        std::cout << "Average Salary in the company : $" << AverageSalary(employee) << endl
             << "Number of Employees in the company : " << employee[0].getNumberOfEmployees() << endl
             << "Average Tenure of Employees in the company : " << AverageTenure(employee) <<" years"<< endl;
        PrintDesignationBasedDistribution(employee);
        std::cout << "_________________________________________________" << endl
             << "    Employee with Longest Tenure of "<<(2023 - employee[EmployeeIndexOfLongestTenure(employee)].getJoiningDate().year)<<" years :" << endl;
        employee[EmployeeIndexOfLongestTenure(employee)].printData();

        //************************** Scenario 2 *****************************
        std::cout << "\033[32m***************************************** Salary Comparisons \033[0m" << endl << endl;
        std::cout << "Heighest Salary Among Employees : $" << HeighestSalaryOfCompany(employee) << endl;
        std::cout << "Lowest Salary Among Employees : $" << LowestSalaryOfCompany(employee) << endl;
        std::cout << "Salary Range of the company : $" << SalaryRangeOfCompany(employee) << endl;
        std::cout << "Median Salary of the company : $" << SalaryMedianOfCompany(employee) << endl;
        PrintAverageSalaryOfEachDesignation(employee);
        std::cout << "_________________________________________________" << endl;
        std::cout << "Employee with Highest Salary : " << endl;
        employee[EmployeeIndexHeighestSalary(employee)].printData();

        //************************** Scenario 3 *****************************
        std::cout << "\033[32m***************************************** Employee Tenure Analysis \033[0m" << endl << endl;
        std::cout << "_________________________________________________" << endl;
        cout << "Employee with longest Tenure of " << (2023 - employee[EmployeeIndexOfLongestTenure(employee)].getJoiningDate().year) << " years :" << endl;
        employee[EmployeeIndexOfLongestTenure(employee)].printData();
        std::cout << "_________________________________________________" << endl;
        cout << "Employee with shortest Tenure of " << (2023 - employee[EmployeeIndexOfShortestTenure(employee)].getJoiningDate().year) << " years :" << endl;
        employee[EmployeeIndexOfShortestTenure(employee)].printData();
        PrintAverageTenureOfEachDesignation(employee);
        std::cout<< endl << "The Highest Paid Designation : " << HeighestPaidDesignation(employee) << endl;
        
        //************************** Scenario 4 *****************************
        std::cout << "\033[32m***************************************** Employee Ranking By Salary \033[0m" << endl << endl;
        float time = 0;
        unsigned int no_comparisons = 0;
        unsigned int no_swaps = 0;

        unsigned short int choice = 1;
        while(choice >=1 && choice <= 3)
        {
            std::cout<<endl << "  For Sorting of employees according to salaries: " << endl
                << "1.  For Bubble Sort " << endl
                << "2.  For Selection Sort " << endl
                << "3.  For Insertion Sort " << endl
                << "4 or >4. To Exit this Menu " << endl;
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                    std::cout << "_________________________________________________" << endl;
                    BubbleSortBySalaries(employee, time, no_comparisons, no_swaps);
                    std::cout << "         After Bubble Sort       " << endl;
                    for (size_t i = 0; i < employee[0].getNumberOfEmployees(); i++)
                    {
                        employee[i].printNameAndSalary();
                        std::cout << endl;
                    }
                    std::cout << endl;
                    std::cout << "Time of execution : " << time << " microseconds" << endl;
                    std::cout << "number of comparisons : " << no_comparisons << endl;
                    std::cout << "number of swaps : " << no_swaps << endl;
                    break;
                case 2:
                    std::cout << "_________________________________________________" << endl;
                    SelectionSortBySalaries(employee, time, no_comparisons, no_swaps);

                    std::cout << "         After Selection Sort       " << endl;
                    for (size_t i = 0; i < employee[0].getNumberOfEmployees(); i++)
                    {
                        employee[i].printNameAndSalary();
                        std::cout << endl;
                    }
                    std::cout << endl;
                    std::cout << "Time of execution : " << time << " microseconds" << endl;
                    std::cout << "number of comparisons : " << no_comparisons << endl;
                    std::cout << "number of swaps : " << no_swaps << endl;
                    break;
                case 3:
                    std::cout << "_________________________________________________" << endl;
                    InsertionSortBySalaries(employee, time, no_comparisons, no_swaps);

                    std::cout << "         After Insertion Sort       " << endl;
                    for (size_t i = 0; i < employee[0].getNumberOfEmployees(); i++)
                    {
                        employee[i].printNameAndSalary();
                        std::cout << endl;
                    }
                    std::cout << endl;
                    std::cout << "Time of execution : " << time << " microseconds" << endl;
                    std::cout << "number of comparisons : " << no_comparisons << endl;
                    std::cout << "number of swaps : " << no_swaps << endl;
                    break;
            }
        }

        //************************** Scenario 5 *****************************
        std::cout << "\033[32m***************************************** Employee Ranking By Salary \033[0m" << endl << endl;

        choice = 1;
        while (choice >= 1 && choice <= 3)
        {
            std::cout << endl << "  For Sorting of employees according to tenure: " << endl
                << "1.  For Bubble Sort " << endl
                << "2.  For Selection Sort " << endl
                << "3.  For Insertion Sort " << endl
                << "4 or >4. To Exit this Menu " << endl;
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                std::cout << "_________________________________________________" << endl;
                BubbleSortByTenure(employee, time, no_comparisons, no_swaps);
                std::cout << "         After Bubble Sort       " << endl;
                for (size_t i = 0; i < employee[0].getNumberOfEmployees(); i++)
                {
                    employee[i].printNameAndTenure();
                    std::cout << endl;
                }
                std::cout << endl;
                std::cout << "Time of execution : " << time << " microseconds" << endl;
                std::cout << "number of comparisons : " << no_comparisons << endl;
                std::cout << "number of swaps : " << no_swaps << endl;
                break;
            case 2:
                std::cout << "_________________________________________________" << endl;
                SelectionSortByTenure(employee, time, no_comparisons, no_swaps);

                std::cout << "         After Selection Sort       " << endl;
                for (size_t i = 0; i < employee[0].getNumberOfEmployees(); i++)
                {
                    employee[i].printNameAndTenure();
                    std::cout << endl;
                }
                std::cout << endl;
                std::cout << "Time of execution : " << time << " microseconds" << endl;
                std::cout << "number of comparisons : " << no_comparisons << endl;
                std::cout << "number of swaps : " << no_swaps << endl;
                break;
            case 3:
                std::cout << "_________________________________________________" << endl;
                InsertionSortByTenure(employee, time, no_comparisons, no_swaps);

                std::cout << "         After Insertion Sort       " << endl;
                for (size_t i = 0; i < employee[0].getNumberOfEmployees(); i++)
                {
                    employee[i].printNameAndTenure();
                    std::cout << endl;
                }
                std::cout << endl;
                std::cout << "Time of execution : " << time << " microseconds" << endl;
                std::cout << "number of comparisons : " << no_comparisons << endl;
                std::cout << "number of swaps : " << no_swaps << endl;
                break;
            }
        }
        
        return 0;
    }
