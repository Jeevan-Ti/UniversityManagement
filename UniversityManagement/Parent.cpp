#include "stdafx.h"
#include "Parent.h"


Parent::Parent(string id)
{
	uid = id;
}


Parent::~Parent()
{
}

void Parent::getinfo(string str)
{
	system("CLS");
	cout << str;
	cout << "Your wards information\n";
	cout << "REGISTRATION    :      ";
	SetColor(78);
	cout << uid << endl;
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

int ParentSubRoutine(char ch, Parent* p)
{
	int i;			//to check return status

	/*cout << "\nTo see LPU news press S\n";
	cout << "To send a message to faculty press F\n";
	cout << "To see your messages press M\n";
	cout << "To logout press L\n";*/

	//to see news
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

	//if logout is pressed
	else if (ch == 'L' || ch == 'l')  
	{
		system("CLS");
		cout << "Sucessfully logged out\n";
		return 1;
	}

	//send message to faculty f
	else if (ch == 'F' || ch == 'f')
	{
		i = WriteMessageP2T(p);
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

	//see your messages
	else if (ch == 'M' || ch == 'm')
	{
		i = ReadParentMessages(p);
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