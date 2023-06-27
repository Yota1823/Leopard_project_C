#include "../inc/Student.h"
#include "../inc/Instructor.h" 
#include "../inc/Admin.h"
#include "../inc/User.h"

#include "sqlite3.h"

#include <iostream>
#include <string>
#include <stdio.h>



#define student 1
#define instructor 2
#define admin 3
#define exit 0

using std::cin;
using std::cout;
using std::string;
using std::endl;


/************************************************************************************************* 	
 The callback() function is invoked for each result row coming out of the evaluated SQL statement
 1st argument - the 4th argument provided by sqlite3_exec() and is typically not used
 2nd argument - number of columns in the result
 3rd argument - an array of strings containing the fields in that row
 4th argument - an array of strings containing the names of the columns
*************************************************************************************************/
static int callback(void* data, int argc, char** argv, char** azColName) 
{ 				
	int i; 
   
    	for (i = 0; i < argc; i++) 
		{ 
        	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    	} 
  
    	printf("\n"); 
    	
		return 0; 
}

int main(int argc, char** argv) {
	sqlite3* DB; 

	int ID; 
	string first_name; 
	string last_name;
	string grad_year;
	char major;
	string email;

	int CRN;
	int choice;
	string student_user;
	string instructor_user;
	string admin_user;
	int select;
	string course_name;

	string title;
	string department;
	int time;
	int dotw;
	string semester;
	int credit;

	/*******************************************************************	
	 Creating a table
	 Create a string then pass the string into the sqlite3_exec function
	********************************************************************/
    string table = "CREATE TABLE COURSES("
                   "CRN INTEGER PRIMARY KEY, "
                   "TITLE TEXT NOT NULL, "
                   "DEPARTMENT TEXT NOT NULL, "
                   "TIME INTEGER NOT NULL, "
				   "DOTW TEXT NOT NULL," 
				   "SEMSTER TEXT NOT NULL, " // DID TEXT TO HAVE SUMMER SPRING FAL
				   "YEAR TEXT NOT NULL,"
				   "CREDITS INTEGER NOT NULL);";
    	
	int exit = 0;
		
    exit = sqlite3_open("database/assignment3.db.db", &DB);			//open the database
		
	char* messageError; 
	
	// execute the create table command
	// sqlite3_exec( pointer to database file, string for sql command, callback function (used to respond to queries, not used here), input to callback, error message address)
    exit = sqlite3_exec(DB, table.c_str(), NULL, 0, &messageError); 
  
   	if (exit != SQLITE_OK) 
	{ 
        std::cerr << "Error Create Table" << std::endl; 
       	sqlite3_free(messageError); 
    } 
    else
        cout << "Table created Successfully" << std::endl; 

	/*******************************************************************
	 Inserting values into a table.
	 Create a string then pass the string into the sqlite3_exec function
	********************************************************************/
	// hard-code (push) a few values into the database - NOTE you can create a single string with multiple INSERT commands
    string sql("INSERT INTO COURSES VALUES(123, 'PROGRAMMING', 'ELECTRICAL', 1230, 'MONDAY', 'SUMMER', 'JUNIOR', 3 );"
        "INSERT INTO COURSES VALUES(132, 'SIGNALS', 'ELECTRICAL', 200, 'TUESDAY', 'SPRING', 'SENIOR', 4 );"
        "INSERT INTO COURSES VALUES(321, 'NETWORKS', 'ELECTRICAL', 100, 'WEDNESDAY', 'FALL', 'FRESHMAN', 4);"
        "INSERT INTO COURSES VALUES(322, 'MULTIVARIABLE', 'MATH', 330, 'THURSDAY', ' FALL', 'SENIOR', 4);"
        "INSERT INTO COURSES VALUES(113, 'ETHICS', 'HSS', 800, 'FRIDAY', 'SPRING', 'FRESHMAN', 3 );"
        "INSERT INTO COURSES VALUES(121, 'ECOMONY', 'MATH' , 500, 'MONDAY', 'SUMMER', 'JUNIOR', 3);"
        "INSTERT INTO COURSES VALUES(332, 'ENGLISH', 'ENGLISH', 330, 'TUESDAY', 'FALL', 'SOPHMORE', 3;)" // SEMI COLON IN PARENTH

    );

	// execute the command
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) 
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messageError);
	}
	else
		std::cout << "Records created Successfully!" << std::endl;

	/***********************************************
	 print all data in the table with SELECT * FROM
	 create string with query then execute
	 **********************************************/
	string query = "SELECT * FROM STUDENT;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

 	cout << "Adding two new students\n";
	
	for(int i = 0; i < 1; i++){
	cout << endl << "Enter the ID, first name, last name, grad year, major, email separated by spaces: ";
	cin >> ID >> fname >> lname >> grad_year >> major >> email;
	cout << endl;

	// Adding from a file or a user input means some string additions (see below)
	string UID = "6";
	string userInput("INSERT INTO STUDENT VALUES(" + ID + "','" + fname + " ',' " + lname + " ',' " + grad_year + " ',' " + major + " ',' " + email + ");");

	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);
	}

 	cout << "Remove one instructor\n";
	
	query = DELETE FROM INSTRUCTOR WHERE condition ID = 20001;
	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);
	cout << "Succesfully, the instructor is removed\n";

	cout << "Update an admin to Vice president\n";

	query = query.exec("UPDATE ADMIN SET TITLE = "Vice-president" WHERE id = 30002");
	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);
	cout << "Succesfully, the admin is updated to Vice president\n";


	/***********************************
	 refining queries --> SELECT example
	 create string --> call command
	***********************************/
	string surname = "SELECT SURNAME FROM COURSES WHERE BIRTHYEAR < 1950;";
	cout << endl << "SQL Command: " << surname << endl;

	exit = sqlite3_exec(DB, surname.c_str(), callback, NULL, &messageError);
	
	query = "SELECT * FROM COURSES;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);


	// other possible commands from SQL (update, delete, etc.), try those. Same concept, create string then call command

	sqlite3_close(DB); 


while(1){
	//initial status
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