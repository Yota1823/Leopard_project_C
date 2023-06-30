#include "Admin.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;


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
void Admin::add_course_in_system(string in_course_name){
    cout << "This course was added\n";
}
void Admin::remove_course_in_system(){
    cout << "This course was removed\n";
}
void Admin::add_user(){
    cout << "This user was added\n";
}
void Admin::remove_user(){
    cout << "This user was removed\n";
}
void Admin::add_student(){
    cout << "This student was added\n";
}
void Admin::remove_student(){
    cout << "This student was removed\n";
}
string Admin::print_roaster(){
    return "";
}

//destreuctor (delete)
Admin::~Admin(){

}