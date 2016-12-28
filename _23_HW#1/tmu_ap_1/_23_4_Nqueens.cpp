//HomeWork_1_4
//N Queens
#include <iostream>
#include <cmath>
using namespace std;
void display();
void Queens_finder(int ,int );
int size;
bool table[100][100]; // maximum of the boolean table is 100*100
//=============================
int main()
{
int x,y,num;
cout<<"Enter size of the table :";
cin>>num;
size=num;
cout<<"Enter Coordinate of first Queen(x,y)(0~n-1)?\n";
cin>>x>>y;
table[x][y]=1; // in the boolean table put true in place of the Entry coordinate

display();     // first table only with one queens displayed !

for(int i=0;i<size;i++)       // this loop checks all the place of the table that queens can insert !//
for(int j=0;j<size;j++)                                                                              // BACK TRACKING !
Queens_finder(i,j);          // function to check right answers !                                    //

    system("PAUSE");
    return 0;
}
//=============================
void Queens_finder(int x,int y)
{
	bool t=0;     // false 
	
	for(int j=0;j<size;j++)     // this loop checks all the horizontal & vertical that not possible to put next queens !
		if (table[x][j] || table[j][y]) t=1;  
 	for(int i=0;i<size;i++)     // this loop checks all the Diagonal that not possible to put next queens !
		for(int j=0;j<size;j++)
			if(abs(x-i)==abs(y-j) && table[i][j]) t=1;

	if (!t) // finaly
	{
		int Num_Queens_found=0;
		table[x][y]=1;
	
    	for(int i=0;i<size;i++)
        	for(int j=0;j<size;j++)
            	if (table[i][j])      
					Num_Queens_found++; // if the coordinate of the table is true it's shows that one queens found !
	
    	if (Num_Queens_found==size) // if number of the queens that found is equal to size of the table it display the answer
			display();
		for(int i=x;i<size;i++)    // back tracking algorithm !
			for(int j=0;j<size;j++)
				Queens_finder(i,j);
		table[x][y]=0;
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  display()
{
	for(int i=0;i<size;i++)     
	{
		for(int j=0;j<size;j++)        
			if (table[j][i])  // insert Q where coordinate is true 
				cout<<" Q";
			else
				cout<<" *"; // otherwise insert star 
		cout<<endl;
	}
	cout<<endl;      
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
