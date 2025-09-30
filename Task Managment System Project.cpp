#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//This is a definition of some colors by their names to facilitate their use.
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

//The max number of task the program can contain. 
const int MaxTask = 15;

//Structure to represent task related information.
struct Task {
	string Discription, feedback, nameFile;
	bool completed;
};

//An array from Task type.
Task tasks[MaxTask];

//The number of current tasks in the program.
int taskCount = 0;


void loginPage();
void admin();

//This function displays the tasks that will appear to the employees.
void displayTasksForEmployees(const Task tasks[], int taskCount) {
	int choice;
	if (taskCount == 0) {
		cout << "\n\t\t\t\t\t\t" << "No tasks " << GREEN << "Added" << RESET << " yet!\n";
		cout << "\t\t\t\t\t\t" << "Enter " << RED << "0" << RESET << " to go back\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
		cin >> choice;
		while (choice != 0) {
			cout << "\t\t\t\t\t\t" << "please Enter " << GREEN << "valid" << RESET << " choice\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			cin >> choice;
		}
		system("cls");
		loginPage();
	}
	else {
		cout << "\n\t\t\t\t\t\t" << BLUE << "======" << RESET << endl;
		cout << "\t\t\t\t\t\t" << CYAN << "Tasks" << RESET << endl;
		cout << "\t\t\t\t\t\t" << BLUE << "======\n" << RESET << endl;
		for (int i = 0; i < taskCount; ++i) {
			cout << "\t\t\t\t\t\t" << RED << "[" << i << "] " << RESET << "\"" << tasks[i].Discription << "\"";
			if (tasks[i].completed) {
				cout << GREEN << " - Completed\n" << RESET;
			}
			cout << endl;
			cout << "\t\t\t\t\t\t" << YELLOW << "Task file name: " << RESET << tasks[i].nameFile << endl;
			cout << "\n\t\t\t\t\t\t" << GREEN << "***********************************" << RESET << endl;
		}
	}
}

//This function displays the tasks that will appear to the operators to evaluate.
void displayTasksForOperation(const Task tasks[], int taskCount) {
	int choice;
	cout << "\t\t\t\t\t\t" << char(201);
	for (int i = 0; i < 13; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;
	cout << "\t\t\t\t\t\t" << YELLOW << "Operator Page " << RESET << char(186) << endl;
	cout << "\t\t\t\t\t\t" << char(200);
	for (int i = 0; i < 13; i++) {
		cout << char(205);
	}
	cout << char(188) << endl;
	if (taskCount == 0) {
		cout << "\n\t\t\t\t\t\t" << "No tasks " << GREEN << "Added" << RESET << " yet!\n";
		cout << "\t\t\t\t\t\t" << "Enter " << RED << "0" << RESET << " to go back\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
		cin >> choice;
		while (choice != 0) {
			cout << "\t\t\t\t\t\t" << "please Enter " << GREEN << "valid" << RESET << " choice\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			cin >> choice;
		}
		system("cls");
		loginPage();
	}
	else {
		cout << "\n\t\t\t\t\t\t" << BLUE << "======" << RESET << endl;
		cout << "\t\t\t\t\t\t" << CYAN << "Tasks" << RESET << endl;
		cout << "\t\t\t\t\t\t" << BLUE << "======\n" << RESET << endl;
		for (int i = 0; i < taskCount; ++i) {
			cout << "\t\t\t\t\t\t" << RED << "[" << i << "] " << RESET << "\"" << tasks[i].Discription << "\"";
			if (tasks[i].completed) {
				cout << GREEN << " - Completed\n" << RESET;
			}
			cout << endl;
			cout << "\t\t\t\t\t\t" << YELLOW << "Task file name: " << RESET << tasks[i].nameFile << endl;
			cout << "\n\t\t\t\t\t\t" << GREEN << "***********************************" << RESET << endl;
		}
	}
}

//This function displays the tasks that will appear to the Admin tp see their result.
void displayTasksForAdmin(const Task tasks[], int taskCount) {
	int choice;
	if (taskCount == 0) {
		cout << "\n\t\t\t\t\t\t" << "No tasks " << GREEN << "Added" << RESET << " yet!\n";
		cout << "\t\t\t\t\t\t" << "Enter " << RED << "0" << RESET << " for Exit\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
		cin >> choice;
		while (choice != 0) {
			cout << "\t\t\t\t\t\t" << "please Enter " << GREEN << "valid" << RESET << " choice\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			cin >> choice;
		}
		exit(0);
	}
	else {
		cout << "\t\t\t\t\t\t" << BLUE << "======" << RESET << endl;
		cout << "\t\t\t\t\t\t" << CYAN << "Tasks" << RESET << endl;
		cout << "\t\t\t\t\t\t" << BLUE << "======\n" << RESET << endl;
		for (int i = 0; i < taskCount; ++i) {
			cout << "\t\t\t\t\t\t" << RED << "[" << i << "] " << RESET << "\"" << tasks[i].Discription << "\"";
			if (tasks[i].completed) {
				cout << GREEN << " - Completed\n" << RESET;
				cout << "\n\t\t\t\t\t\t" << YELLOW << "feedback: " << RESET << tasks[i].feedback;
			}
			cout << endl;
			cout << "\n\t\t\t\t\t\t" << GREEN <<"***********************************" << RESET << endl;
		}
	}
}

/*
This function displays the screen that will appear to employees when they log in to their account
and this function gives them their limited permissions.
*/
void employee() {
	string choice;
	bool reset1 = true, reset2 = true;
	int taskIndex;
	string NameFile;
	while (reset1) {
		system("cls");
		cout << "\t\t\t\t\t\t" << char(201);
		for (int i = 0; i < 13; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;
		cout << "\t\t\t\t\t\t" << YELLOW << "Employee Page " << RESET << char(186) << endl;
		cout << "\t\t\t\t\t\t" << char(200);
		for (int i = 0; i < 13; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
		displayTasksForEmployees(tasks, taskCount);
		cout << "\n\t\t\t\t\t\t" << "Enter " << RED << "task index" << RESET << " to " << GREEN << "Upload" << RESET << " the file: ";
		cin >> taskIndex;
		cout << "\n\t\t\t\t\t\t" << "Enter " << RED << "File Name" << RESET << " with his extention: ";
		cin >> NameFile;
		tasks[taskIndex].nameFile = NameFile;
		cout << "\t\t\t\t\t\t" << "Uploaded " << GREEN << "Successfuly" << RESET << endl;
		cout << "\n\t\t\t\t\t\t" << "Do you want to " << GREEN << "Submit" << RESET << " another task? " << RED << "(y/n)" << RESET << endl;
		cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
		do {
			cin >> choice;
			if (choice == "y" || choice == "Y") {
				reset1 = true;
				reset2 = true;
			}
			else if (choice == "n" || choice == "N") {
				reset1 = false;
				reset2 = true;
			}
			else {
				reset2 = false;
				cout << "\n\t\t\t\t\t\t" << "Please enter a " << GREEN << "Valid" << RESET << " choice " << RED << "(y/n)" << RESET << endl;
				cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			}
		} while (reset2 == false);
	}
}

/*
This function displays the screen that will appear to operators when they log in to their account
and this function gives them their semi unlimited permissions.
*/
void operation() {
	string filename;
	int choice;
	char choice2;
	string feedback;
	bool reset1 = true;
	bool reset2 = true;

	displayTasksForOperation(tasks, taskCount);
	int taskIndex;
	cout << "\n\t\t\t\t\t\t" << "Do you want to " << GREEN << "Edit?" << RESET << " " << RED << "(y/n) " << RESET << endl;
	cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
	cin >> choice2;
	if (choice2 == 'y') {
		while (reset1) {
			reset2 = true;

			cin.ignore();
			cout << "\t\t\t\t\t\t" << "Enter the " << GREEN << "File Name" << RESET << " or " << GREEN << "Path" << RESET << " : ";
			getline(cin, filename);
			system("cls");
			displayTasksForOperation(tasks, taskCount);
			ifstream file(filename);

			if (file.is_open()) {
				cout << "\n\n\t\t\t\t\t\t" << "The " << GREEN << "Contents" << RESET << " of the " << RED << "file" << RESET << ":" << endl;
				string line;
				cout << "\t\t\t\t\t\t" << BLUE << "*****************************************" << RESET << endl;
				while (getline(file, line)) {
					cout << "\t\t\t\t\t\t" << RED << line << RESET << endl;
				}
				cout << "\t\t\t\t\t\t" << BLUE << "*****************************************" << RESET << endl;
				file.close();
			}
			else {
				cout << "\n\t\t\t\t\t\t" << RED << "ERROR" << "RESET" << " Opening the file." << endl;
			}
			cout << "\n\t\t\t\t\t\t" << "Enter " << RED << "Task Index" << RESET << " to mark as " << GREEN << "completed" << RESET << " : ";
			cin >> taskIndex;
			if (taskIndex >= 0 && taskIndex < taskCount) {
				tasks[taskIndex].completed = true;
				cout << "\t\t\t\t\t\t" << "Task " << GREEN << "Marked As Completed!" << RESET << "\n";
				cout << "\n\t\t\t\t\t\t" << "Give it a " << GREEN << "Feedback" << RESET << " : ";
				cin.ignore();
				getline(cin, feedback);
				tasks[taskIndex].feedback = feedback;
			}
			else {
				cout << "\n\t\t\t\t\t\t" << RED << "Invalid" << RESET << " task index!\n";
			}
			while (reset2) {
				cout << "\n\n\t\t\t\t\t\t" << RED << "[1]" << RESET << " to mark " << GREEN << "Another Task" << RESET << ".\n";
				cout << "\t\t\t\t\t\t" << RED << "[0]" << RESET << " to back to " << GREEN << "Login Page" << RESET << ".\n";
				cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
				cin >> choice;
				if (choice == 1) {
					system("cls");
					displayTasksForOperation(tasks, taskCount);
					reset1 = true;
					reset2 = false;
				}
				else if (choice == 0) {
					reset1 = false;
					reset2 = false;
				}
				else {
					cout << "\n\t\t\t\t\t\t" << "Please enter a " << GREEN << "Valid" << RESET << " choice " << RED << "(y/n)" << RESET << endl;
					reset2 = true;
				}
			}
		}
	}
	else {
		cout << "\t\t\t\t\t\t" << BLUE;
		system("pause");
		cout << RESET;
	}
}

//This functions adds a task when called.
void addTask() {
	bool reset1 = true;
	bool reset2 = true;
	string choice;
	string taskDescription, feedback;
	while (reset1) {
		system("cls");
		cin.ignore();
		cout << "\t\t\t\t\t\t" << char(201);
		for (int i = 0; i < 15; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;
		cout << "\t\t\t\t\t\t" << YELLOW << "Add Task Page   " << RESET << char(186) << endl;
		cout << "\t\t\t\t\t\t" << char(200);
		for (int i = 0; i < 15; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
		if (taskCount < MaxTask) {
			cout << "\n\t\t\t\t\t\t" << "Enter Task " << RED << "Description: " << RESET;
			getline(cin, taskDescription);
			tasks[taskCount].Discription = taskDescription;
			tasks[taskCount].completed = false;
			cout << "\t\t\t\t\t\t" << "Task " << GREEN << "added" << RESET << " successfully!\n" << endl;
			taskCount++;
			cout << "\t\t\t\t\t\t" << "Do you want to " << GREEN << "Add" << RESET << " another task? " << RED << "(y/n)" << RESET << endl;
			cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			do {
				cin >> choice;
				if (choice == "y" || choice == "Y") {
					reset1 = true;
					reset2 = true;
				}
				else if (choice == "n" || choice == "N") {
					reset1 = false;
					reset2 = true;
				}
				else {
					reset2 = false;
					cout << "\n\t\t\t\t\t\t" << "Please enter a " << GREEN << "Valid" << RESET << " choice " << RED << "(y/n)" << RESET << endl;
					cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
				}
			} while (reset2 == false);
		}
		else {
			cout << "\n\t\t\t\t\t\t" << RED << "There is no storage to add task!" << RESET;
			reset1 = false;
			system("pause");
		}
	}
}

//This function removes a specific task when called.
void deleteTask() {
	bool reset1 = true;
	bool reset2 = true;
	int choice;
	string choice2;
	

	int taskIndexToDelete;
	while (reset1) {
		system("cls");
		cout << "\t\t\t\t\t\t" << char(201);
		for (int i = 0; i < 17; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;
		cout << "\t\t\t\t\t\t" << YELLOW << "Delete Task Page  " << RESET << char(186) << endl;
		cout << "\t\t\t\t\t\t" << char(200);
		for (int i = 0; i < 17; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
		cout << "\n";
		displayTasksForAdmin(tasks, taskCount);
		cout << "\n\n\t\t\t\t\t\t" << "Enter task index to " << RED << "Delete" << RESET<< ": ";
		cin >> taskIndexToDelete;

		while (taskIndexToDelete < 0 || taskIndexToDelete >= taskCount) {
			cout << "\t\t\t\t\t\t" << RED << "Invalid " << RESET << "task index!\n";
			cout << "\t\t\t\t\t\t" << "Please enter " << GREEN << "valid" << RESET << " index\n" << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			cin >> taskIndexToDelete;
		}

		for (int i = taskIndexToDelete; i < taskCount - 1; ++i) {
			tasks[i] = tasks[i + 1];
		}
		taskCount--;
		cout << "\t\t\t\t\t\t" << "Task Deleted " << GREEN << "successfully!\n" << RESET<<endl;
		cout << "\t\t\t\t\t\t" << "Do you want to " << GREEN << "Delete" << RESET << " another task? " << RED << "(y/n)" << RESET << endl;
		cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
		do {
			cin >> choice2;
			if (choice2 == "y" || choice2 == "Y") {
				reset1 = true;
				reset2 = true;
				system("cls");
			}
			else if (choice2 == "n" || choice2 == "N") {
				reset1 = false;
				reset2 = true;
			}
			else {
				reset2 = false;
				cout << "\n\t\t\t\t\t\t" << "Please enter a " << GREEN << "valid" << RESET << " choice " << RED << "(y/n)" << RESET << endl;
				cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
			}
		} while (reset2 == false);
	}
}

/*
This function displays the screen that will appear to the administrator when he logs in to his account 
and this function allows him to access his unlimited permissions.
*/
void admin() {
	int choice;
	bool resetfunction = true;
	while (resetfunction) {
		cout << "\t\t\t\t\t\t" << char(201);
		for (int i = 0; i < 10; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;
		cout << "\t\t\t\t\t\t" << YELLOW << "Admin Page " << RESET << char(186) << endl;
		cout << "\t\t\t\t\t\t" << char(200);
		for (int i = 0; i < 10; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;

		cout << "\n\t\t\t\t\t\t" << RED << "[1]" << RESET << GREEN << " Add Task" << RESET << endl;
		cout << "\t\t\t\t\t\t" << RED << "[2]" << RESET << GREEN << " Delete Task" << RESET << endl;
		cout << "\t\t\t\t\t\t" << RED << "[3]" << RESET << GREEN << " Display the result of task" << RESET << endl;
		cout << "\t\t\t\t\t\t" << RED << "[4]" << RESET << GREEN << " back to login page" << RESET << endl;
		cout << "\t\t\t\t\t\t" << RED << "[0]" << RESET << GREEN << " Exit" << RESET << endl;
		cout << "\n\t\t\t\t\t\t" << BLUE << "==> " << RESET;
		cin >> choice;
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			addTask();
			system("cls");
			break;
		case 2:
			deleteTask();
			system("cls");
			break;
		case 3:
			system("cls");
			displayTasksForAdmin(tasks, taskCount);
			cout << "\n\t\t\t\t\t\t"<<BLUE;
			system("pause");
			cout << RESET;
			system("cls");
			break;
		case 4:
			resetfunction = false;
			system("cls");
			break;
		default:
			system("cls");
			cout << "\n\t\t\t\t\t\t" << "Please enter a" << GREEN << " Valid " << RESET << "choice\n" << endl;
		}
	}

}

//This function displays the login screen and selects the account to which it will direct you based on the login data.
void loginPage() {
	int choice, attempts = 3;
	const string user1 = "khaled";
	const string pass1 = "1234";
	const string user2 = "zaid";
	const string pass2 = "12345";
	const string user3 = "ahmad";
	const string pass3 = "123456";
	bool flag = true;
	string username, password;
	while (flag && attempts >= 1) {
		system("cls");
		cout << "\t\t\t\t\t\t" << char(201);
		for (int i = 0; i < 10; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;
		cout << "\t\t\t\t\t\t"<< YELLOW <<"Login Page " << RESET << char(186) << endl;
		cout << "\t\t\t\t\t\t" << char(200);
		for (int i = 0; i < 10; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;



		cout << "\n\t\t\t\t\t\t" << char(201);
		for (int i = 0; i < 25; i++) {
			cout << char(205);
		}
		cout << char(187) << endl;

		cout << GREEN << "\t\t\t\t\t\t  Username: " << RESET;
		cin >> username;
		cout << GREEN << "\n\t\t\t\t\t\t  Password: " << RESET;
		cin >> password;
		cout << "\t\t\t\t\t\t" << char(200);
		for (int i = 0; i < 25; i++) {
			cout << char(205);
		}
		cout << char(188) << endl;
		if (username == user1 && password == pass1) {
			system("cls");
			admin();
			attempts = 3;
		}
		else if (username == user2 && password == pass2) {
			system("cls");
			operation();
			attempts = 3;
		}
		else if (username == user3 && password == pass3) {
			employee();
			attempts = 3;
		}
		else {
			attempts--;
			cout << "\n\n\t\t\t\t\t\t" << RED << "Invalid" << RESET << " username or password!!" << endl;
			cout << "\n\t\t\t\t\t\t" << "You have " << RED << attempts << RESET << " Attempts remaining" << endl;
			if (attempts == 0) {
				cout << "\n\t\t\t\t\t\tYou have used all your attempts.\n";
				cout << "\t\t\t\t\t\tThe program " << RED << "BLOCKED\n" << RESET;
				exit(0);
			}
			do {
				cout << "\t\t\t\t\t\tEnter 1 to " << RED << "try Again" << RESET << " or 0 to " << RED << "Exit." << RESET << endl;
				cout << BLUE << "\t\t\t\t\t\t==> " << RESET;
				cin >> choice;
				if (choice == 1) {
					flag = true;
					system("cls");
				}
				else if (choice == 0) {
					exit(0);
				}
				else {
					cout << "\t\t\t\t\t\tPlease enter " << GREEN << "valid" << RESET << " number." << endl;
				}
			} while (choice != 1);

		}
	}
}

//This function is the start function and contains the welcome screen that appears when the program starts.
void start() {
	string start;
	cout << "\t\t\t\t\t\t" << CYAN << "=====================================" << RESET;
	cout << "\n\t\t\t\t\t\t" << BLUE << "Wellcome To The Task Managment System" << RESET << endl;
	cout << "\t\t\t\t\t\t" << CYAN << "=====================================" << RESET << endl;
	cout << "\n\n\t\t\t\t\t\tEnter (" << RED << "start" << RESET << ")" << " for go to login page : ";
	do {
		cin >> start;
		if (start == "start") {
			loginPage();
		}
		else {
			cout << "\n\t\t\t\t\t\tPlease enter (" << RED << "start" << ")" << RESET << " for go to login page : ";
		}
	} while (start != "start");
}


int main() {
	start();

	return 0;

}
