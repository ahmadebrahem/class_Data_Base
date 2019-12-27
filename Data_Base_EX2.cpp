#include "pch.h"
#include <iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

struct Date
{
	unsigned short int year;
	unsigned short int month;
	unsigned short int day;
};

struct Student
{
	string Firstname;
	string Lastname;
	unsigned long long int ID;
	Date birthday;
	float Grade;
};

struct Class
{
	string Classname;
	//float Average;
	unsigned short int capacity;
	vector <Student> Data;
};

vector<Class> Database;
Class c;

void selectclass(string cls)//make the global object the used object 
{
	for (auto i : Database)
		if (i.Classname == cls)
		{
			c = i;
		}
}

Student Add_Stuent(string _data)
{
	//spleit student data string to fname , lname , date , grade , id
	string split_data[5];
	int index = 0;
	for (auto c : _data)
	{
		if (c != ' ')
			split_data[index] += c;
		else
			index++;
	}

	string date[3];
	index = 0;
	for (auto c : split_data[2])
	{
		if (c != '/')
			date[index] += c;
		else
			index++;
	}
	string::size_type sz;     // alias of size_t

	Student s;
	s.Firstname = split_data[0];
	s.Lastname = split_data[1];
	Date d;

	d.year = stoul(date[0]);
	d.month = stoul(date[1]);
	d.day = stoul(date[2]);

	s.birthday = d;
	s.Grade = stof(split_data[3], &sz);
	s.ID = stoull(split_data[4], nullptr, 10);

	return s;
}

void AddClass(string cls)// add class by class name
{
	Class y;

	ifstream infile(cls);
	string line;
	int jump = 0;
	while (getline(infile, line))
	{
		if (jump == 0)
			y.Classname = line;

		if (jump == 1)
			y.capacity = stoul(line);

		if (jump >= 2)
		{
			y.Data.push_back(Add_Stuent(line));
		}

		jump++;
	}

	Database.push_back(y);

}

void RemoveClass(string cls)// remove aclass frome Database
{
	int j = 0;
	for (auto i : Database)
	{
		if (i.Classname == cls)
		{
			Database.erase(Database.begin() + j);   
		}
		j++;
	}
}

void ShowClass(string Cname)// show a class information by class name
{
	bool ok = false;
	for (auto i : Database)
	{
		if (i.Classname == Cname)
		{
			ok = true;

			cout << i.Classname << endl;
			cout << i.capacity << endl;

			for (auto j : i.Data)
			{
				cout << left << setfill(' ') << setw(6) << j.Firstname;
				cout << setw(8) << j.Lastname;
				cout << setw(4) << j.birthday.year << "/";
				cout << right << setfill('0') << setw(2) << j.birthday.month << "/";
				cout << setw(2) << j.birthday.day << " ";
				cout << setw(5) << j.Grade;
				cout << setfill(' ') << setw(11) << j.ID << endl;
			}
			break;
		}
	}
	if (ok == false)
	{
		cout << "=========================> class name not found !" << endl;
	}
}

void ShowAll()// show all classes' information
{
	for (auto i : Database)
	{
		cout << "============> class : " << i.Classname << " <============" << endl;
		cout << i.Classname << endl;
		cout << i.Data.size() << endl;

		for (auto j : i.Data)
		{
			cout << j.Firstname << " ";
			cout << j.Lastname << " ";
			cout << j.birthday.year << "/";
			cout << j.birthday.month << "/";
			cout << j.birthday.day << " ";
			cout << j.Grade << " ";
			cout << j.ID << endl;
		}
	}
}

void printc()// to show the selected class information
{
	bool ok = false;
	for (auto i : Database)
	{
		if (i.Classname == c.Classname)
		{
			ok = true;

			cout << i.Classname << endl;
			cout << i.Data.size() << endl;

			for (auto j : i.Data)
			{
				cout << endl;
				cout << left << setfill(' ') << setw(6) << j.Firstname;
				cout <<setw(8)<< j.Lastname;
				cout << setw(4) << j.birthday.year<<"/";
				cout << right << setfill('0') << setw(2) << j.birthday.month << "/";
				cout << setw(2) << j.birthday.day<<" ";
				cout << setw(5) << j.Grade;
				cout << setfill(' ') << setw(11) << j.ID << endl;

			}
			break;
		}
	}
	if (ok == false)
	{
		cout << "====>> class name not found !!!!" << endl;
	}
}

void AddStudent(string s, Date d,float f, unsigned long long int u )// to add a new student to a selected class
{
	string::size_type sz;     // alias of size_t

	Student y;
	string split_data[2];
	int index = 0;
	for (auto c : s)
	{
		if (c != ' ')
			split_data[index] += c;
		else
			index++;
	}
	y.Firstname = split_data[0];
	y.Lastname = split_data[1];
	y.birthday = d;
	y.Grade = f;
	y.ID = u;

	c.Data.push_back(y);

	for (auto &i : Database)
	{
		if (i.Classname == c.Classname)

			i.Data.push_back(y);
	}
}

void Datestudnt(string line) // convet student information string to rael information
{
	string split_data[5];
	int index = 0;
	for (auto c : line)
	{
		if (c != ' ')
			split_data[index] += c;
		else
			index++;
	}

	string date[3];
	index = 0;
	for (auto c : split_data[2])
	{
		if (c != '/')
			date[index] += c;
		else
			index++;
	}
	string::size_type sz;     // alias of size_t

	string fullname = split_data[0] + " " + split_data[1];
	Date d;

	d.year = stoul(date[0]);
	d.month = stoul(date[1]);
	d.day = stoul(date[2]);

	float grade = stof(split_data[3], &sz);
	unsigned long long int id = stoull(split_data[4], nullptr, 10);

	AddStudent(fullname, d, grade, id);

}

void RemoveStudent(unsigned long long int id)// remove student from a selected class
{
	for (auto &j : Database)
	{
		int k = 0;
		if (j.Classname == c.Classname)
		{
			for (auto &i : j.Data)
			{
				if (i.ID == id)
				{
					j.Data.erase(j.Data.begin() + k);
				}
				k++;
			}
		}
	}
}

void Search(unsigned long long int id)
{
	for (auto i : c.Data)
	{
		if (i.ID == id)
		{
			cout << endl;
			cout << "Firstname : " << i.Firstname << endl;
			cout << "Lastname  : " << i.Lastname << endl;
			cout << "birthday  : " << i.birthday.year << "/";
			cout << setfill('0') << setw(2) << i.birthday.month << "/";
			cout << setw(2) << i.birthday.day << endl;
			cout << "Grade     : " << setw(5) << i.Grade << endl;
			cout << "ID        : " << setw(10) << i.ID << endl;
		}
	}
}

void Search(string Fname, string Lname)
{
	for (auto i : c.Data)
	{
		if (i.Firstname == Fname && i.Lastname == Lname)
		{
			cout << endl;
			cout << "Firstname : " << i.Firstname << endl;
			cout << "Lastname  : " << i.Lastname << endl;
			cout << "birthday  : " << i.birthday.year << "/";
			cout << setfill('0') << setw(2) << i.birthday.month << "/";
			cout << setw(2) << i.birthday.day << endl;
			cout << "Grade     : " << setw(5) << i.Grade << endl;
			cout << "ID        : " << setw(10) << i.ID << endl;
		}
	}
}

void Sort_Id()
{
	vector <Student> v;
	v = c.Data;

	int j;

	for (auto z : v)
	{
		j = 0;

		for (auto i : v)
		{
			j++;
			if (j < v.size())
				if (i.ID > v[j].ID)
				{
					Student temp = v[j - 1];
					v[j - 1] = v[j];
					v[j] = temp;
				}
		}
	}

	c.Data = v;

	RemoveClass(c.Classname);

	Database.push_back(c);
}

void Sort_name()
{
	vector <Student> v;
	v = c.Data;

	int j;

	for (auto z : v)
	{
		j = 0;

		for (auto i : v)
		{
			j++;

			if (j < v.size())
				if (i.Lastname > v[j].Lastname)
				{
					Student temp = v[j - 1];
					v[j - 1] = v[j];
					v[j] = temp;
				}
		}
	}

	c.Data = v;

	RemoveClass(c.Classname);

	Database.push_back(c);
}

string to_lower(string x)
{
	for (auto &i : x)
	{
		if (i < 97 && i > 55)
		{
			i = i + 32;
		}
	}
	return x;
}

string cut1(string line) // to cut the () off from a string

{
	string str = line;

	if (str.find("<") != string::npos)//////////
	{
		unsigned first = str.find("<");
		unsigned last = str.find(">");
		str = str.substr(first + 1, last - first - 1);

		return str;
	}
	else
	{
		return "";
	}


}

string Filename(unsigned int str)
{
	string sa = to_string(str);
	string sb = ".basu";
	string sc = ("L") + sa + sb;

	return sc;
}

void Save()// to save the change
{
	unsigned int counter = 1;
	ofstream outf;
	for (auto i : Database)
	{
		outf.open(Filename(counter));

		outf << i.Classname << "\n";
		outf << i.Data.size() << "\n";
		for (auto j : i.Data)
		{
			outf << left << setfill(' ') << setw(6) << j.Firstname;
			outf << setw(8) << j.Lastname;
			outf << setw(4) << j.birthday.year << "/";
			outf << right << setfill('0') << setw(2) << j.birthday.month << "/";
			outf << setw(2) << j.birthday.day << " ";
			outf << setw(5) << j.Grade;
			outf << setfill(' ') << setw(11) << j.ID << endl;

		}
		outf.close();
		counter++;
	}
}

void Rank() // rate the students grade with A,B,C,D,E
{
	bool ok = false;
	for (auto i : Database)
	{
		if (i.Classname == c.Classname)
		{
			ok = true;

			cout << i.Classname << endl;
			cout << i.capacity << endl;

			for (auto j : i.Data)
			{
				cout << j.Firstname << " ";
				cout << j.Lastname << " ";
				
				if (j.Grade >= 18 )
				{
					cout << " A" << endl;
				}
				else if (j.Grade >= 15 && j.Grade < 18)
				{
					cout << " B" << endl;
				}
				else if (j.Grade >= 12 && j.Grade < 15)
				{
					cout << " C" << endl;
				}
				else if (j.Grade >= 10 && j.Grade < 12)
				{
					cout << " D" << endl;
				}
				else if (j.Grade < 10)
				{
					cout << " E" << endl;
				}
			}
			break;
		}
	}
	if (ok == false)
	{
		cout << "====>> class name not found !!!!" << endl;
	}

}

void Help()// the function that help you to enter the inputs
{
	string help = "Information about this programe :\n\n";
	help += "* basu add class <File Name>      : For adding a new class frome a file.\n";
	help += "* basu add student                : For adding student information to class.\n";
	help += "* basu remove student <ID>        : To remove a student from class by student number.\n";
	help += "* basu selsect class <Class Name> : To select a class.\n";
	help += "* basu select none                : To select nothing.\n";
	help += "* basu search <ID>                : To search for a student and show this student information by student number.\n";
	help += "* basu search <Full Name>         : To search for a student and show this student information by student fullname.\n";
	help += "* basu show                       : To show data.\n";
	help += "* basu show <Class Name>          : To show class information.\n";
	help += "* basu sort name                  : To sort the students by name.\n";
	help += "* basu sort id                    : To sort the students by student number.\n";
	help += "* basu save                       : To save the data.\n";
	help += "* basu Rank                       : To rate the student's grade with A,B,C,D,E.\n";
	help += "* basu exit                       : To exit the program.\n";

	cout << help;
}

void start()// Start function ( the main function )
{
	Class basu;
	
	string line;
	cout << "_>";
	while (getline(cin, line)) // till you press exit
	{
		bool correct = false;
		string arr[6];
		string y, stmt = "";
		int i = 0;
		int index = 0;
		string str = line;
		stmt = cut1(line);

		unsigned first1 = 0;
		unsigned last1 = str.find("<");
		string strNew1 = str.substr(first1, last1 - first1 - 1);


		for (auto c : strNew1)
		{
			if (c != ' ')
				arr[index] += c;
			else
				index++;
		}

		for (auto i : arr)
		{
			string w = i;
			w = to_lower(i);
			y += w;
		}

		if (y == "basuaddclass")
		{
			AddClass(stmt);
		}

		else if (y == "basuremoveclass")
		{
			RemoveClass(stmt);
		}

		else if (y == "basuaddstudent")
		{
			Datestudnt(stmt);
		}

		else if (y == "basuremovestudent")
		{
			RemoveStudent(stoull(stmt, nullptr, 10));
		}

		else if (y == "basuselectclass")
		{
			selectclass(stmt);
		}

		else if (y == "basuselectnone")
		{
			selectclass("non");
		}

		else if (y == "basusearch" && !isalpha(stmt[0]))
		{
			Search(stoull(stmt, nullptr, 10));
		}

		else if (y == "basusearch" && isalpha(stmt[0]))
		{
			string split_data[2];
			int index = 0;
			for (auto n : stmt)
			{
				if (n != ' ')
					split_data[index] += n;
				else
					index++;
			}

			Search(split_data[0], split_data[1]);
		}

		else if (y == "basushow" && stmt.length() > 1)
		{
			ShowClass(stmt);
		}

		else if (y == "basushow")
		{
			printc();
		}

		else if (y == "basusortname")
		{
			Sort_name();
		}

		else if (y == "basusortid")
		{
			Sort_Id();
		}

		else if (y == "basusave")
		{
			Save();
		}

		else if (y == "basurank")
		{
			Rank();
		}

		else if (y == "basuhelp")
		{
			Help();
		}

		else if (y == "exit")
		{
			break;
		}

		cout << endl << "_>";
	}
//	cout << "\npress Exit to exit programm \n";
}

int main()
{
	start();
	return 0;
}