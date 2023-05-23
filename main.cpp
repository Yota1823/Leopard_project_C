#include "Student.h"
#include "Instructor.h" 
#include "Admin.h"
#include "User.h"

#include <iostream>
#include <string>


#define student 1
#define instructor 2
#define admin 3
#define exit 0

using std::cin;
using std::cout;
using std::string;
using std::endl;


int main() {
	string first_name; 
	string last_name;
	int choice;
	int ID; 
	string student_user;
	string instructor_user;
	string admin_user;
	int CRN;
	int select;
	string course_name;
while(1){
	//initial restaurant status
	User user("first name","last name",0);
			cout << "---------- What are you? ----------\n";
			cout << "Enter the following options:\n";
			cout << "1 - Student" << endl;
			cout << "2 - Instructor" << endl;
			cout << "3 - Admin" << endl;
			cout << "0 - Exit" << endl;
			cin >> choice;  

			// Student
			if (choice == 1) {
				cout << "What is your first name?\n";
				cin >> first_name;
				cout << "What is your last name?\n";
				cin >> last_name;
				cout << "What is your ID?\n";
				cin >> ID;
				Student* student_user = new Student(first_name, last_name, ID);
			while(1){
				cout << "---------What do you want to do?------------\n";
				cout << "Enter the following options:\n";
				cout << "1 - search course" << endl;
				cout << "2 - add course" << endl;
				cout << "3 - drop course" << endl;
				cout << "4 - display schedule" << endl;
				cout << "0 - Exit" << endl;

				cin >> select;
				if(select = 1){
					cout << "Enter the course number mame\n";
					cin >> course_name;

					student_user->search_course(course_name);
				}else if(select = 2){
					cout << "Enter the course CRN\n";
					cin >> CRN;
					student_user->add_course(CRN);
				}else if(select = 3){
					cout << "Enter the course CRN\n";
					cin >> CRN;
					student_user->drop_course(CRN);					
				}else if(select = 4){
					student_user->display_schedule();
				}else if(select = 0){
					break;
				}
			}
								

			}
			// Instructor
			else if (choice == 2) {
				cout << "What is your first name?\n";
				cin >> first_name;
				cout << "What is your last name?\n";
				cin >> last_name;
				cout << "What is your ID?\n";
				cin >> ID;
				Instructor* instructor_user = new Instructor(first_name, last_name, ID);
				while(1){
				cout << "---------What do you want to do?------------\n";
				cout << "Enter the following options:\n";
				cout << "1 - search course" << endl;
				cout << "2 - print schedule" << endl;
				cout << "3 - print class list" << endl;
				cout << "0 - exit" << endl;

				cin >> select;
				if(select = 1){
					cout << "Enter the course number mame\n";
					cin >> course_name;

					instructor_user->search_course();
				}else if(select = 2){
					cout << "Enter the course CRN\n";
					cin >> CRN;
					instructor_user->print_schedule();
				}else if(select = 3){
					cout << "Enter the course CRN\n";
					cin >> CRN;
					instructor_user->print_class_list();					
				}else if(select = 0){
					break;
				}
								
				}
			}
			// Admin
			else if (choice == 3) {
				cout << "What is your first name?\n";
				cin >> first_name;
				cout << "What is your last name?\n";
				cin >> last_name;
				cout << "What is your ID?\n";
				cin >> ID;
				Admin* admin_user = new Admin(first_name, last_name, ID);
				while(1){
				cout << "---------What do you want to do?------------\n";
				cout << "Enter the following options:\n";
				cout << "1 - search course" << endl;
				cout << "2 - add course in system" << endl;
				cout << "3 - remove course in system" << endl;
				cout << "4 - add user" << endl;
				cout << "5 - remove user" << endl;
				cout << "6 - add student" << endl;
				cout << "7 - remove student" << endl;
				cout << "8 - print roaster" << endl;
				cout << "0 - exit" << endl;

				cin >> select;
				if(select = 1){
					cout << "Enter the course number mame\n";
					cin >> course_name;

					admin_user->search_course();
				}else if(select = 2){
					admin_user->add_course_in_system();
					cout << "The class is added\n";
				}else if(select = 3){
					admin_user->remove_course_in_system();	
					cout << "The class is removed\n";				
				}else if(select = 4){
					admin_user->add_user();
					cout << "The user is added\n";	
				}else if(select = 5){
					admin_user->remove_user();
					cout << "The user is removed\n";	
				}else if(select = 6){
					admin_user->add_student();
					cout << "The student is add\n";
				}else if(select = 7){
					admin_user->remove_student();
					cout << "The student is removed\n";
				}else if(select = 8){
					cout << "Here is the roster\n";
					admin_user->print_roaster();
				}else if(select = 0){
					break;
				}		
				}																						
			}
			// Exit
			else if (choice == 0) {
				break;
			}
			// Invalid input
			else {
				cout << "Invalid selection" << endl;
			}
		

		

	cout << "\nExiting\n\n";
}
	return 0;
}