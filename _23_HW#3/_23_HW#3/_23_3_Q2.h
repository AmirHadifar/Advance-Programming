#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef Student_h
#define Student_h

class student
{
private:
	string name;
	string family;
	static int ID;
	int identifiction;
	string major;
public:
	student* next;
	student()
	{
		name="Name";
		family="Family";
		identifiction=0;
		major="Major";
	}
	void add();
	void display();
	string retname()   {	return name; }
	string retfamily() { return family; }
	int retid() { return identifiction; }
	void set_name() { cout<<"Enter New name :";cin>>name; }
	void set_family() { cout<<"Enter New family :";cin>>family; }
	void set_major() { cout<<"Enter New Major :";cin>>major; }
};
int student::ID(0);//static data which store students ID's
//===================================
void student::add()
{
	cout<<"Add new Student "<<endl<<endl
		<<"Enter Student Name :";cin>>name;
	cout<<"Enter Student Family :";cin>>family;
	cout<<"Enter Student Major :";cin>>major;
	identifiction=ID++;// give them an id atoumaticly when an object create 
	cout<<"Student ID :"<<identifiction<<endl;
	
}
void student::display()
{
	cout<<setw(10)<<name<<setw(10)<<family<<setw(10)<<major<<setw(10)<<identifiction<<endl;
	cout<<"============================================================\n";
}

#endif