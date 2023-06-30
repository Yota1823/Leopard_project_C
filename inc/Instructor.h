#include<string>
#include "User.h"

using std::string;


class Instructor:
	public User
{
protected:
	//attritude (data)
	string CRN;
	string course_name;


public:
	//constructor (initial value)
	Instructor();
	Instructor(string in_first_name, string in_last_name);
	Instructor(string in_first_name, string in_last_name, int in_ID);

	//method
    string search_course(string in_course_name);
    string print_schedule();
    string print_class_list();

	//destreuctor (delete)
	~Instructor();

};