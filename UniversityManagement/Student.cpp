#include "stdafx.h"

Student::Student() 
{

}

Student::Student(string a)
{
	regno = a;
}

Student::~Student()
{
}

void Student::setinfo()
{
	getline(cin, c);
	password = EnterPassword("Enter password (Maximum 20 characters)\n");
	cout << "Enter name of the student\n";
	getline(cin,name);
	cout << "Enter father's name\n";
	getline(cin, fname);
	cout << "Enter mother's name\n";
	getline(cin, mname);
	cout << "Enter students's gender male/female/other\n";
	getline(cin,gender);
	cout << "Enter course studying\n";
	getline(cin,course);
	cout << "Enter joining batch\n";
	cin >> batch;
	cout << "Enter CGPA\n";
	cin >> cgpa;
	cout << "Enter any remarks\n";
	getline(cin, c);
	getline(cin,remarks);
	cout << "Enter attendance\n";
	cin >> attendance;
}

void Student::getinfo()
{
	system("CLS");
	cout << "Logged in as ";
	SetColor(74);
	cout << regno<<endl;
	SetColor(79);
	cout << "NAME            :      ";
	SetColor(78);
	cout << name << endl;
	SetColor(79);
	cout << "FATHER NAME  	:      ";
	SetColor(78);
	cout << fname << endl;
	SetColor(79);
	cout << "MOTHER NAME  	:      ";
	SetColor(78);
	cout << mname << endl;
	SetColor(79);
	cout << "GENDER          :      ";
	SetColor(78);
	cout << gender << endl;
	SetColor(79);
	cout << "BATCH           :      ";
	SetColor(78);
	cout << batch << endl;
	SetColor(79);
	cout << "COURSE          :      ";
	SetColor(78);
	cout << course << endl;
	SetColor(79);
	cout << "CGPA            :      ";
	SetColor(78);
	cout << cgpa << endl;
	SetColor(79);
	cout << "REMARKS         :      ";
	SetColor(78);
	cout << remarks << endl;
	SetColor(79);
	cout << "ATTENDANCE      :      ";
	SetColor(78);
	cout << attendance << "%" << endl;
	SetColor(79);
}

void Student::getinfo(string str)
{
	system("CLS");
	cout << str;
	cout << "REGISTRATION    :      ";
	SetColor(78);
	cout << regno << endl;
	SetColor(79);
	cout << "NAME            :      ";
	SetColor(78);
	cout << name << endl;
	SetColor(79);
	cout << "FATHER NAME  	:      ";
	SetColor(78);
	cout << fname << endl;
	SetColor(79);
	cout << "MOTHER NAME  	:      ";
	SetColor(78);
	cout << mname << endl;
	SetColor(79);
	cout << "GENDER          :      ";
	SetColor(78);
	cout << gender << endl;
	SetColor(79);
	cout << "BATCH           :      ";
	SetColor(78);
	cout << batch << endl;
	SetColor(79);
	cout << "COURSE          :      ";
	SetColor(78);
	cout << course << endl;
	SetColor(79);
	cout << "CGPA            :      ";
	SetColor(78);
	cout << cgpa << endl;
	SetColor(79);
	cout << "REMARKS         :      ";
	SetColor(78);
	cout << remarks << endl;
	SetColor(79);
	cout << "ATTENDANCE      :      ";
	SetColor(78);
	cout << attendance << "%" << endl;
	SetColor(79);
}

int NewEntry(char ch)
{
	if (ch == 'N' || ch == 'n')
	{
		int status;
		Display d("COLOR 4F");
		string pid = "P", regno;
		d.SetFontSize(25, "Arial");
		cout << "New student registration\n";
		cout << "Enter registration number of student\n";
		cin >> regno;
		Student s(regno);
		s.setinfo();
		status = WriteToFile(s);
		if (status == 1)
		{
			system("CLS");
			d.SetFontSize(35, "Arial");
			cout << "Registration Sucessful\n\n";
			cout << "Your login id is " ;
			SetColor(236);
			cout << s.regno << "\n\n";
			SetColor(79);
			cout << "Your password is ";
			SetColor(236);
			cout << s.password << "\n\n";
			SetColor(79);
			cout << "Your parent id is ";
			SetColor(236);
			pid += s.regno;
			cout << pid << "\n\n";
			SetColor(79);
			cout << "Your parent password is ";
			SetColor(236);
			cout << s.password << "\n\n";
			SetColor(79);
		}
		else
			cout << "Entry failed\n";
		return 1;
	}
	else if (ch == 'T' || ch == 't')
	{
		int id, status;
		cout << "New employee registration\n";
		cout << "Enter employee id\n";
		cin >> id;
		Teacher t(id);
		t.setinfo();
		status = WriteToFile(t);
		if (status == 1)
		{
			system("CLS");
			cout << "Registration Sucessful\n\n";
			cout << "Your login id is ";
			SetColor(236);
			cout << t.id << "\n\n";
			SetColor(79);
			cout << "Your password is ";
			SetColor(236);
			cout << t.password << "\n\n";
			SetColor(79);
		}
		else
			cout << "Entry failed\n";
		return 1;
	}
}

int SearchEntry(char ch)
{
	int i;
	//if student login
	if (ch == 'S' || ch == 's')		
	{
		int i;
		string password,regno;
		bool check = false;
		char ch = ' ';
		cout << "Student login\n";
		cout << "Enter registration number of student\n";
		cin >> regno;
		password = EnterPassword("Enter password\n");
		Student s(regno);
		Student *sptr = &s;
		while (check == false)
		{
			i = ReadFile(sptr, password);
			if (i == 1)
			{
				s.getinfo();
				displayBar(s.attendance);
				cout << "\nTo see LPU news press S\n";
				cout << "To see your messages press M\n";
				cout << "To logout press L\n";
				ch = _getch();
				if (StudentSubRoutine(ch,sptr))
					check = true;
			}
			else
				break;
		}
		return 1;
	}

	//if parent login
	else if (ch == 'P' || ch == 'p')		
	{
		string password,id;
		char ch = ' ';
		bool check = false;
		cout << "Parent login\n";
		cout << "Enter parent id\n";
		cin >> id;
		password = EnterPassword("Enter your password\n");
		Parent p(id);
		Parent *pptr = &p;
		while (check == false)
		{
			i = ReadFile(pptr, password);
			if (i == 1)
			{
				p.getinfo("Logged in as parent\n");
				displayBar(p.attendance);
				cout << "\nTo see LPU news press S\n";
				cout << "To send a message to a faculty press F\n";
				cout << "To see your messages press M\n";
				cout << "To logout press L\n";
				ch = _getch();
				if (ParentSubRoutine(ch,pptr))
					check = true;
			}
			else
				break;
		}
		return 1;
	}

	//if teacher login
	else if (ch == 'L' || ch == 'l')		
	{
		int id;
		string password;
		char ch = ' ';
		bool check = false;
		cout << "Teacher login\n";
		//cin >> id;
		cout << "Enter employee id\n";
		cin >> id;
		password = EnterPassword("Enter your password\n");
		Teacher t(id);
		Teacher *tptr = &t;
		while (check == false)
		{
			i = ReadFile(tptr,password);
			if (i == 1)
			{
				t.getinfo();
				cout << "\nTo see LPU news press S\n";
				cout << "To make a new news entry press N\n";
				cout << "To send a message to student press M\n";
				cout << "To send a message to parent press P\n";
				cout << "To see your messages press Y\n";
				cout << "To search for a student press D\n";
				cout << "To delete student entry enter E\n";
				cout << "To logout press L\n";
				ch = _getch();
				if (TeacherSubRoutine(ch,tptr))
					check = true;
			}
			else
				break;
		}
		return 1;
	}
}

int StudentSubRoutine(char ch,Student* s)
{
	int i;			//to check return status
	if (ch == 'S' || ch == 's')
	{
		i = ReadNews();
		if (i)
		{
			SetColor(159);
			cout << "End of news\n";
			SetColor(79);
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
		else
		{
			system("CLS");
			cout << "Unable to retrive news at the moment\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
	}

	//read messages
	else if (ch == 'M' || ch == 'm')
	{
		i = ReadStudentMessages(s);
		if (i)
		{
			SetColor(159);
			cout << "End of your messages\n";
			SetColor(79);
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
		else
		{
			system("CLS");
			cout << "Seems like you don't have any messages yet\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
	}

	//if logout is pressed
	else if (ch == 'L' || ch == 'l')  
	{
		system("CLS");
		cout << "Sucessfully logged out\n";
		return 1;
	}

	//invalid input
	else
	{
		system("CLS");
		cout << "Enter a valid input\n";
		cout << "Press any key to return to previous page\n";
		_getch();
		return 0;
	}
}