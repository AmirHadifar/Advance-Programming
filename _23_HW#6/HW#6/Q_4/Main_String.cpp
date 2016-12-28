#include <iostream>
#include "MYString.h"
using namespace std;
int Strlen(const char* chptr)
{

	int i=0;
	while(chptr[i]!='\0')
		i++;
	return i;
}
void Strcpy(char* des,const char* era)
{
	int i=0;
	for(i=0;era[i]!='\0';i++)
		des[i]=era[i];
	des[i]='\0';
}
template <class T>
int Strcmp(const MYString<T>& str1,const char* str2)
{
	int len_first=str1.count();
	int len_sec=Strlen(str2);
	int size=(len_first<=len_sec)?len_sec:len_first;
	if(size!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(str1.item(i)>str2[i])
				return 1;
			else if(str1.item(i)<str2[i])
				return -1;
			else if(str1.item(i)==str2[i] && i==size-1)
				return 0;
		}
	}
	else
		return 0;
	return 0;
}
//=========================================================
template <class T1,class T2>
int Strcmp(const MYString<T1>& str1,const MYString<T2>& str2)
{
	int len_first=str1.count();
	int len_sec=str2.count();
	int size=(len_first<=len_sec)?len_sec:len_first;
	if(size!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(str1.item(i)>str2.item(i))
				return 1;
			else if(str1.item(i)<str2.item(i))
				return -1;
			else if(str1.item(i)==str2.item(i) && i==size-1)
				return 0;
		}
	}
	else
		return 0;
	return 0;
}
//===================================================
ostream& operator <<(ostream &out, const MYString<char> &s)
{
		for (int i = 0; i < s.length(); ++i)
			out << s[i];
		return out;
}
//=========================================================
istream& operator >>(istream &in, MYString<char> &s)
{
		char temp[1000];
		in >> temp;
		s.set(temp);
		return in;
}
MYString<char> operator+ (const char* str1, MYString<char> str2)
{
	MYString<char> temp;
	for(int i=0;i<Strlen(str1);i++)
		temp.append(str1[i]);
	for(int i=Strlen(str1);i<Strlen(str1)+str2.length();i++)
		temp.append(str2.item(i-str2.length()));
	return temp;
}
//===========================================================
MYString<char> operator+ (const char str1, MYString<char> str2)
{
	MYString<char> temp;
	temp.append(str1);
	for(int i=1;i<1+str2.length();i++)
		temp.append(str2.item(i-str2.length()));
	return temp;
}
int main()
{
	
	MYString<char> x("Amir");
	MYString<char> y(" Hadifar");
	cout<<x<<endl;
	cout<<y<<endl;
	x+=y;
	cout<<x<<endl;
	

	system("pause");
	return 1905;
}