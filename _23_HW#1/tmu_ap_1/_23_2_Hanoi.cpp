//HomeWork_1_2
//Displacement of Hanoi tower
#include <iostream>
using namespace std;
void start(int&);                // for get number of the disk
void Hanoi(int,char,char,char); // for display replacement
//=======================
int main()
{
    int N_disk;
    start(N_disk);             // get number of the disk
	cout<<endl<<endl;
	system("pause");
    return 0;
} 
//=======================
void start(int& Ndisk)
{ 
	cout<<"Displacement in Hanoi Tower \n\n"<<endl;
	cout<<"Enter number of the disk :";cin>>Ndisk;
	cout<<endl<<endl;
	Hanoi(Ndisk,'A','B','C'); // Calling function for replacement
}
//~~~~~~~~~~~~~~~~~~~~~~
void Hanoi(int Ndisk, char A,char B,char C)
{
    if(Ndisk == 1)
    {
            cout<<"\n Disk 1 from "<<A<<" to "<<C;            
    }
    else
    {
        Hanoi(Ndisk-1,A,C,B); //A goes to B
        cout<<"\n Disk "<<Ndisk<<" from "<<A<<" to "<<C;
        Hanoi(Ndisk-1,B,A,C); //B goes to C
    }
}
//~~~~~~~~~~~~~~~~~~~~