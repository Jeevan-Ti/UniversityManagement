#include "stdafx.h"
#include "Teacher.h"
using namespace std;

Teacher::Teacher(int k)
{
	id = k;
}


Teacher::~Teacher()
{
}

void Teacher::setinfo()
{
	getline(cin, c);
	password = EnterPassword("Enter password (Maximum 20 characters)\n");
	cout << "Enter teacher name\n";
	getline(cin, name);
	cout << "Enter gender male/female/other\n";
	getline(cin, gender);
	cout << "Enter joining year\n";
	cin >> joiningyear;
	cout << "Enter your department\n";
	getline(cin, c);
	getline(cin, department);

}

void Teacher::getinfo()
{
	system("CLS");
	cout << "Logged in as ";
	SetColor(74);
	cout << id << endl;
	SetColor(79);
	cout << "NAME  	       	";
	SetColor(78);
	cout << name << endl;
	SetColor(79);
	cout << "DEPARTMENT	" ;
	SetColor(78);
	cout << department << endl;
	SetColor(79);
	cout << "GENDER	        " ;
	SetColor(78);
	cout << gender << endl;
	SetColor(79);
	cout << "YEAR JOINED    	" ;
	SetColor(78);
	cout << joiningyear << endl;
	SetColor(79);
}

int TeacherSubRoutine(char ch,Teacher* t)
{
	/*cout << "To see LPU news press S\n";
	cout << "To make a new news entry press N\n";
	cout << "To send message to student press M\n";
	cout << "To send message to parent press P\n";
	cout << "To see your messages press Y\n";
	cout << "To see student details press D\n";
	cout << "To logout press L\n";*/
	int i;			//to check return status

	//new news entry
	if (ch == 'N' || ch == 'n')          
	{
		i = EnterNews();
		if (i)
		{
			cout << "News sucessfully entered\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
		else
		{
			system("CLS");
			cout << "Failed to enter News\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
	}

	//Read news
	else if (ch == 'S' || ch == 's')
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

	//search for stuednt
	else if (ch == 'D' || ch == 'd')
	{
		system("CLS");
		string regno;
		cout << "Enter registration number of student\n";
		cin >> regno;
		Student s(regno);
		Student *sptr = &s;
		i = ReadFile(sptr);
		if (i == 1)
		{
			s.getinfo("Student information\n");
			displayBar(s.attendance);
			cout << "Press any key to return to previous page\n";
			_getch();
		}
		else
		{
			cout << "Press any key to return to main page\n";
			_getch();
		}
		return 0;
	}

	//if logout is pressed

	else if (ch == 'L' || ch == 'l')  
	{
		system("CLS");
		cout << "Sucessfully logged out\n";
		return 1;
	}

	//message to parent
	else if (ch == 'P' || ch == 'p')
	{
		i = WriteMessageT2P(t);
		if (i)
		{
			cout << "Message sucessfully sent\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
		else
		{
			//system("CLS");
			cout << "Failed to send message\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
	}

	//message to student
	else if (ch == 'M' || ch == 'm')
	{
		i = WriteMessageT2S(t);
		if (i)
		{
			cout << "Message sucessfully sent\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
		else
		{
			//system("CLS");
			cout << "Failed to send message\n";
			cout << "Press any key to return to previous page\n";
			_getch();
			return 0;
		}
	}

	//your messages
	else if (ch == 'Y' || ch == 'y')
	{
		i = ReadTeacherMessages(t);
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
