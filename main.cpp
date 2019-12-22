#include <iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;


struct Date
{
    unsigned short int year ;
    unsigned short int month ;
    unsigned short int day ;
};

struct Student
{
    string Firstname;
    string Lastname ;
    unsigned long long int ID ;
    //string ID;
    // note string ==> date ;
    Date birthday ;
    //float Grade ;
    float Grade ;

};

struct Class
{
    string Classname;
    //float Average;
    unsigned short int capacity ;
    vector <Student> Data;
};

vector<Class> Database;
Class c ;

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

		Student s ;
		s.Firstname=split_data[0];
        s.Lastname=split_data[1];
        Date d ;

        d.year=stoul(date[0]);
        d.month=stoul(date[1]);
        d.day=stoul(date[2]);

        s.birthday=d ;
        s.Grade=stof(split_data[3], &sz);
        s.ID=stoull(split_data[4], nullptr, 10);

        return s ;



	}

void AddClass (string cls)///////////////////////////////
{


Class y ;

    std::ifstream infile(cls);
    string line;
    int jump = 0 ;
while (getline(infile, line))
{
    if (jump == 0)
        y.Classname = line;

    if (jump == 1 )
      y.capacity= stoul(line);

    if(jump>=2)
    {
        y.Data.push_back(Add_Stuent(line));

    }



    jump++ ;
}


    Database.push_back(y) ;


}

void RemoveClass(string cls)/////////////////////////////
{
    for (int i = 0; i < Database.size(); i++)
			if (Database[i].Classname == cls)
            {
                cout<<"======================="<<endl;
                Database.erase(Database.begin() + i);


            }


}

void ShowClass (string Cname)
{
    bool ok = false ;
    for (int i = 0 ; i < Database.size(); i++)
    {
        if(Database[i].Classname==Cname)
        {
            ok = true;


        cout<<Database[i].Classname<<endl;
        cout<<Database[i].capacity<<endl;


        for(int j = 0 ; j <Database[i].Data.size();j++)
        {
        cout<<Database[i].Data[j].Firstname<<" ";
        cout<<Database[i].Data[j].Lastname<<" ";
        cout<<Database[i].Data[j].birthday.year<<"/";
        cout<<Database[i].Data[j].birthday.month<<"/";
        cout<<Database[i].Data[j].birthday.day<<" ";
        cout<<Database[i].Data[j].Grade<<" ";
        cout<<Database[i].Data[j].ID<<endl;

        }
break;
        }


    }
    if(ok == false)
    {
        cout<<"=========================> class name not found !"<<endl;
    }
}

void ShowAll ()
{

    for (int i = 0 ; i < Database.size(); i++)
    {cout<<"============> class : "<<Database[i].Classname<<" <============"<<endl;
        cout<<Database[i].Classname<<endl;
        cout<<Database[i].capacity<<endl;

        for(int j = 0 ; j <Database[i].Data.size();j++)
        {
        cout<<Database[i].Data[j].Firstname<<" ";
        cout<<Database[i].Data[j].Lastname<<" ";
        cout<<Database[i].Data[j].birthday.year<<"/";
        cout<<Database[i].Data[j].birthday.month<<"/";
        cout<<Database[i].Data[j].birthday.day<<" ";
        cout<<Database[i].Data[j].Grade<<" ";
        cout<<Database[i].Data[j].ID<<endl;
        }


        }




}



void printc ()
{

       /* cout<<c.Classname<<endl;
        cout<<c.capacity<<endl;
        for(int j = 0 ; j <c.Data.size();j++)
        {
        cout<<c.Data[j].Firstname<<endl;
        cout<<c.Data[j].Lastname<<endl;
        cout<<c.Data[j].birthday.year<<endl;
        cout<<c.Data[j].birthday.month<<endl;
        cout<<c.Data[j].birthday.day<<endl;
        cout<<c.Data[j].Grade<<endl;
        cout<<c.Data[j].ID<<endl;
        }
*/
for (auto z : c.Data)
            cout<<z.ID<<endl;
}

void AddStudent (string s ,Date d , unsigned long long int u  , float f)/////////////
{
    string::size_type sz;     // alias of size_t

		Student y ;
		string split_data[2];
		int index = 0;
		for (auto c : s)
		{
			if (c != ' ')
				split_data[index] += c;
			else
				index++;
		}
		y.Firstname=split_data[0];
        y.Lastname=split_data[1];
        y.birthday= d ;
        y.Grade=f;
        y.ID=u;

        cout<< y.Firstname << y.Lastname << y.Grade <<y.ID<<endl;

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



       for(int i = 0 ; i < Database.size();i++)
       {
           if(Database[i].Classname=="Advanced Programming")
            cout<<"pppppppppppppppppppppppppppppppppppppp"<<endl;
           Database[i].Data.push_back(y);
       }



}

void Datestudnt (string line)
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
		Date d ;

        d.year=stoul(date[0]);
        d.month=stoul(date[1]);
        d.day=stoul(date[2]);

        //d
        unsigned long long int id = stoull(split_data[3], nullptr, 10);
        float grade =stof(split_data[4], &sz);

        cout<<fullname<<split_data[3]<<d.year<<d.month<<d.day <<split_data[4]<<endl;
        cout<<fullname<<id<<d.year<<d.month<<d.day <<grade<<endl;


		AddStudent(fullname , d , id , grade );







}

void RemoveStudent (unsigned long long int id)
{





    for(int i = 0 ; i < c.Data.size();i++)
    {
        if(c.Data[i].ID==id)
        {

            c.Data.erase(c.Data.begin() + i);
        cout<<"fffffffffffff"<<endl;
        }
    }

}

void Search(unsigned long long int id)
{
    for(int i = 0 ; i < c.Data.size();i++)
    {
        if(c.Data[i].ID==id)
        {
            cout<<"Firstname "<<c.Data[i].Firstname<<endl;
            cout<<"Lastname "<<c.Data[i].Lastname<<endl;
            cout<<"birthday "<<c.Data[i].birthday.year<<"/"<<c.Data[i].birthday.month<<"/"<<c.Data[i].birthday.day<<endl;
            cout<<"ID "<<c.Data[i].ID<<endl;
            cout<<"Grade "<<c.Data[i].Grade<<endl;


        }
    }

}


void Search(string Fname , string Lname)
{
    for(int i = 0 ; i < c.Data.size();i++)
    {
        if(c.Data[i].Firstname==Fname &&c.Data[i].Lastname==Lname )
        {
            cout<<"Firstname "<<c.Data[i].Firstname<<endl;
            cout<<"Lastname "<<c.Data[i].Lastname<<endl;
            cout<<"birthday "<<c.Data[i].birthday.year<<"/"<<c.Data[i].birthday.month<<"/"<<c.Data[i].birthday.day<<endl;
            cout<<"ID "<<c.Data[i].ID<<endl;
            cout<<"Grade "<<c.Data[i].Grade<<endl;


        }
    }

}








void Sort_Id()
	{vector <Student> v;
	    v=c.Data;

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




c.Data=v;


		for (auto z : c.Data)
            cout<<z.ID<<endl;

            RemoveClass(c.Classname);

            Database.push_back(c);
	}






int main()
{


  AddClass ("L.txt")  ;
  AddClass ("L2.txt")  ;
  ShowAll ();
  selectclass("Logic_Circuits");
  Sort_Id();
//printc();
   ShowClass ("Logic_Circuits");
   /*
cout<<"oooooooooooooooooooooo//////////////////////////oooooooooooooooooooooooooo"<<endl;


   ShowClass ("Advanced Programming");
cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;
   Datestudnt ("hasan hammad 2000/2/24 9622358001 12");

   ShowClass ("Advanced Programmins");
    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;


    Search(9622358001);
     cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;


    Search("hasan" , "hammad");

    cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;
   RemoveStudent(9622358001);
   ShowClass ("Logic_Circuits");

cout<<"ooooooooooooooooooooooooooooooooooooooooooooooooooo"<<endl;





  RemoveClass("Logic_Circuits")  ;


   //printc ();


   ShowClass ("Logic_Circuits");


*/




    return 0;
}
