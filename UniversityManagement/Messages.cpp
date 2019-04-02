#include"stdafx.h"
#include "Messages.h"
//message from parent to teacher
int WriteMessageP2T(Parent* p)
{
	string temp, eon, id;
	ofstream myfile1, myfile2;
	system("CLS");
	eon = "<<<";
	cout << "Enter faculty's employee id number\n";
	getline(cin, id);
	getline(cin, id);
	cout << "Type <<< at the end in a new line to send message\n";
	string directory1, directory2;
	directory1 = CurrentDirectory();
	directory2 = CurrentDirectory();
	directory1 += "\\Messages";
	directory2 += "\\Messages";
	wstring x1 = s2ws(directory1);
	wstring x2 = s2ws(directory2);
	WCHAR * wx1 = &x1[0];
	WCHAR * wx2 = &x2[0];
	_wmkdir(wx1);
	directory1 += "\\ParentMessages";
	directory2 += "\\TeacherMessages";
	x1 = s2ws(directory1);
	x2 = s2ws(directory2);
	wx1 = &x1[0];
	wx2 = &x2[0];
	_wmkdir(wx1);
	_wmkdir(wx2);
	temp = id;
	temp += ".txt";			
	directory1 += "\\";					//parent messages
	directory1 += p->uid;
	directory1 += ".txt";
	//cout << directory1 << endl;
	directory2 += "\\";
	directory2 += temp;			//teacher messages
	//cout << directory2 << endl;
	myfile1.open(directory1, ios::out | ios::app);
	myfile2.open(directory2, ios::out | ios::app);
	if (myfile1.is_open() && myfile2.is_open())
	{
		//start the message entry with symbol <<<T to show teacher sent message
		myfile1 << "<<<P\n";
		myfile2 << "<<<P\n";
		myfile1 << "Message to " << id << endl;
		myfile2 << "Message from " << p->name << "'s (RegNo : " << p->uid << ") parent \n";
		myfile1 << GetTimeandDate();
		myfile2 << GetTimeandDate();
		while (1)
		{
			getline(cin, temp);
			if (!temp.compare(eon))
				break;
			else
			{
				myfile1 << temp << endl;
				myfile2 << temp << endl;
			}
		}
		myfile1.close();
		myfile2.close();
		return 1;
	}
	else
		return 0;
}

//message from teacher to parent
int WriteMessageT2P(Teacher* t)
{
	string temp, eon,id;
	ofstream myfile1,myfile2;
	system("CLS");
	eon = "<<<";
	cout << "Enter ward's registration number\n";
	getline(cin, id);
	getline(cin, id);
	cout << "Type <<< at the end in a new line to send message\n";
	string directory1,directory2;
	directory1 = CurrentDirectory();
	directory2 = CurrentDirectory();
	directory1 += "\\Messages";
	directory2 += "\\Messages";
	wstring x1 = s2ws(directory1);
	wstring x2 = s2ws(directory2);
	WCHAR * wx1 = &x1[0];
	WCHAR * wx2 = &x2[0];
	_wmkdir(wx1);
	directory1 += "\\ParentMessages";
	directory2 += "\\TeacherMessages";
	x1 = s2ws(directory1);
	x2 = s2ws(directory2);
	wx1 = &x1[0];
	wx2 = &x2[0];
	_wmkdir(wx1);
	_wmkdir(wx2);
	temp = id;
	temp += ".txt";			//teacher to parent messages(parent messages)
	directory1 += "\\";
	directory1 += temp;
	//cout << directory1 << endl;
	directory2 += "\\";
	directory2 += to_string(t->id);			//teacher messages
	directory2 += ".txt";
	//cout << directory2 << endl;
	myfile1.open(directory1, ios::out | ios::app);
	myfile2.open(directory2, ios::out | ios::app);
	if (myfile1.is_open() && myfile2.is_open())
	{
		//start the message entry with symbol <<<T to show teacher sent message
		myfile1 << "<<<T\n";
		myfile2 << "<<<T\n";
		myfile1 << "Message from " << t->name << " (ID : " << t->id << ")\n";
		myfile2 << "Message to " << id << "'s parent\n";
		myfile1 << GetTimeandDate();
		myfile2 << GetTimeandDate();
		while (1)
		{
			getline(cin, temp);
			if (!temp.compare(eon))
				break;
			else
			{
				myfile1 << temp << endl;
				myfile2 << temp << endl;
			}
		}
		myfile1.close();
		myfile2.close();
		return 1;
	}
	else
		return 0;
}

//message from teacher to student
int WriteMessageT2S(Teacher* t)
{
	string temp, eon, id;
	ofstream myfile1, myfile2;
	system("CLS");
	eon = "<<<";
	cout << "Enter ward's registration number\n";
	getline(cin, id);
	getline(cin, id);
	cout << "Type <<< at the end in a new line to send message\n";
	string directory1, directory2;
	directory1 = CurrentDirectory();
	directory2 = CurrentDirectory();
	directory1 += "\\Messages";
	directory2 += "\\Messages";
	wstring x1 = s2ws(directory1);
	wstring x2 = s2ws(directory2);
	WCHAR * wx1 = &x1[0];
	WCHAR * wx2 = &x2[0];
	_wmkdir(wx1);
	directory1 += "\\ParentMessages";
	directory2 += "\\StudentMessages";
	x1 = s2ws(directory1);
	x2 = s2ws(directory2);
	wx1 = &x1[0];
	wx2 = &x2[0];
	_wmkdir(wx1);
	_wmkdir(wx2);
	temp = id;
	temp += ".txt";			//teacher to parent messages(parent messages)
	directory1 += "\\";
	directory1 += temp;
	//cout << directory1 << endl;
	directory2 += "\\";
	directory2 += to_string(t->id);			//teacher messages
	directory2 += ".txt";
	//cout << directory2 << endl;
	myfile1.open(directory1, ios::out | ios::app);
	myfile2.open(directory2, ios::out | ios::app);
	if (myfile1.is_open() && myfile2.is_open())
	{
		//start the message entry with symbol <<<T to show teacher sent message
		myfile1 << "<<<T\n";
		myfile2 << "<<<T\n";
		myfile1 << "Message from " << t->name << " (ID : " << t->id << ")\n";
		myfile2 << "Message to " << id << "\n";
		myfile1 << GetTimeandDate();
		myfile2 << GetTimeandDate();
		while (1)
		{
			getline(cin, temp);
			if (!temp.compare(eon))
				break;
			else
			{
				myfile1 << temp << endl;
				myfile2 << temp << endl;
			}
		}
		myfile1.close();
		myfile2.close();
		return 1;
	}
	else
		return 0;
}

//read student messages
int ReadStudentMessages(Student* s)
{
	string temp, snc;
	snc = "<<<T";	//snc is start message character
	int n = 1, i;
	string directory;
	directory = CurrentDirectory();
	directory += "\\Messages";
	wstring x1 = s2ws(directory);
	WCHAR * wx1 = &x1[0];
	_wmkdir(wx1);
	directory += "\\StudentMessages";
	x1 = s2ws(directory);
	wx1 = &x1[0];
	_wmkdir(wx1);
	temp += s->regno;
	temp += ".txt";
	directory += "\\";					//parent messages
	directory += temp;
	ifstream myfile(directory);
	if (myfile.is_open())
	{
		system("CLS");
		SetColor(113);
		cout << "Your messages\n";
		SetColor(79);
		while (1)
		{
			getline(myfile, temp);
			if (myfile.eof())
				break;
			else if (!temp.compare(snc) && n % 2 == 1)
			{
				SetColor(252);
				n++;
				getline(myfile, temp);
			}
			else if (!temp.compare(snc) && n % 2 == 0)
			{
				SetColor(112);
				n++;
				getline(myfile, temp);
			}
			cout << temp;
			for (i = 0; i < 71; i++)
				cout << " ";
			cout << endl;
		}
		SetColor(79);
		return 1;
	}
	else
		return 0;
}

//read parent messages
int ReadParentMessages(Parent* p)
{
	string temp, snc,snc1;
	snc = "<<<T";	//snc is start message character
	snc1 = "<<<P";
	int n = 1, i;
	string directory;
	directory = CurrentDirectory();
	directory += "\\Messages";
	wstring x1 = s2ws(directory);
	WCHAR * wx1 = &x1[0];
	_wmkdir(wx1);
	directory += "\\ParentMessages";
	x1 = s2ws(directory);
	wx1 = &x1[0];
	_wmkdir(wx1);
	temp += p->uid;
	temp += ".txt";
	directory += "\\";					//parent messages
	directory += temp;
	ifstream myfile(directory);
	if (myfile.is_open())
	{
		system("CLS");
		SetColor(113);
		cout << "Your messages\n";
		SetColor(79);
		while (1)
		{
			getline(myfile, temp);
			if (myfile.eof())
				break;
			else if ((!temp.compare(snc) || !temp.compare(snc1)) && n % 2 == 1)
			{
				SetColor(252);
				n++;
				getline(myfile, temp);
			}
			else if ((!temp.compare(snc) || !temp.compare(snc1)) && n % 2 == 0)
			{
				SetColor(112);
				n++;
				getline(myfile, temp);
			}
			cout << temp;
			for (i = 0; i < 71; i++)
				cout << " ";
			cout << endl;
		}
		SetColor(79);
		return 1;
	}
	else
		return 0;
}

//read teacher messages
int ReadTeacherMessages(Teacher* t)
{
	string temp, snc, snc1;
	snc = "<<<T";	//snc is start message character
	snc1 = "<<<P";
	int n = 1, i;
	string directory;
	directory = CurrentDirectory();
	directory += "\\Messages";
	wstring x1 = s2ws(directory);
	WCHAR * wx1 = &x1[0];
	_wmkdir(wx1);
	directory += "\\TeacherMessages";
	x1 = s2ws(directory);
	wx1 = &x1[0];
	_wmkdir(wx1);
	temp += to_string(t->id);
	temp += ".txt";
	directory += "\\";					//parent messages
	directory += temp;
	ifstream myfile(directory);
	if (myfile.is_open())
	{
		system("CLS");
		SetColor(113);
		cout << "Your messages\n";
		SetColor(79);
		while (1)
		{
			getline(myfile, temp);
			if (myfile.eof())
				break;
			else if ((!temp.compare(snc) || !temp.compare(snc1)) && n % 2 == 1)
			{
				SetColor(252);
				n++;
				getline(myfile, temp);
			}
			else if ((!temp.compare(snc) || !temp.compare(snc1)) && n % 2 == 0)
			{
				SetColor(112);
				n++;
				getline(myfile, temp);
			}
			cout << temp;
			for (i = 0; i < 71; i++)
				cout << " ";
			cout << endl;
		}
		SetColor(79);
		return 1;
	}
	else
		return 0;
}


