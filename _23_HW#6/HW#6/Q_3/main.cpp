#include<iostream>
#include<conio.h>
#include"Farm.h"
#include"Morgh.h"
#include"Duck.h"
using namespace std;
int main()
{
	int count;
	Farm farm;
	cout<<"Please Enter Number of Morghs : ";
	cin>>count;
	int D = count/2;
	for(int i=0;i<D;i++)
	{
		Duck *Temp = new Duck();
		farm.AddBird(Temp);
	}
	for(int i=0;i<count-D;i++)
	{
		Morgh *Temp = new Morgh();
		farm.AddBird(Temp);
	}
	for(int i=0;i<1000;i++)
		farm.Cycle();
	cout<<"-----------------------------------------\n";
	cout<<"Total Speak : "<<farm.totalspeak;
	_getch();
	return 0;
}