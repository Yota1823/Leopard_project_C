#include "Student.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;

int 
	//constructor (initial value)
	Student(){
        name = "None"
    }
	Student(string in_first_name, string in_last_name){
        first_name = in_first_name;
        last_name = in_last_name;
    }
	Student(string in_first_name, string in_last_name, int in_ID);

	//method
    string search_course(string in_course_name);
    void add_course(int in_CRN);
    void drop_course(int in_CRN);
    string display_schedule();

	//destreuctor (delete)
	~Student();