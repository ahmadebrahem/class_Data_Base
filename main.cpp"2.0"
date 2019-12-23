// Data_Base_EX2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	//string ID;
	// note string ==> date ;
	Date birthday;
	//float Grade ;
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

void selectclass(string cls)
{
	for (int i = 0; i < Database.size(); i++)
		if (Database[i].Classname == cls)
		{
			c = Database[i];
		}
}

Student Add_Stuent(string _data)
{
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

void AddClass(string cls)///////////////////////////////
{
	Class y;
	std::ifstream infile(cls);
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

void RemoveClass(string cls)/////////////////////////////
{
	for (int i = 0; i < Database.size(); i++)
		if (Database[i].Classname == cls)
		{
			cout << "=======================" << endl;
			Database.erase(Database.begin() + i);
		}
}

void ShowClass(string Cname)
{
	bool ok = false;
	for (int i = 0; i < Database.size(); i++)
	{
		if (Database[i].Classname == Cname)
		{
			ok = true;

			cout << Database[i].Classname << endl;
			cout << Database[i].capacity << endl;

			for (int j = 0; j < Database[i].Data.size(); j++)
			{
				cout << Database[i].Data[j].Firstname << " ";
				cout << Database[i].Data[j].Lastname << " ";
				cout << Database[i].Data[j].birthday.year << "/";
				cout << Database[i].Data[j].birthday.month << "/";
				cout << Database[i].Data[j].birthday.day << " ";
				cout << Database[i].Data[j].Grade << " ";
				cout << Database[i].Data[j].ID << endl;
			}
			break;
		}
	}
	if (ok == false)
	{
		cout << "=========================> class name not found !" << endl;
	}
}

void ShowAll()
{
	for (int i = 0; i < Database.size(); i++)
	{
		cout << "============> class : " << Database[i].Classname << " <============" << endl;
		cout << Database[i].Classname << endl;
		cout << Database[i].capacity << endl;

		for (int j = 0; j < Database[i].Data.size(); j++)
		{
			cout << Database[i].Data[j].Firstname << " ";
			cout << Database[i].Data[j].Lastname << " ";
			cout << Database[i].Data[j].birthday.year << "/";
			cout << Database[i].Data[j].birthday.month << "/";
			cout << Database[i].Data[j].birthday.day << " ";
			cout << Database[i].Data[j].Grade << " ";
			cout << Database[i].Data[j].ID << endl;
		}
	}
}

void printc()
{

	cout << c.Classname << endl;
	cout << c.capacity << endl;
	for (int j = 0; j < c.Data.size(); j++)
	{
		cout << c.Data[j].Firstname << endl;
		cout << c.Data[j].Lastname << endl;
		cout << c.Data[j].birthday.year << endl;
		cout << c.Data[j].birthday.month << endl;
		cout << c.Data[j].birthday.day << endl;
		cout << c.Data[j].Grade << endl;
		cout << c.Data[j].ID << endl;
	}

	//for (auto z : c.Data)
			   // cout<<z.ID<<endl;
}

void AddStudent(string s, Date d, unsigned long long int u, float f)/////////////
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

	cout << y.Firstname << y.Lastname << y.Grade << y.ID << endl;

	c.Data.push_back(y);
	/* for(int j = 0 ; j <c.Data.size();j++)
	 {
	 cout<<Database[i].Data[i].Firstname<<endl;
	 cout<<Database[i].Data[i].Lastname<<endl;
	 cout<<Database[i].Data[i].birthday.year<<endl;
	 cout<<Database[i].Data[i].birthday.month<<endl;
	 cout<<Database[i].Data[i].birthday.day<<endl;
	 cout<<Database[i].Data[i].Grade<<endl;
	 cout<<Database[i].Data[i].ID<<endl;
	 }*/



	for (int i = 0; i < Database.size(); i++)
	{
		if (Database[i].Classname == c.Classname)
			cout << "pppppppppppppppppppppppppppppppppppppp" << endl;
		Database[i].Data.push_back(y);
	}



}

void Datestudnt(string line)
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

	//d
	unsigned long long int id = stoull(split_data[3], nullptr, 10);
	float grade = stof(split_data[4], &sz);

	cout << fullname << split_data[3] << d.year << d.month << d.day << split_data[4] << endl;
	cout << fullname << id << d.year << d.month << d.day << grade << endl;

	AddStudent(fullname, d, id, grade);
}

void RemoveStudent(unsigned long long int id)
{
	for (int j = 0; j < Database.size(); j++)
	{
		if (Database[j].Classname == c.Classname)
		{
			for (int i = 0; i < Database[j].Data.size(); i++)
			{
				if (Database[j].Data[i].ID == id)
				{
					Database[j].Data.erase(Database[j].Data.begin() + i);
					cout << "fffffffffffff" << endl;
				}
			}
		}
	}
}

void Search(unsigned long long int id)
{
	for (int i = 0; i < c.Data.size(); i++)
	{
		if (c.Data[i].ID == id)
		{
			cout << "Firstname " << c.Data[i].Firstname << endl;
			cout << "Lastname " << c.Data[i].Lastname << endl;
			cout << "birthday " << c.Data[i].birthday.year << "/" << c.Data[i].birthday.month << "/" << c.Data[i].birthday.day << endl;
			cout << "ID " << c.Data[i].ID << endl;
			cout << "Grade " << c.Data[i].Grade << endl;
		}
	}
}

void Search(string Fname, string Lname)
{
	for (int i = 0; i < c.Data.size(); i++)
	{
		if (c.Data[i].Firstname == Fname && c.Data[i].Lastname == Lname)
		{
			cout << "Firstname " << c.Data[i].Firstname << endl;
			cout << "Lastname " << c.Data[i].Lastname << endl;
			cout << "birthday " << c.Data[i].birthday.year << "/" << c.Data[i].birthday.month << "/" << c.Data[i].birthday.day << endl;
			cout << "ID " << c.Data[i].ID << endl;
			cout << "Grade " << c.Data[i].Grade << endl;


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
	cout << str.find("<") << " ddddddddddddd" << endl;
	if (str.find("<") != string::npos)//////////
	{
		unsigned first = str.find("<");
		unsigned last = str.find(">");
		str = str.substr(first + 1, last - first - 1);
		cout << "new " << str << endl;
		return str;

	}
	else
	{
		cout << "oooooooooooooooo = " << "" << endl;
		return "";
	}


}


void start()
{
	Class basu;
	string help = "Information about this programe :\n\n\n";
	help += "* basu add class <File Name>      : For adding a new class frome a file.\n";
	help += "* basu add student                : For adding student information to class.\n\n";
	help += "* basu remove student <ID>        : To remove a student from class by student number.\n\n";
	help += "* basu selsect class <Class Name> : To select a class.\n";
	help += "* basu select none                : To select nothing.\n\n";
	help += "* basu search <ID>                : To search for a student and show this student information by student number.\n";
	help += "* basu search <Full Name>         : To search for a student and show this student information by student fullname.\n\n";
	help += "* basu show                       : To show data.\n";
	help += "* basu show <Class Name>          : To show class information.\n\n";
	help += "* basu sort name                  : To sort the students by name.\n";
	help += "* basu sort id                    : To sort the students by student number.\n\n";
	help += "* basu save                       : To save the data.\n\n";
	help += "* basu exit                       : To exit the program.\n\n";
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
		cout << "new1 " << strNew1 << endl;

		for (auto c : strNew1)
		{
			if (c != ' ')
				arr[index] += c;
			else
				index++;
		}

		for (auto x : arr)
			cout << "x = " << x << endl;

		for (int i = 0; i < 6; i++)
		{
			string w = arr[i];




			w = to_lower(arr[i]);
			y += w;



		}

		cout << "y = " << y << endl;
		cout << "s = " << stmt << endl;

		if (y == "basuaddclass")
		{
			cout << "basuaddclass" << endl;
			AddClass(stmt);
			//basu.get_file(stmt);
		}
		else if (y == "basuremoveclass")
		{
			RemoveClass(stmt);
			//basu.removeclass(stmt);
		}
		else if (y == "basuaddstudent")
		{
			Datestudnt(stmt);
			//basu.add_student(stmt);
		}
		else if (y == "basuremovestudent")
		{
			cout << "***************    " << stoull(stmt, nullptr, 10) << endl;
			RemoveStudent(stoull(stmt, nullptr, 10));
			//basu.remove_student(stoi(stmt));
		}
		else if (y == "basuselectclass")
		{
			selectclass(stmt);
			//basu.selectclass(stmt);
		}
		else if (y == "basuselectnone")
		{
			selectclass("non");
		}
		else if (y == "basusearch" && !isalpha(stmt[0]))
		{
			Search(stoull(stmt, nullptr, 10));
			//basu.search_id(stoi(stmt));
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
			//basu.search_name(stmt);
		}
		else if (y == "basushow" && stmt.length() > 1)
		{
			cout << "print c ===========" << endl;
			printc();
		}
		else if (y == "basushow")//////////////////////////////////
		{
			cout << "show all =====================" << endl;
			ShowAll();
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
			///basu.save();
		}
		else if (y == "basuhelp")
		{
			cout << help;
		}
		else if (y == "exit")
		{
			break;
		}
		cout << endl << "_>";
	}
}


int main()
{
	start();
	/*
	  AddClass ("L.txt")  ;
	  AddClass ("L2.txt")  ;
	  ShowAll ();
	  selectclass("Logic_Circuits");
	 // Sort_Id();
	 Sort_name();
	//printc();
    */
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
