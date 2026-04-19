# Employee Management & Algorithm Analysis System

A professional C++ console application designed to manage employee records and perform a comparative analysis of fundamental sorting algorithms. This project demonstrates high-level **Object-Oriented Programming (OOP)**, **File I/O**, and **Algorithm Performance Metrics**.

## 📝 Project Description
This system acts as a mini-database for an organization. It reads employee profiles (including ID, Salary, Designation, and Joining Date) from a text file and allows the user to organize this data using different sorting techniques. 

The primary focus is on **Algorithm Analysis**: the system doesn't just sort the data; it measures exactly how efficient each algorithm is by tracking execution time, total comparisons, and the number of swaps performed.

## 💎 Core Concepts & Features
- **Object-Oriented Modeling**: Uses a dedicated `Employee` class with encapsulation. It also tracks the total number of employee instances using a `static` member variable.
- **File Processing**: Implements robust logic to parse colon-separated data from `Employeedata.txt`.
- **Comparative Sorting**:
  - **Bubble Sort**: Simple iterative sorting.
  - **Selection Sort**: Finds the minimum element repeatedly.
  - **Insertion Sort**: Builds the final sorted array one item at a time.
- **Performance Benchmarking**: 
  - Tracks execution time in **microseconds** using the `<chrono>` library.
  - Monitors the "algorithmic cost" by counting total **comparisons** and **swaps**.

## 📂 File Structure
* **`main.cpp`**: Controls the application flow. It populates the employee array and presents an interactive menu to the user.
* **`Employee.h` & `Employee.cpp`**: Defines the data model. Handles the storage and retrieval of employee attributes.
* **`SortUtils.h`**: A logic-heavy header containing the sorting algorithms and utility functions like `Swap` and `StoreDesignations`.
* **`Employeedata.txt`**: The data source. Ensure this file is in the same directory as your executable for the program to load data correctly.

## 🚀 How to Run

### 1. Prerequisites
- A C++ compiler (GCC/G++ recommended).
- The `Employeedata.txt` file must be present in the project root.

### 2. Compilation
Open your terminal and compile all the C++ files together:
```bash
g++ main.cpp Employee.cpp -o EmployeeSystem
```

### 3. Execution
Run the compiled program:
```bash
./EmployeeSystem
```

## 📊 Sample Output
After selecting a sorting method from the menu, the console will display:
1. The sorted list of employees by their tenure/joining date.
2. **Time of execution** (e.g., 450 microseconds).
3. **Number of comparisons**.
4. **Number of swaps**.

## 👤 Author
**Muhammad Yousaf**
