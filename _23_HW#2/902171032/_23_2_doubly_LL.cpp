#include <iostream>
#include <string>
using namespace std;
//====================
struct Link_list
{
	string name;
	string family;
	double ID;
	Link_list* next;
	Link_list* prev;
};
//====================
//---------------------
int main()
{
	int num,i;
	Link_list* head=NULL;
	Link_list* tail;
	Link_list* curr;
	Link_list* temp1;
	Link_list* temp2;
	Link_list* search;
	cout<<"How many Student u want to Create at First ?";cin>>num;

	for(i=0;i<num;i++)
	{
		curr=new Link_list;
		cout<<"\n# Student "<<i+1<<"#"<<endl;
		cout<<"Enter Student Name :";cin>>curr->name;
		cout<<"Enter Student Family :";cin>>curr->family;
		cout<<"Enter Student Account Identifiction :";cin>>curr->ID;
		curr->next=NULL;
		curr->prev=NULL;
		
		if(head==NULL)        // if list is empty
			temp1=tail=head=curr;
		else
		{
			search=head;
			while(search)
			{
				if(search->ID > curr->ID )
					break;
				else
					search=search->next;
			}// end of while for search and find ~__~

			if(head==search && curr->ID < head->ID )
			{
				curr->next=head;
				head->prev=curr;
				head=curr;
			}
			else if(tail==search && curr->ID < tail->ID)
			{
				curr->prev=tail->prev;
				curr->next=tail;
				(tail->prev)->next=curr;
				tail->prev=curr;
			}
			else
			{
				if(curr->ID > tail->ID)
				{
					tail->next=curr;
					tail=curr;
					tail->prev=temp1;
					temp1=curr;
				}
				else
				{
					curr->next=search;
					curr->prev=search->prev;
					search->prev->next=curr;
					search->prev=curr;
				}
			}




		}

		}// end of for

	
	cout<<endl;
	//==============================
	system("cls");
	while(num!=4)
	{
		cout<<"Menu"
		<<"\n\t1- Enter Student "
		<<"\n\t2- Delete a Student "
		<<"\n\t3- Print Students "
		<<"\n\t4- Exit "
		<<"\nChoose Option :";cin>>num;
	switch(num)
	{
	case 1:
		curr=new Link_list;
		cout<<"\n# Student "<<i+1<<"#"<<endl;
		cout<<"Enter Student Name :";cin>>curr->name;
		cout<<"Enter Student Family :";cin>>curr->family;
		cout<<"Enter Student Account Identifiction :";cin>>curr->ID;
		curr->next=NULL;
		curr->prev=NULL;
		
		if(head==NULL)        // if list is empty
			temp1=tail=head=curr;
		else
		{
			search=head;
			while(search)
			{
				if(search->ID > curr->ID )
					break;
				else
					search=search->next;
			}                                         // end of while for search and find ~__~

			if(head==search && curr->ID < head->ID )
			{
				curr->next=head;
				head->prev=curr;
				head=curr;
			}
			else if(tail==search && curr->ID < tail->ID)
			{
				curr->prev=tail->prev;
				curr->next=tail;
				(tail->prev)->next=curr;
				tail->prev=curr;
			}
			else
			{
				if(curr->ID > tail->ID)
				{
					tail->next=curr;
					tail=curr;
					tail->prev=temp1;
					temp1=curr;
				}
				else
				{
					curr->next=search;
					curr->prev=search->prev;
					search->prev->next=curr;
					search->prev=curr;
				}
			}
		}
		break;
	case 2:
		bool answer;
		int ID;
		cout<<"Enter student ID :";cin>>ID;
		search=head;
		while(search)
		{
			if(search->ID==ID && search==head)
			{
				Link_list* temp=search;
				head=head->next;
				delete temp;
				answer=true;
				break;
			}
			else if(search->ID==ID && search==tail)
			{
				Link_list* temp=search;
				tail=tail->prev;
				tail->next=NULL;
				delete temp;
				answer=true;
				break;
			}
			else if(search->ID==ID)
			{
				Link_list* temp=search;
				search->next->prev=search->prev;
				search->prev->next=search->next;
				delete temp;
				answer=true;
				break;
			}
			else
			{
				search=search->next;
				answer=false;
			}
		}
		if(answer==false)
			cout<<"Invalid Account identifiction "<<endl;
		else 
			cout<<"Deleted ... "<<endl;

		break;

	case 3:
			temp2=head;
			while(temp2)
			{
				cout<<temp2->name<<" , "<<temp2->family<<" Account identifiction :"<<temp2->ID<<endl;
				temp2=temp2->next;
			}
			break;
	default:
		cout<<"Wrong Input !"<<endl;
	}// end of case 
	}
	cout<<"\n\n\n";
	system("pause");
	return 0;
}
