#include<string>
#include "User.h"

using std::string;


class Admin:
	public User
{
protected:
	//attritude (data)
	string CRN;
	string course_name;


public:
	//constructor (initial value)
	Admin();
	Admin(string in_first_name, string in_last_name);
	Admin(string in_first_name, string in_last_name, int in_ID);

	//method
    string search_course();
    void add_course_in_system();
    void remove_course_in_system();
    void add_user();
    void remove_user();
    void add_student();
    void remove_student();
    string print_roaster();



	//destreuctor (delete)
	~Admin();

};