#pragma once
class Parent:public Student
{
public:
	Parent(string id);
	virtual ~Parent();
	string uid;
	void getinfo(string str);
};

int ParentSubRoutine(char ch,Parent* p);

