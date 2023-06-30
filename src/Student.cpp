#include "Student.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;


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
    return "";
}
void Student::add_course(int in_CRN){
    cout << "This course was added\n";
}
void Student::drop_course(int in_CRN){
    cout << "This course was dropped\n";
}
string Student::display_schedule(){
    return "";
}

//destreuctor (delete)
Student::~Student(){

}