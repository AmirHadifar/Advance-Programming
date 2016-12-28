#include <iostream>
#include "Farm.h"
#include "Morgh.h"
using namespace std;
int main()
{
	Morgh* hen;
	Farm farm;
	int n;
	cout<<"Enter Number of the Hens :";cin>>n;
	hen=new Morgh[n];

	for(int i=0;i<n;i++)
		farm.AddMorgh(&hen[i]);
	farm.Cycle();
	//system("cls");
	
	cout<<"Total ghodghod is :"<<farm.totalGhodghod<<endl;



	delete []hen;
	system("pause");
	return 1905;

}