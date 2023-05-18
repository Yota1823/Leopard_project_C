#include<string>
#include "User.h"


using std::string;


class Student:
	public User
{
protected:
	//attritude (data)
	string CRN;
	string course_name;


public:
	//constructor (initial value)
	Student();
	Student(string in_first_name, string in_last_name);
	Student(string in_first_name, string in_last_name, int in_ID);

	//method
    string search_course(string in_course_name);
    void add_course(int in_CRN);
    void drop_course(int in_CRN);
    string display_schedule();

	//destreuctor (delete)
	~Student();

};