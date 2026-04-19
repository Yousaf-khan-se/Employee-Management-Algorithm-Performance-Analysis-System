//Muhammad Yousaf
//22i-8797
//Assignment 1
#ifndef SUPPORTINGFUNCTION_H
#define SUPPORTINGFUNCTION_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

size_t lengthOf(string st)
{
	size_t len = 0;
	while (st[len] != '\0')
		len++;

	return len;
}

template <typename H>
void Swap(H& a, H& b)
{
	H temp = a;
	a = b;
	b = temp;
}
string designations[7]; // Stores total designations uniquely
void StoreDesignationsIn(Employee element[], string designations[], size_t num = 7)
{
	bool skip = false;
	size_t t = 0;
	for (int i = 0; i < 10; i++)
	{
		skip = false;
		for (int j = i + 1; j < 10; j++)
		{
			if (element[i].getDesignation() == element[j].getDesignation())
			{
				skip = true;
				break;
			}
		}
		if (skip)
			continue;
		else
		{
			designations[t] = element[i].getDesignation();
			t++;
		}
	}
	//for (int j = 0; j < 7; j++)
		//std::cout<<"-"<< designations[j] << "-" << endl;
}

//*****************************  Scenario 1
double AverageSalary(Employee element[])
{
	unsigned int sum = 0;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		sum += element[i].getSalary();
	}
	return static_cast<double>(sum) / static_cast<double>(element[0].getNumberOfEmployees());
}
unsigned int AverageTenure(Employee element[])
{
	unsigned int sum = 0;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		sum += (2023 - element[i].getJoiningDate().year);
	}
	return sum / static_cast<unsigned int>(element[0].getNumberOfEmployees());
}
void PrintDesignationBasedDistribution(Employee element[])
{
	unsigned int SoftwareEngineer = 0;
	unsigned int SeniorSoftwareEngineer = 0;
	unsigned int DataScientist = 0;
	unsigned int ProjectManager = 0;
	unsigned int SeniorDataAnalyst = 0;
	unsigned int UxDesigner = 0;
	unsigned int QualityAssuranceAnalyst = 0;
	std::cout<< "_________________________________________________" << endl;
	std::cout<< "	Distribution of employees based on designation" << endl;

	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getDesignation() == designations[3])
			SoftwareEngineer++;
		else if (element[i].getDesignation() == designations[5])
			SeniorSoftwareEngineer++;
		else if (element[i].getDesignation() == designations[6])
			DataScientist++;
		else if (element[i].getDesignation() == designations[0])
			ProjectManager++;
		else if (element[i].getDesignation() == designations[1])
			SeniorDataAnalyst++;
		else if (element[i].getDesignation() == designations[2])
			UxDesigner++;
		else if (element[i].getDesignation() == designations[4])
			QualityAssuranceAnalyst++;
	}

	std::cout<< "Software Engineers : " << SoftwareEngineer << " employees " << endl
		<< "Senior Software Engineers : " << SeniorSoftwareEngineer << " employees " << endl
		<< "Data Sceintists : " << DataScientist << " employees " << endl
		<< "Project Managers : " << ProjectManager << " employees " << endl
		<< "Senior Data Analysts : " << SeniorDataAnalyst << " employees " << endl
		<< "UX Designers : " << UxDesigner << " employees " << endl
		<< "Quality Assurance Analysts : " << QualityAssuranceAnalyst << " employees " << endl;
}
size_t EmployeeIndexOfLongestTenure(Employee element[])
{
	unsigned short int max_tenure = 0;
	size_t index = -1;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (max_tenure < (2023 - element[i].getJoiningDate().year))
		{
			max_tenure = (2023 - element[i].getJoiningDate().year);
			index = i;
		}
		else if (max_tenure == (2023 - element[i].getJoiningDate().year))
		{
			if (element[index].getJoiningDate().month > element[i].getJoiningDate().month)
			{
				max_tenure = (2023 - element[i].getJoiningDate().year);
				index = i;
			}
		}
	}
	return index;
}
//*****************************  Scenario 2
unsigned int HeighestSalaryOfCompany(Employee element[])
{
	unsigned int max_salary = 0;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getSalary() > max_salary)
		{
			max_salary = element[i].getSalary();
		}
	}
	return max_salary;
}
unsigned int LowestSalaryOfCompany(Employee element[])
{
	unsigned int min_salary = 99999999;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getSalary() < min_salary)
		{
			min_salary = element[i].getSalary();
		}
	}
	return min_salary;
}
unsigned int SalaryRangeOfCompany(Employee element[])
{
	return (HeighestSalaryOfCompany(element) - LowestSalaryOfCompany(element));
}
double SalaryMedianOfCompany(Employee array[])
{
	const size_t Size = array[0].getNumberOfEmployees();
	unsigned int *element = new unsigned int[Size];
	for(size_t i = 0; i<Size; i++)
	{
		element[i] = array[i].getSalary();
	}

	//Selection Sort to sort array according to salaries
	size_t smallest;
	for (size_t i = 0; i < Size -1; i++)
	{
		smallest = i;
		for (size_t j = i + 1; j < Size; j++)
		{
			if (element[j] < element[smallest])
				smallest = j;
		}
		Swap(element[smallest], element[i]);
	}

	double mid1 = static_cast<double>(element[(Size / 2)]);
	double mid2 = static_cast<double>(element[(Size/2) - 1]);

	delete[] element;
	element = nullptr;

	std::cout<< "This median is valid only if the employees would be sorted in ascending order according to their salaries" << endl;
	if (Size % 2 == 0)
	{
		return static_cast<double>((mid2 + mid1) / 2.0);
	}
	else
		return static_cast<double>(mid1);
}
void PrintAverageSalaryOfEachDesignation(Employee element[])
{
	unsigned int SoftwareEngineer = 0;
	unsigned int SoftwareEngineerSalarySum = 0;
	unsigned int SeniorSoftwareEngineer = 0;
	unsigned int SeniorSoftwareEngineerSalarySum = 0;
	unsigned int DataScientist = 0;
	unsigned int DataScientistSalarySum = 0;
	unsigned int ProjectManager = 0;
	unsigned int ProjectManagerSalarySum = 0;
	unsigned int SeniorDataAnalyst = 0;
	unsigned int SeniorDataAnalystSalarySum = 0;
	unsigned int UxDesigner = 0;
	unsigned int UxDesignerSalarySum = 0;
	unsigned int QualityAssuranceAnalyst = 0;
	unsigned int QualityAssuranceAnalystSalarySum = 0;
	std::cout<< "_________________________________________________" << endl;
	std::cout<< "	Average Salaries of employees based on designation" << endl;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getDesignation() == designations[3])
		{
			SoftwareEngineer++;
			SoftwareEngineerSalarySum += element[i].getSalary();
		}
		else if (element[i].getDesignation() == designations[5])
		{
			SeniorSoftwareEngineer++;
			SeniorSoftwareEngineerSalarySum += element[i].getSalary();
		}
		else if (element[i].getDesignation() == designations[6])
		{
			DataScientist++;
			DataScientistSalarySum += element[i].getSalary();
		}
		else if (element[i].getDesignation() == designations[0])
		{
			ProjectManager++;
			ProjectManagerSalarySum += element[i].getSalary();
		}
		else if (element[i].getDesignation() == designations[1])
		{
			SeniorDataAnalyst++;
			SeniorDataAnalystSalarySum += element[i].getSalary();
		}
		else if (element[i].getDesignation() == designations[2])
		{
			UxDesigner++;
			UxDesignerSalarySum += element[i].getSalary();
		}
		else if (element[i].getDesignation() == designations[4])
		{
			QualityAssuranceAnalyst++;
			QualityAssuranceAnalystSalarySum += element[i].getSalary();
		}
	}

	std::cout<< "Software Engineers : $" << SoftwareEngineerSalarySum/SoftwareEngineer << endl
		<< "Senior Software Engineers : $" << SeniorSoftwareEngineerSalarySum/SeniorSoftwareEngineer << endl
		<< "Data Sceintists : $" << DataScientistSalarySum/DataScientist << endl
		<< "Project Managers : $" << ProjectManagerSalarySum/ProjectManager << endl
		<< "Senior Data Analysts : $" << SeniorDataAnalystSalarySum/SeniorDataAnalyst << endl
		<< "UX Designers : $" << UxDesignerSalarySum/UxDesigner << endl
		<< "Quality Assurance Analysts : $" << QualityAssuranceAnalystSalarySum/QualityAssuranceAnalyst << endl;
}
size_t EmployeeIndexHeighestSalary(Employee element[])
{
	unsigned int max_salary = 0;
	size_t element_index = 0;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getSalary() > max_salary)
		{
			max_salary = element[i].getSalary();
			element_index = i;
		}
	}
	return element_index;
}

//*****************************  Scenario 3
size_t EmployeeIndexOfShortestTenure(Employee element[])
{
	unsigned short int min_tenure = 999;
	size_t index = -1;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (min_tenure > (2023 - element[i].getJoiningDate().year))
		{
			min_tenure = (2023 - element[i].getJoiningDate().year);
			index = i;
		}
		else if (min_tenure == (2023 - element[i].getJoiningDate().year))
		{
			if (element[index].getJoiningDate().month < element[i].getJoiningDate().month)
			{
				min_tenure = (2023 - element[i].getJoiningDate().year);
				index = i;
			}
		}
	}
	return index;
}
void PrintAverageTenureOfEachDesignation(Employee element[])
{
	unsigned int SoftwareEngineer = 0;
	unsigned int SoftwareEngineerTenureSum = 0;
	unsigned int SeniorSoftwareEngineer = 0;
	unsigned int SeniorSoftwareEngineerTenureSum = 0;
	unsigned int DataScientist = 0;
	unsigned int DataScientistTenureSum = 0;
	unsigned int ProjectManager = 0;
	unsigned int ProjectManagerTenureSum = 0;
	unsigned int SeniorDataAnalyst = 0;
	unsigned int SeniorDataAnalystTenureSum = 0;
	unsigned int UxDesigner = 0;
	unsigned int UxDesignerTenureSum = 0;
	unsigned int QualityAssuranceAnalyst = 0;
	unsigned int QualityAssuranceAnalystTenureSum = 0;
	std::cout << "_________________________________________________" << endl;
	std::cout << "	Average Tenure of employees based on designation" << endl;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getDesignation() == designations[3])
		{
			SoftwareEngineer++;
			SoftwareEngineerTenureSum += (2023 - element[i].getJoiningDate().year);
		}
		else if (element[i].getDesignation() == designations[5])
		{
			SeniorSoftwareEngineer++;
			SeniorSoftwareEngineerTenureSum += (2023 - element[i].getJoiningDate().year);
		}
		else if (element[i].getDesignation() == designations[6])
		{
			DataScientist++;
			DataScientistTenureSum += (2023 - element[i].getJoiningDate().year);
		}
		else if (element[i].getDesignation() == designations[0])
		{
			ProjectManager++;
			ProjectManagerTenureSum += (2023 - element[i].getJoiningDate().year);
		}
		else if (element[i].getDesignation() == designations[1])
		{
			SeniorDataAnalyst++;
			SeniorDataAnalystTenureSum += (2023 - element[i].getJoiningDate().year);
		}
		else if (element[i].getDesignation() == designations[2])
		{
			UxDesigner++;
			UxDesignerTenureSum += (2023 - element[i].getJoiningDate().year);
		}
		else if (element[i].getDesignation() == designations[4])
		{
			QualityAssuranceAnalyst++;
			QualityAssuranceAnalystTenureSum += (2023 - element[i].getJoiningDate().year);
		}
	}

	std::cout << "Software Engineers : " << SoftwareEngineerTenureSum / SoftwareEngineer << " years"<<endl
		<< "Senior Software Engineers : " << SeniorSoftwareEngineerTenureSum / SeniorSoftwareEngineer << " years" << endl
		<< "Data Sceintists : " << DataScientistTenureSum / DataScientist << " years" << endl
		<< "Project Managers : " << ProjectManagerTenureSum / ProjectManager << " years" << endl
		<< "Senior Data Analysts : " << SeniorDataAnalystTenureSum / SeniorDataAnalyst << " years" << endl
		<< "UX Designers : " << UxDesignerTenureSum / UxDesigner << " years" << endl
		<< "Quality Assurance Analysts : " << QualityAssuranceAnalystTenureSum / QualityAssuranceAnalyst << " years" << endl;
}
string HeighestPaidDesignation(Employee element[])
{
	unsigned int max_salary = 0;
	size_t element_index = 0;
	for (size_t i = 0; i < element[0].getNumberOfEmployees(); i++)
	{
		if (element[i].getSalary() > max_salary)
		{
			max_salary = element[i].getSalary();
			element_index = i;
		}
	}
	return element[element_index].getDesignation();
}

//*****************************  Scenario 4
void BubbleSortBySalaries(Employee element[], float &time, unsigned int &no_comparisons, unsigned int &no_swaps)
{
	time = 0;
	no_comparisons = 0;
	no_swaps = 0;
	const size_t s = element[0].getNumberOfEmployees();

	// start the stop watch
	auto start_time = std::chrono::high_resolution_clock::now();

	bool swapped = false;
	for (int i = 0 ; no_comparisons++, i < s - 1; i++)
	{
		for (int j = 0; no_comparisons++, j < s - i - 1; j++)
		{
			no_comparisons++;
			if (element[j + 1].getSalary() < element[j].getSalary())
			{
				Swap(element[j], element[j + 1]);
				no_swaps++;
				swapped = true;
			}
		}
		no_comparisons++;
		if (!swapped)
		{
			break;
		}
	}

	// Stop the stopwatch
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	time =  elapsed_time.count();
}
void SelectionSortBySalaries(Employee element[], float& time, unsigned int& no_comparisons, unsigned int& no_swaps)
{
	time = 0;
	no_comparisons = 0;
	no_swaps = 0;
	const size_t s = element[0].getNumberOfEmployees();

	// start the stop watch
	auto start_time = std::chrono::high_resolution_clock::now();

	size_t smallest = 0;
	for (int i = 0;no_comparisons++, i < s - 1; i++)
	{
		smallest = i;
		for (int j = i + 1; no_comparisons++, j < s; j++)
		{
			no_comparisons++;
			if (element[j].getSalary() < element[smallest].getSalary())
			{
				smallest = j;
			}
		}
		no_swaps++;
		Swap(element[smallest], element[i]);
	}


	// Stop the stopwatch
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	time = elapsed_time.count();
}
void InsertionSortBySalaries(Employee element[], float& time, unsigned int& no_comparisons, unsigned int& no_swaps)
{
	time = 0;
	no_comparisons = 0;
	no_swaps = 0;
	const size_t s = element[0].getNumberOfEmployees();

	// start the stop watch
	auto start_time = std::chrono::high_resolution_clock::now();

	Employee current;
	current.setNumberOfEmployees(element[0].getNumberOfEmployees()-1);// As it is a temporary variable
	for (int i = 1, j; no_comparisons++, i < s; i++)
	{
		current = element[i];
		for (j = i - 1; no_comparisons+=3, j >= 0 && current.getSalary() < element[j].getSalary(); j--)
		{
			element[j + 1] = element[j];
		}
		element[j + 1] = current;
		no_swaps++;
	}

	// Stop the stopwatch
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	time = elapsed_time.count();
}

//*****************************  Scenario 5
void BubbleSortByTenure(Employee element[], float& time, unsigned int& no_comparisons, unsigned int& no_swaps)
{
	time = 0;
	no_comparisons = 0;
	no_swaps = 0;
	const size_t s = element[0].getNumberOfEmployees();

	// start the stop watch
	auto start_time = std::chrono::high_resolution_clock::now();

	bool swapped = false;
	for (int i = 0; no_comparisons++, i < s - 1; i++)
	{
		for (int j = 0; no_comparisons++, j < s - i - 1; j++)
		{
			no_comparisons++;
			if (element[j + 1].getJoiningDate().year > element[j].getJoiningDate().year)
			{
				Swap(element[j], element[j + 1]);
				no_swaps++;
				swapped = true;
			}
		}
		no_comparisons++;
		if (!swapped)
		{
			break;
		}
	}

	// Stop the stopwatch
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	time = elapsed_time.count();
}
void SelectionSortByTenure(Employee element[], float& time, unsigned int& no_comparisons, unsigned int& no_swaps)
{
	time = 0;
	no_comparisons = 0;
	no_swaps = 0;
	const size_t s = element[0].getNumberOfEmployees();

	// start the stop watch
	auto start_time = std::chrono::high_resolution_clock::now();

	size_t smallest = 0;
	for (int i = 0; no_comparisons++, i < s - 1; i++)
	{
		smallest = i;
		for (int j = i + 1; no_comparisons++, j < s; j++)
		{
			no_comparisons++;
			if (element[j].getJoiningDate().year > element[smallest].getJoiningDate().year)
			{
				smallest = j;
			}
		}
		no_swaps++;
		Swap(element[smallest], element[i]);
	}


	// Stop the stopwatch
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	time = elapsed_time.count();
}
void InsertionSortByTenure(Employee element[], float& time, unsigned int& no_comparisons, unsigned int& no_swaps)
{
	time = 0;
	no_comparisons = 0;
	no_swaps = 0;
	const size_t s = element[0].getNumberOfEmployees();

	// start the stop watch
	auto start_time = std::chrono::high_resolution_clock::now();

	Employee current;
	current.setNumberOfEmployees(element[0].getNumberOfEmployees() - 1);// As it is a temporary variable
	for (int i = 1, j; no_comparisons++, i < s; i++)
	{
		current = element[i];
		for (j = i - 1; no_comparisons += 3, j >= 0 && current.getJoiningDate().year > element[j].getJoiningDate().year; j--)
		{
			element[j + 1] = element[j];
		}
		element[j + 1] = current;
		no_swaps++;
	}

	// Stop the stopwatch
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculate the elapsed time
	auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	time = elapsed_time.count();
}


#endif // !SUPPORTINGFUNCTION_H
