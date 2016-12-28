#include<iostream>
#include<conio.h>
#include"Farm.h"
#include"Morgh.h"
using namespace std;
int main()
{
	int count;
	Farm farm;
	cout<<"Please Enter Number of Hens : ";
	cin>>count;
	for(int i=0;i<count;i++)
	{
		Morgh *Temp = new Morgh(&farm);
		farm.AddMorgh(Temp);
	}
	for(int i=0;i<1000;i++)
		farm.Cycle();
	cout<<"---------------------------------------------------\n";
	cout<<"Total Ghod Ghod is : "<<farm.totalGhodghod;
	_getch();
	return 0;
}