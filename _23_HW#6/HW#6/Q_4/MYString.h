#include <iostream>
#include "DynamicArray.h"
using namespace std;

#ifndef MYString_H_
#define MYString_H_

template <class T>
class MYString : public DynamicArray<T>
{

	//iostream operators
	
	friend ostream& operator <<(ostream&, const MYString&);
	friend istream& operator >>(istream&, MYString& );
	friend int Strcmp(const MYString&,const MYString&);
	friend int Strcmp(const MYString&,const char*);
	
public:
	
	//=========================================================
	~MYString(){clear();}			//destructor
	//=========================================================
	MYString(){clear();}	//no-arg constructor
	//=========================================================
	MYString(const char* arg)			//1-arg (pointer to char) constructor
	{
		clear();
		for(int i=0;i<Strlen(arg);i++)
			append(arg[i]);
	}
	//=========================================================
	MYString(const unsigned int a)			//1-arg (integer) constructor
	{
		char temp[20];
		int r=0;
		int i=0;
		while(a!=0)
		{
			r=a%10;
			a/=10;
			temp[i++]=r+'0';//integer to char
		}
		for(int j=i-1;j>-1;j--)
			append(temp[j]);
	}
	//=========================================================
	MYString(const MYString& copy)			//copy constructor
	{
		for(int i=0;i<copy.length();i++)
			append(copy.item(i));
	}


	//setters
	//=========================================================
	void set(const char* str)
	{
		clear();
		for(int i=0;i<Strlen(str);i++)
			append(str[i]);
	}
	//=========================================================
	void set(const MYString& str)
	{
		clear();
		for (int i = 0; i < str.count(); i++)
			append(str.item(i));
	}
	//=========================================================
	int length() const		//string length
	{
		return count();
	}
	//=========================================================
	
	//functions of MYString

	
	MYString subMYString(const int s, const int to) const
	{
		MYString temp;
		for(int i=s;i!=s+to;i++)
			temp.append(instance.item(i));
		return temp;
	}
//===========================================================
	MYString substr(const int s, const int to) const
	{
		MYString temp;
		for(int i=s;i!=s+to;i++)
			temp.append(instance.item(i));
		return temp;
	}
//===========================================================

	int position(const MYString, const int) const;
	int position(const char*, const int) const;

	
	//arithmetic operators

	//===========================================================
MYString operator+ (const MYString str)
{
	MYString temp;
	for(int i=0;i<length();i++)
		temp.append(item(i));
	for(int i=length();i<length()+str.length();i++)
		temp.append(item(i-length()));
	return temp;
}
//===========================================================

//===========================================================

	//comparison operators
	bool operator!=(const MYString str) const
	{
	return Strcmp(*this,str)!=0;
	}
	bool operator!=(const char* str) const
	{
		return Strcmp(*this,str)!=0;
	}
	bool operator==(const MYString str) const
	{
		return Strcmp(*this,str)==0;
	}
	bool operator==(const char* str ) const
	{
		return Strcmp(*this,str)==0;
	}
	bool operator<=(const MYString str) const
	{
		return Strcmp(*this,str)<=0;
	}
	bool operator<=(const char* str) const
	{
		return Strcmp(*this,str)<=0;
	}
	bool operator>=(const MYString str) const
	{
		return Strcmp(*this,str)>=0;
	}
	bool operator>=(const char* str ) const
	{
		return Strcmp(*this,str)>=0;
	}
	bool operator< (const MYString str) const
	{
		return Strcmp(*this,str)<0;
	}
	bool operator< (const char* str) const
	{
		return Strcmp(*this,str)<0;
	}
	bool operator> (const MYString str) const
	{
		return Strcmp(*this,str)>0;
	}
	bool operator> (const char* str ) const
	{
		return Strcmp(*this,str)>0;
	}

	

	//assignment operator

	//=========================================================
	MYString& operator= (const MYString& R)
	{
		clear();
		for(int i=0;i<R.length();i++)
			append(R.item(i));
		return *this;
	}
	//=========================================================
	MYString& operator= (const char* str )
	{
		int len=Strlen(str);
		instance.clear();
		for(int i=0;i<len;i++)
			instance.append(str[i]);
		return *this;
	}
	//=========================================================
	
	//compound assignment operators
	//===========================================================
	MYString& operator-=(const int charcount)
	{
		MYString temp;
		for(int i=charcount;i<count();i++)
			temp.instance.append(item(i));
		clear();
		*this=temp;
		return *this;
	}
	//===========================================================
	MYString& operator+=(const char str)
	{
		append(str);
		return *this;
	}
	//===========================================================
	MYString& operator+=(const MYString& str)
	{
		for(int i=0;i<str.count();i++)
			append(str.item(i));
		return *this;
	}


	//access operators
	
};

#endif /* MYString_H_ */
