#include<string>

using std::string;


class User
{
public:
	//attritude (data)
	string first_name;
	string last_name;
    int ID;



	//constructor (initial value)
	User();
	User(string in_first_name, string in_last_name);
	User(string in_first_name, string in_last_name, int in_ID);

	//method
	string show_name();


	//destreuctor (delete)
	~User();

};