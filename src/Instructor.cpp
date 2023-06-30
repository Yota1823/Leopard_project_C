#include "Instructor.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;


	//constructor (initial value)
	Instructor::Instructor(){
        name = "N/A";
    }
	Instructor::Instructor(string in_first_name, string in_last_name){
        first_name = in_first_name;
        last_name = in_last_name;
    }
	Instructor::Instructor(string in_first_name, string in_last_name, int in_ID){
        first_name = in_first_name;
        last_name = in_last_name;
        ID = in_ID;
    }


	//method
    string Instructor::search_course(string in_course_name){
        return "";
    }
    string Instructor::print_schedule(){
        return "";
    }
    string Instructor::print_class_list(){
        return "";
    }

	//destreuctor (delete)
	Instructor::~Instructor(){

    }