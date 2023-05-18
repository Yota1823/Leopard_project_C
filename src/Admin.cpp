#include "Admin.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;

string name;
string first_name;
string last_name;
int ID;

	//constructor (initial value)
	Admin::Admin(){
        name = "N/A";
    }
	Admin::Admin(string in_first_name, string in_last_name){
        first_name = in_first_name;
        last_name = in_last_name;
    }
	Admin::Admin(string in_first_name, string in_last_name, int in_ID){
        first_name = in_first_name;
        last_name = in_last_name;
        ID = in_ID;
    }


	//method
    string Admin::search_course(string in_course_name){
        return 0;
    }
    void Admin::add_course_in_system();{
        
    }
    void Admin::remove_course_in_system(){

    }
    void Admin::add_user(){

    }
    void Admin::remove_user(){

    }
    void Admin::add_student(){

    }
    void Admin::remove_student(){

    }
    string Admin::print_roaster(){

    }

	//destreuctor (delete)
	Admin::~Admin(){

    }