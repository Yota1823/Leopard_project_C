#include <iostream> 
#include <sqlite3.h>
#include <string> 
#include <stdio.h>
  
using namespace std; 
  
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


int main(int argc, char** argv) 
{ 
    sqlite3* DB; 
    	
	/*******************************************************************	
	 Creating a table
	 Create a string then pass the string into the sqlite3_exec function
	********************************************************************/
    string table = "CREATE TABLE PROGRAMMER("
                   "CRN INTEGER PRIMARY KEY, "
                   "TITLE TEXT NOT NULL, "
                   "DEPARTMENT TEXT NOT NULL, "
                   "TIME INTEGER NOT NULL, "
				   "DOTW TEXT NOT NULL," 
				   "SEMSTER TEXT NOT NULL, " // DID TEXT TO HAVE SUMMER SPRING FAL
				   "YEAR INTEGER NOT NULL,"
				   "CREDITS INTEGER NOT NULL);";
    	
	int exit = 0;
		
    exit = sqlite3_open("programmer.db", &DB);			//open the database
		
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
    string sql("INSERT INTO PROGRAMMER VALUES(123, 'PROGRAMMING', 'ELECTRICAL', 1230, 'MONDAY', 'SUMMER', 3 );"
        "INSERT INTO PROGRAMMER VALUES(132, 'SIGNALS', 'ELECTRICAL', 200, 'TUESDAY', 'SPRING', 4 );"
        "INSERT INTO PROGRAMMER VALUES(321, 'NETWORKS', 'ELECTRICAL', 100, 'WEDNESDAY', 'FALL', 4);"
        "INSERT INTO PROGRAMMER VALUES(322, 'MULTIVARIABLE', 'MATH', 330, 'THURSDAY', ' FALL', 4);"
        "INSERT INTO PROGRAMMER VALUES(113, 'ETHICS', 'HSS', 800, 'FRIDAY', 'SPRING', 3 );"
        "INSERT INTO PROGRAMMER VALUES(121, 'ECOMONY', 'MATH' , 500, 'MONDAY', 'SUMMER', 3);"
        "INSTERT INTO PROGRAMMER VALUES(332, 'ENGLISH', 'ENGLISH', 330, 'TUESDAY', 'FALL', 3;)" // SEMI COLON IN PARENTH

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
	string query = "SELECT * FROM PROGRAMMER;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);



	/**********************************************
	 adding from a file or user input
	 get input --> create string --> call command
	**********************************************/
	string fname, lname; 
	string year;			//year is an integer in the database table, but we beed to create a string to pass in to the sql command
	int CRN;
	string title;
	string department;
	int time;
	int dotw;
	string semester;
	int year;
	int credit;

	cout << endl << "Enter the first name, last name, and birth year of a famous programmer separated by spaces: ";
	cin >> fname >> lname >> year;
	cout << endl;

	// Adding from a file or a user input means some string additions (see below)
	string UID = "6";
	string userInput("INSERT INTO PROGRAMMER VALUES(" + UID + ",'" + fname + "','" + lname + "'," + year + ");");

	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);



	/***********************************
	 refining queries --> SELECT example
	 create string --> call command
	***********************************/
	string surname = "SELECT SURNAME FROM PROGRAMMER WHERE BIRTHYEAR < 1950;";
	cout << endl << "SQL Command: " << surname << endl;

	exit = sqlite3_exec(DB, surname.c_str(), callback, NULL, &messageError);
	
	query = "SELECT * FROM PROGRAMMER;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

	
	// other possible commands from SQL (update, delete, etc.), try those. Same concept, create string then call command

	sqlite3_close(DB); 
   	return 0; 
}
    
    