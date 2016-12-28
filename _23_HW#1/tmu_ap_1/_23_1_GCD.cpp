//HomeWork_1_1
//calculate GCD ( Greatest Common Divisor )
#include <iostream>
using namespace std;
void start(int& , int&);// for get integers
void exchange(int& , int&); // for exchange and make integer positive
int GCD(int,int);// calculate GCD
void display(int,int,int);
//=======================
int main()
{
	int a,b;
	start(a,b);// Get integeres
	system("pause");
	return 0;
}
//========================
void start(int& a,int& b)
{

	cout<<"Greatest Common Divisor\n\n";
	cout<<"Please Enter first integer :";cin>>a;
	cout<<"Please Enter second integer :";cin>>b;
	exchange(a,b); // replace if a is smaller than b // if a or b is negetive change them
	int gcd=GCD(a,b); // calculate G C D
	display(a,b,gcd);//display G C D
	

}
//~~~~~~~~~~~~~~~~~~~~~~~~
void exchange(int& a,int& b)
{
	int temp;
	
	if(a<0)
		a*=-1;
	if(b<0)
		b*=-1;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~
int GCD(int a,int b)
{	
	if(a%b==0)
		return b;
	else
		return GCD(b,a%b);
}
//~~~~~~~~~~~~~~~~~~~~~
void display(int a,int b,int gcd)
{
	cout<<"\nGreat Common DivisoR :"<<endl;
	cout<<"("<<a<<" , "<<b<<") = "<<gcd<<endl<<endl;
}