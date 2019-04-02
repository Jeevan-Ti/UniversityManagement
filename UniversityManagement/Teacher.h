#pragma once
#include<string>
using namespace std;
class Teacher
{
public:
	int id;
	string gender, department, name, joiningyear, c, password;
	Teacher(int k);
	virtual ~Teacher();
	void setinfo();
	void getinfo();
};

int TeacherSubRoutine(char ch, Teacher* t);


