#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace std;
student* head=NULL;
student* tail=NULL;
//===========all functions==============
void start();
void add();
void edit();
void display_all();
void omit();
student* finder_name();
void finder_id();
//============= main ===================
int main()
{
	system("color 09");
	start();
	system("pause");
	return 1905;
}
//======================================
void start()
{
	student* temp=NULL;
	int option;
	do
	{
		cout<<"Menu :\n"
			<<"\t[1] Add new Student \n"
			<<"\t[2] Edit information about a Student \n"
			<<"\t[3] Omit a Student \n"
			<<"\t[4] Display all Students \n"
			<<"\t[5] Find a Student by name  \n"
			<<"\t[6] Find a Student by ID \n"
			<<"\t[7] Exit\n";
		cout<<"Choose Your Option :";cin>>option;
		system("cls");
			switch(option)
			{
			case 1:
				add();
				break;
			case 2:
				edit();//for edit information about a student
				break;
			case 3:
				omit();// deleting a student
				break;
			case 4:
				display_all();// display all studnet ( name,family,major,id)
				break;
			case 5:
				temp=finder_name();//find a specfic member by getting name from user
				if(temp)
				{
					cout<<setw(10)<<"Name"<<setw(10)<<"Family"<<setw(10)<<"Major"<<setw(15)<<"Account ID "<<endl<<endl;
					cout<<"============================================================\n";
					temp->display();
					cout<<endl;
				}

				else
					cout<<"Invalid name or family ."<<endl;
				break;
			case 6:
				finder_id();// find students by searching their ID's
				break;
			case 7:
				break;
			default:
				cout<<"Wrong input !"<<endl;
			}
		
	}while(option!=7);
}
//=============================
void add()
{
	student* var=new student;
	var->add();
	var->next=NULL;
	if(!head)
		head=tail=var;
	else
	{
		tail->next=var;
		tail=var;
	}
}
//=======================================
void display_all()
{
	student* temp=head;
	cout<<"List of all Student \n\n";
	cout<<setw(10)<<"Name"<<setw(10)<<"Family"<<setw(10)<<"Major"<<setw(15)<<"Account ID "<<endl<<endl;
	cout<<"============================================================\n";

	while(temp)
	{
		temp->display();
		temp=temp->next;
	}
	cout<<endl;
}
//=======================================
void edit()
{
	student* temp=finder_name();
	if(!temp)
		cout<<"Invalid name or family "<<endl;
	else
	{
		int option;
		do
		{
			cout<<"Edit\n"
				<<"[1] Name \n"
				<<"[2] Family \n"
				<<"[3] Major \n"
				<<"[4] Exit \n";
			cout<<"Choose Your Option :";cin>>option;

			switch(option)
			{
			case 1:
				temp->set_name();
				break;
			case 2:
				temp->set_family();
				break;
			case 3:
				temp->set_major();
				break;
			case 4:
				break;
			default:
				cout<<"Wrong input !"<<endl;
			}//end of switch
		}while(option!=4);
	}//end of else
}//end of function
//==================================================
student* finder_name()
{
	student* temp=head;
	string name;
	string family;
	cout<<"Enter Student name :";cin>>name;
	cout<<"Enter Student family :";cin>>family;
	cout<<endl;
	
	while(temp)
	{
		if(temp->retname()==name && temp->retfamily()==family)
		{
			return temp;
		}
		else
			temp=temp->next;
	}

	return NULL;
}
//================================================
void finder_id()
{
	student* temp=head;
	int id;
	cout<<"Enter Student ID :";cin>>id;
	while(temp)
	{
		if(id==temp->retid())
		{
			cout<<endl<<endl;
			cout<<setw(10)<<"Name"<<setw(10)<<"Family"<<setw(10)<<"Major"<<setw(15)<<"Account ID "<<endl<<endl;
			cout<<"============================================================\n";
			temp->display();
			cout<<endl<<endl;
			return;
		}
		else
			temp=temp->next;
	}
}
//==============================================
void omit()
{
	student* temp=finder_name();
	student* tail_del=tail;
	student* head_del=head;

	if(temp==NULL)
		cout<<"Invalid entry !"<<endl;
	else
	{
			if( head_del->retname()==temp->retname() && head_del->retfamily()==temp->retfamily() )
			{
				student* tmp=head;
				head=head->next;
				delete tmp;
				cout<<"Succuessfully Deleted !"<<endl;
				return;
			}
			else if( tail_del->retname()==temp->retname()  && tail_del->retfamily()==temp->retfamily() )
			{
				student* pre_tail=NULL;
				student* search_tail=head;
				while(search_tail->next)
				{
					pre_tail=search_tail;
					search_tail=search_tail->next;
				}

				pre_tail->next=NULL;
				tail=pre_tail;
				cout<<"Succuessfully Deleted !"<<endl;
				delete search_tail;
				return;
			}
			else	
			{
				student* temp1=head;
				student* temp2=NULL;
				while(temp1->next)
				{
					
					if(temp1->retname()==temp->retname() && temp1->retfamily()==temp->retfamily() )
						break;
					else
					{
						temp2=temp1;
						temp1=temp1->next;
					}
				}
				temp2->next=temp1->next;
				delete temp1;
				cout<<"\nSuccuessfully Deleted !"<<endl<<endl;
				return;
			}
		
	}
}	