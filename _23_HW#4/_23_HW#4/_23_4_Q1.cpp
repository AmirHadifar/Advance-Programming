// Stack with some function ( push,pop,copy_con,empty,size,...)
// All right revived by Amir
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int d=0,Node* n=NULL)
	{
		data=d;
		next=n;
	}
	int data;
	Node* next;
};
//=====================================
class Stack
{
private:
	Node* _top;
	int _size;
public:
	Stack():_top(NULL),_size(0) {}
	Stack(const Stack&);
	Stack(int s, Node* n);
	~Stack();
	int Size()const{	return _size;	}
	int Top();
	bool Empty();
	void Pop();
	void Push();
};
//=====================================
Stack::Stack(const Stack& R) // copy constructor
{
	_size=R._size;
	Node* apnode=new Node;
	if(R._top)
		_top=apnode;
	else
		_top=NULL;
	Node *ap=R._top;
	while(ap!=NULL)
	{
		apnode->data=ap->data;
		if(ap->next==NULL)
			apnode->next=NULL;
		else
		{
			apnode->next=new Node;
			apnode=apnode->next;
		}
		ap=ap->next;
	}
}
//=====================================
Stack::~Stack() // destructor
{
	while(_top)
		this->Pop();
}
//=====================================
int Stack::Top() // fuction that return top 
{
	if(_top)
		return _top->data;
	else
		return -999;
}
//=====================================
bool Stack::Empty() // this function check to see stack is empty or not
{
	if(_top)
		return false;
	else
		return true;
}
//=====================================
void Stack::Push() // add new data to top of stack
{
	Node* var=new Node;
	_size++;
	cout<<"Enter Data :";cin>>var->data;
	var->next=NULL;
	if(!_top)
		_top=var;
	else
	{
		var->next=_top;
		_top=var;
	}
}
//=====================================
void Stack::Pop() // remove the top data
{
	Node* temp=this->_top;
	if(temp)
	{
		_top=_top->next;
		delete temp;
		_size--;
	}
	else
		cout<<"Stack is Empty !"<<endl;
}
//=====================================
int main()
{
	int option;
	Stack s; 
	do
	{
		cout<<"[1] Push\n"
			<<"[2] Pop\n"
			<<"[3] Size\n"
			<<"[4] top\n"
			<<"[5] Empty\n"
			<<"[6] Exit\n"
			<<"Choose Your option :";cin>>option;
		system("cls");
		switch(option)
		{
		case 1:
			s.Push();
			break;
		case 2:
			s.Pop();
			break;
		case 3:
			cout<<"Size of Stack is :"<<s.Size()<<endl;
			break;
		case 4:
			cout<<"Stored Data in Top is :";
				if(s.Top()==-999)
					cout<<" Nothing ."<<endl;
				else
					cout<<s.Top()<<endl;

			break;
		case 5:
			cout<<"Is Stack Empty ? "<<boolalpha<<s.Empty()<<endl;
			break;
		case 6:
			break;
		default:
			cout<<"Wrong input !"<<endl;
		}
	}while(option!=6);
	
	system("pause");
	return 1905;
}
