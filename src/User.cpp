#include "User.h"
#include <iostream>
#include <string>


using std::string;
using std::cout;
int User::ID = 0;
std::string User::name;
std::string User::first_name;
std::string User::last_name;


User::User(){

}
User::User(string in_first_name, string in_last_name){
    first_name = in_first_name;
    last_name = in_last_name;
}
	User::User(string in_first_name, string in_last_name, int in_ID){
    first_name = in_first_name;
    last_name = in_last_name;
    ID = in_ID;        
}

//method
string User::show_name(){
	return first_name + " " + last_name;
}


//destreuctor (delete)
User::~User(){

}