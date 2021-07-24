#include "stdafx.h"
#include "File.h"

using namespace std;
//using namespace std::experimental::filesystem;
bool checkr = false;
File::File()
{
}

File::~File()
{
}

int WriteToFile(Student s)
{
	ofstream myfile;
	string directory;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Student.csv";
	myfile.open(directory, ios::out | ios::app);
	if (myfile.is_open())
	{
		myfile << s.regno << ',';
		myfile << s.password << ',';
		myfile << s.name << ',';
		myfile << s.gender << ',';
		myfile << s.batch << ',';
		myfile << s.course << ',';
		myfile << s.cgpa << ',';
		myfile << s.remarks<<',';
		myfile << s.attendance << ',';
		myfile << s.fname << ',';
		myfile << s.mname << endl;
		myfile.close();
		return 1;
	}
	else
	return 0;
}

int WriteToFile(Teacher t)
{
	ofstream myfile;
	string directory;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Teacher.csv";
	myfile.open(directory, ios::out | ios::app);
	if (myfile.is_open())
	{
		myfile << t.id << ',';
		myfile << t.password << ',';
		myfile << t.name << ',';
		myfile << t.gender << ',';
		myfile << t.joiningyear << ',';
		myfile << t.department << endl;
		myfile.close();
		return 1;
	}
	else
		return 0;
}

string SearchFile(const string key,const string file)
{
	string line, temp, check;
	char ch = ' ';
	bool  flag = false;
	int i;
	check = key;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		checkr = true;
		while (flag == false)
		{
			getline(myfile, line);
			i = 0;
			while (ch != ',')
			{
				if (myfile.eof())
					break;
				ch = line[i];
				if (ch != ',')
					temp += ch;
				else if (ch == ',')
				{
					ch = ' ';
					break;
				}
				i++;
			}
			if (!check.compare(temp) || myfile.eof())
			{
				if (check.compare(temp) && myfile.eof())
				{
					system("CLS");
					checkr = false;
					cout << "Entry not found" << endl;
				}
				flag = true;
			}
			temp = "";
		}
		myfile.close();
	}
	else
	{
		system("CLS");
		checkr = false;
		cout << "Unable to open database" << endl;
	}
	return line;
}

float str2float(std::string s)
{
	float number;
	std::stringstream ss;
	ss << s;
	ss >> number;
	return number;
}

int str2int(string s)
{
	int n;
	stringstream ss;
	ss << s;
	ss >> n;
	return n;
}

int ReadFile(Student* s,string password)
{
	string result,temp,pass,directory;
	char ch = ' ';
	int i = 0,index = 0;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Student.csv";
	pass = password;	//enter password to login
	result = SearchFile(s->regno,directory);
	if (checkr == true)
	{
		for (i = 0; i < result.size(); i++)
		{
			ch = result[i];
			if (ch != ',')
				temp += ch;
			else if (ch == ',')
			{
				index++;
				if (index == 2)
				{
					s->password = temp;
					if (pass.compare(temp))
					{
						cout << "Wrong password\n";
						return 0;
					}
				}
				else if (index == 3)
					s->name = temp;
				else if (index == 4)
					s->gender = temp;
				else if (index == 5)
					s->batch = str2int(temp);
				else if (index == 6)
					s->course = temp;
				else if (index == 7)
					s->cgpa = str2float(temp);
				else if (index == 8)
					s->remarks = temp;
				else if (index == 9)
					s->attendance = str2float(temp);
				else if (index == 10)
					s->fname = temp;
				ch = ' ';
				temp = "";
			}
			if (i == result.size() - 1)
				s->mname = temp;
		}		//print read results from file

		return 1;				//return 1 if sucessfull read
	}
	else
	{
		//cout << "Unkown error occured or entry not found" << endl;
		return 0;
	}
}

int ReadFile(Teacher* t,string password)
{
	string result, temp,pass,directory;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Teacher.csv";
	char ch = ' ';
	int i = 0, index = 0;
	pass = password;  //enter password to login
	result = SearchFile(to_string(t->id), directory);
	if (checkr == true)
	{
		for (i = 0; i < result.size(); i++)
		{
			ch = result[i];
			if (ch != ',')
				temp += ch;
			else if (ch == ',')
			{
				index++;

				if (index == 2)
				{
					t->password = temp;
					if (pass.compare(temp))
					{
						cout << "Wrong password\n";
						return 0;
					}
				}
				else if (index == 3)
					t->name = temp;
				else if (index == 4)
					t->gender = temp;
				else if (index == 5)
					t->joiningyear = temp;

				ch = ' ';
				temp = "";
			}
			if (i == result.size() - 1)
				t->department = temp;
		}		//print read results from file
		
		return 1;		//return 1 if sucessfullly read
	}
	else
	{
		//cout << "Unkown error occured or entry not found" << endl;
		return 0;
	}
}

int ReadFile(Parent* p, string password)
{
	string result, temp, pass,directory;
	char ch = ' ';
	int i = 0, index = 0;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Student.csv";
	pass = password;	//enter password to login
	temp = p->uid;
	/*for (i = 0; i < sizeof(p->uid) - 1; i++)
	{
		temp[i] = p->uid[i + 1];
	}*/
	result = SearchFile(temp, directory);
	if (checkr == true)
	{
		for (i = 0; i < result.size(); i++)
		{
			ch = result[i];
			if (ch != ',')
				temp += ch;
			else if (ch == ',')
			{
				index++;
				if (index == 2)
				{
					p->password = temp;
					if (pass.compare(temp))
					{
						cout << "Wrong password\n";
						return 0;
					}
				}
				else if (index == 3)
					p->name = temp;
				else if (index == 4)
					p->gender = temp;
				else if (index == 5)
					p->batch = str2int(temp);
				else if (index == 6)
					p->course = temp;
				else if (index == 7)
					p->cgpa = str2float(temp);
				else if (index == 8)
					p->remarks = temp;
				else if (index == 9)
					p->attendance = str2float(temp);
				else if (index == 10)
					p->fname = temp;
				ch = ' ';
				temp = "";
			}
			if (i == result.size() - 1)
				p->mname = temp;
		}		//print read results from file

		return 1;				//return 1 if sucessfull read
	}
	else
	{
		//cout << "Unkown error occured or entry not found" << endl;
		return 0;
	}
}

int ReadFile(Student* s)
{
	string result, temp, pass, directory;
	char ch = ' ';
	int i = 0, index = 0;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Student.csv";
	//pass = password;	//enter password to login
	result = SearchFile(s->regno, directory);
	if (checkr == true)
	{
		for (i = 0; i < result.size(); i++)
		{
			ch = result[i];
			if (ch != ',')
				temp += ch;
			else if (ch == ',')
			{
				index++;
				if (index == 2)
				{
					s->password = temp;
				}
				else if (index == 3)
					s->name = temp;
				else if (index == 4)
					s->gender = temp;
				else if (index == 5)
					s->batch = str2int(temp);
				else if (index == 6)
					s->course = temp;
				else if (index == 7)
					s->cgpa = str2float(temp);
				else if (index == 8)
					s->remarks = temp;
				else if (index == 9)
					s->attendance = str2float(temp);
				else if (index == 10)
					s->fname = temp;
				ch = ' ';
				temp = "";
			}
			if (i == result.size() - 1)
				s->mname = temp;
		}		//print read results from file

		return 1;				//return 1 if sucessfull read
	}
	else
	{
		//cout << "Unkown error occured or entry not found" << endl;
		return 0;
	}
}

string CurrentDirectory()
{
	std::experimental::filesystem::v1::path cwd =
		std::experimental::filesystem::v1::current_path();

	return cwd.u8string();
}

wstring s2ws(const string& s)
{
	return std::wstring(s.begin(), s.end());
}

int DeleteEntry(const string key, const string directory)
{
	int i;
	ifstream ifile;
	ofstream ofile;
	string line, temp;
	char ch = ' ';
	const char* d;
	d = &directory[0];
	ifile.open(d, ios::in);
	ofile.open("temp.txt", ios::out);
	if (ifile.is_open() && ofile.is_open())
	{
		while (1)
		{
			//cout<<"Openeinf\n";
			getline(ifile, line);
			i = 0;
			//gives the first key
			while (ch != ',')
			{
				if (ifile.eof())
					break;
				ch = line[i];
				if (ch != ',')
					temp += ch;
				else if (ch == ',')
				{
					ch = ' ';
					break;
				}
				i++;
			}
			if (temp.compare(key))
				ofile << line << endl;
			if (ifile.eof())
				break;
			temp = "";
		}
		ifile.close();
		ofile.close();
		ifile.open("temp.txt", ios::in);
		ofile.open(d, ios::out);
		if (ifile.is_open() && ofile.is_open())
		{
			while (1)
			{
				getline(ifile, line);
				//cout<<"re\n";
				ofile << line << endl;
				if (ifile.eof())
					break;
			}
			ofile.close();
			ifile.close();
			remove("temp.txt");
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

string StudentDirectory()
{
	string directory;
	directory = CurrentDirectory();
	directory += "\\LoginData";
	wstring x = s2ws(directory);
	WCHAR * wx = &x[0];
	_wmkdir(wx);
	directory += "\\Student.csv";
	return directory;
}
