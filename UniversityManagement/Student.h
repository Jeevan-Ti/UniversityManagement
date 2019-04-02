#include<string>
#pragma once
using namespace std;
class Student
{
public:
	int batch;
	float cgpa,attendance;
	string gender, course, name, remarks,c,password, regno;
	string mname, fname;
	Student();
	Student(string a);
	virtual ~Student();
	void setinfo();
	void getinfo();
	void getinfo(string str);
};

int NewEntry(char ch);
int SearchEntry(char ch);
int StudentSubRoutine(char ch,Student* s);

