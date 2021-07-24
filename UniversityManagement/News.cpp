#include "stdafx.h"
#include "News.h"
#define _CRT_SECURE_NO_WARNINGS

int EnterNews()
{
	string temp,eon;
	ofstream myfile;
	eon = "<<<";
	system("CLS");
	cout << "Enter news\n";
	cout << "Type <<< at the end in a new line to complete news entry\n";
	string directory;
	directory = CurrentDirectory();
	directory += "\\News";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\News.txt";
	myfile.open(directory, ios::out | ios::app);
	if (myfile.is_open())
	{
		//start the news entry with symbol <<<
		myfile << "<<<\n";     
		myfile << GetTimeandDate();
		while (1)
		{
			getline(cin, temp);
			if (!temp.compare(eon))
				break;
			else
				myfile << temp << endl;
		}
		myfile.close();
		return 1;
	}
	else
		return 0;
}

int ReadNews()
{
	string temp,snc;
	snc = "<<<";	//snc is start news character
	int n = 1,i;
	string directory;
	directory = CurrentDirectory();
	directory += "\\News";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\News.txt";
	ifstream myfile(directory);
	if (myfile.is_open())
	{
		system("CLS");
		SetColor(113);
		cout << "LPU News\n";
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

string GetTimeandDate()
{
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);
	return asctime(ti);
}