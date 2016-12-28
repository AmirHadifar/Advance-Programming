#include <iostream>
using namespace std;
class Complex_num
{
private:
	float x;
	float y;
public:
	Complex_num(): x(0) , y(0) {} // constructor
	void get();    
	Complex_num add(Complex_num);
	Complex_num minus(Complex_num);
	Complex_num muliply(Complex_num);
	Complex_num division(Complex_num);
	void display(Complex_num,Complex_num);
};
void Complex_num::get()
{
	cout<<"Enter X :";cin>>x;
	cout<<"Enter Y :";cin>>y;
	cout<<endl;

}
////////////////////////////////////////////////////////////////////////////////
Complex_num Complex_num::add(Complex_num B1)//function for add 2 complex number 
{
           Complex_num temp;
           temp.x = x + B1.x;
           temp.y = y + B1.y;
           return  temp;
}
////////////////////////////////////////////////////////////////////////////////
Complex_num Complex_num::minus(Complex_num B1)//function for minus 2 complex number
{
           Complex_num temp;
           temp.x = x - B1.x;
           temp.y = y - B1.y;
           return temp;
}
////////////////////////////////////////////////////////////////////////////////
Complex_num Complex_num::muliply(Complex_num B3)//function for muliply 2 complex number
{
           Complex_num temp;
           temp.x = x*B3.x - y*B3.y;
           temp.y = x*B3.y + B3.x*y;
           return temp;
}
////////////////////////////////////////////////////////////////////////////////
Complex_num Complex_num::division(Complex_num B2)
{
	Complex_num temp2,temp1;

	if(B2.x==0 && B2.y==0)
	{
		cout<<"Second Coordinate is not possible ! "<<endl;
		temp2.x=0;
		temp2.y=0;
		return temp2;
	}
	else
	{
		temp2.x=x*B2.x - y*(-B2.y); // muliply top
		temp2.y=x*(-B2.y) + B2.x*y;
	
		temp1.x=B2.x*B2.x - B2.y*(-B2.y); // muliply botton
		temp1.y=B2.x*(-B2.y) + B2.x*B2.y;

		float div=temp1.x+temp1.y;
		temp2.x/=div;
		temp2.y/=div;
		return temp2;
	}

}
////////////////////////////////////////////////////////////////////////////////////
void Complex_num::display(Complex_num a,Complex_num b)// display the complex number >>> A + iB
{
	cout<<"----------------------------------------------------\n";
	cout<<"first Coordinate  :("<<a.x<<" , "<<a.y<<")\n"
		<<"second Coordinate :("<<b.x<<" , "<<b.y<<")\n\n";
    cout<<"Answer is : "<<x;
	if(y>=0)
		cout<<" + "<<y<<"i "<<endl;
	else
		cout<<" - "<<-y<<"i "<<endl;
	cout<<"----------------------------------------------------\n";
}
////////////////////////////////////////////////////////////////////////////////
//==============================================================================
void start(Complex_num&,Complex_num&);
int main()
{
	system("color 09");
	Complex_num num1,num2,temp;
	int option;
	start(num1,num2);
	do
	{
		cout<<"Menu:\n\t[1] Add\n\t[2] Minus\n\t[3] Muliply\n\t[4] Division\n\t[5] Set new numbers\n\t[6] Exit\nChoose Your Option :";cin>>option;//choose operator
		cout<<endl;
		system("cls");
		switch(option)
		{
		case 1:
			cout<<"Add"<<endl;
			temp=num1.add(num2);
			temp.display(num1,num2);	
			break;	
		case 2:
			cout<<"Minus"<<endl;
			temp=num1.minus(num2);
			temp.display(num1,num2);
			break;
		case 3:
			cout<<"Muliply"<<endl;
			temp=num1.muliply(num2);
			temp.display(num1,num2);
			break;
		case 4:
			cout<<"Division"<<endl;
			temp=num1.division(num2);
			temp.display(num1,num2);
			break;
		case 5:
			start(num1,num2);
			break;
		case 6:
			exit(0);
		default:
			cout<<"Wrong input"<<endl;
		}//end of switch

	}while(option!=6);

		system("pause");
		return 1905;
}
//===============================================
void start(Complex_num& a,Complex_num& b)
{
	int option;
	system("cls");
	cout<<"\n"
		<<" [1] Set New number\n"
		<<" [2] Exit \n\n"
		<<"Choose Your Option :";cin>>option;
	cout<<endl;
	switch(option)
	{
	case 1:
		cout<<"Enter first Coordinate \n";
		a.get();
		cout<<"Enter second Coordinate \n";
		b.get();
		break;
	case 2:
		exit(0);
	default:
		cout<<"Wrong input ! "<<endl;
	}
}
