# Task Management System ![C++](https://img.shields.io/badge/Language-C++-blue) ![First Project](https://img.shields.io/badge/Project-First%20University%20Project-green) ![Build](https://img.shields.io/badge/Build-Passing-brightgreen) ![License](https://img.shields.io/badge/License-MIT-yellow)

**My first university project and my first experience building a larger C++ program.**  
A **console-based C++ Task Management System** that allows administrators, operators, and employees to manage tasks efficiently, submit files, and provide feedback, with an interactive and color-coded console interface.

---

## Table of Contents
- [Overview](#overview)  
- [Features](#features)  
- [Roles & Permissions](#roles--permissions)  
- [Installation & Usage](#installation--usage)  
- [Technologies](#technologies)  
- [License](#license)

---

## Overview
This project was created as my **first major university project**, demonstrating my ability to build a **larger-scale C++ program**. The system is fully **console-based** and uses color-coded output for an improved user experience. (The code is designed to run on Windows)

---

## Features
- Add, delete, and view tasks (Admin)  
- Review tasks, mark them as completed, and provide feedback (Operator)  
- Submit files for tasks (Employee)  
- Interactive console UI with color-coded messages  
- Role-based access control  
- Input validation to prevent errors  

---

## Roles & Permissions

| Role        | Permissions |
|------------|-------------|
| **Admin**  | Add tasks, delete tasks, view task results |
| **Operator** | View tasks, mark tasks as completed, provide feedback |
| **Employee** | Submit task files, view assigned tasks |

---

## Installation & Usage

1. **Clone the repository:**
```c
git clone https://github.com/your-username/Task-Management-System.git
Compile the project (Linux/macOS):
g++ Task\ Managment\ System\ Project.cpp -o task

Or on Windows:
g++ Task\ Managment\ System\ Project.cpp -o task.exe (Recommended)

Run the executable:
./task   # Linux/macOS
task.exe # Windows

After runing the program, the program will display login in page:
For Admin:
  username: khaled
  pass: 1234
For Operator:
  username: zaid
  pass: 12345
For employee:
  username: ahmad
  pass: 123456
```

---

## Technologies

- Language: C++
- Platform: Cross-platform (Windows/Linux)
- Interface: Console-based, color-coded output

---

## License

- This project is open source and available under the MIT License.
