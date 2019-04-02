#pragma once

class File
{
public:
	File();
	virtual ~File();
};

int WriteToFile(Student s);
int WriteToFile(Teacher t);

int ReadFile(Student* s,string password);
int ReadFile(Teacher* t, string password);
int ReadFile(Parent* p, string password);
int ReadFile(Student* s);
string SearchFile(const string key, const string file);
float str2float(string s);
int str2int(string s);
string CurrentDirectory();
wstring s2ws(const string& s);