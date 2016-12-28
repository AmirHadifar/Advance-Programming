#include <iostream>
using namespace std;
int* Merge(int*,int);
int main()
{
	int number;
	cout<<"Merge Sort :\n\n";
	cout<<"How Many Numbers ?";cin>>number;

	int* Total_num=new int[number];
	
	for(int i=0;i<number;i++)
	{
		cout<<"Enter Num "<<i+1<<" :";cin>>Total_num[i];
	}

	Merge(Total_num,number);

	cout<<"\n\nAfter Sorting :\n\n";
	for(int i=0;i<number;i++)
			cout<<Total_num[i]<<" , ";
	

	delete []Total_num;
	cout<<"\n\n\n\n\n";
	system("pause");
	return 0;
}
//====================
int* Merge(int* T_num,int number)
{
	
	if(number>1)
	{
		int R_part=number/2;
		int L_part=R_part;
		
		if(number%2==1)
			L_part++;

		int* R_arr=new int[R_part];
		int* L_arr=new int[L_part];

		for(int i=0;i<R_part;i++)
			R_arr[i]=T_num[i];
		
		for(int i=R_part;i<R_part+L_part;i++)
			L_arr[i-R_part]=T_num[i];
		if(number%2==1)
		{
		R_arr=Merge(R_arr,number/2);
		L_arr=Merge(L_arr,(number/2)+1);
		}
		else
		{
		R_arr=Merge(R_arr,number/2);
		L_arr=Merge(L_arr,number/2);
		}
			
		int i=0,j=0,k=0;

		while(R_part!=j && L_part!=k)
		{
			if(R_arr[j]<L_arr[k])
			{
				T_num[i]=R_arr[j];
				i++;
				j++;
			}
			else
			{
				T_num[i]=L_arr[k];
				i++;
				k++;
			}
		}

		while(R_part!=j)
		{
			T_num[i]=R_arr[j];
			i++;
			j++;
		}
		while(L_part!=k)
		{
			T_num[i]=L_arr[k];
			i++;
			k++;
		}
	}
	return T_num;
}





