#include "Student.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;

string name;
string first_name;
string last_name;
int ID;

	//constructor (initial value)
	Student::Student(){
        name = "N/A";
    }
	Student::Student(string in_first_name, string in_last_name){
        first_name = in_first_name;
        last_name = in_last_name;
    }
	Student::Student(string in_first_name, string in_last_name, int in_ID){
        first_name = in_first_name;
        last_name = in_last_name;
        ID = in_ID;
    }


	//method
    string Student::search_course(string in_course_name){
        return 0;
    }
    void Student::add_course(int in_CRN){
        
    }
    void Student::drop_course(int in_CRN){

    }
    string Student::display_schedule(){

    }

	//destreuctor (delete)
	Student::~Student(){

    }