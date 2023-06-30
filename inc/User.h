#pragma once
#include<string>

using std::string;


class User
{
public:
	//attritude (data)
    static int ID;
    static std::string name;
    static std::string first_name;
    static std::string last_name;



	//constructor (initial value)
	User();
	User(std::string in_first_name, std::string in_last_name);
	User(std::string in_first_name, std::string in_last_name, int in_ID);

	//method
	string show_name();


	//destreuctor (delete)
	~User();

};