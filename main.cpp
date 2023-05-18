#include <iostream>
#include <string>

#include "Student.h"  
#include "Instructor.h"  
#include "Admin.h"  
#include "User.h" 

using std::cin;
using std::cout;
using std::string;
using std::endl;


int main() {
	int food; // change 
	int owner; // change 
	int amount = 0; // Change 

	
			cout << "---------- What are you? ----------\n";
			cout << "Enter the following options:\n";
			cout << "1 - Student" << endl;
			cout << "2 - Instructor" << endl;
			cout << "3 - Admin" << endl;
			cout << "0 - Exit" << endl;
			cin >> owner; // change 

			// Student
			if (owner == 1) {
				
			}
			// Instructor
			else if (owner == 2) {
				
			}
			// Admin
			else if (owner == 3) {
				
			}
			// Exit
			else if (owner == 0) {
				break;
			}
			// Invalid input
			else {
				cout << "Invalid selection" << endl;
			}
		

		

	cout << "\nExiting\n\n";

	return 0;
}