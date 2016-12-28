#include "MYString.h"
#include "DynamicArray.h"
//=========================================================
void Strcpy(char* des,const char* era)
{
	int i=0;
	for(i=0;era[i]!='\0';i++)
		des[i]=era[i];
	des[i]='\0';
}
//=========================================================
int Strlen(const char* chptr)
{

	int i=0;
	while(chptr[i]!='\0')
		i++;
	return i;
}
//=========================================================
int Strcmp(const MYString& str1,const char* str2)
{
	int len_first=str1.instance.count();
	int len_sec=Strlen(str2);
	int size=(len_first<=len_sec)?len_sec:len_first;
	if(size!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(str1.instance.item(i)>str2[i])
				return 1;
			else if(str1.instance.item(i)<str2[i])
				return -1;
			else if(str1.instance.item(i)==str2[i] && i==size-1)
				return 0;
		}
	}
	else
		return 0;
	return 0;
}
//=========================================================
int Strcmp(const MYString& str1,const MYString& str2)
{
	int len_first=str1.instance.count();
	int len_sec=str2.instance.count();
	int size=(len_first<=len_sec)?len_sec:len_first;
	if(size!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(str1.instance.item(i)>str2.instance.item(i))
				return 1;
			else if(str1.instance.item(i)<str2.instance.item(i))
				return -1;
			else if(str1.instance.item(i)==str2.instance.item(i) && i==size-1)
				return 0;
		}
	}
	else
		return 0;
	return 0;
}
//=========================================================
ostream& operator <<(ostream &out, const MYString &s)
{
		for (int i = 0; i < s.length(); ++i)
			out << s[i];
		return out;
}
//=========================================================
istream& operator >>(istream &in, MYString &s)
{
		char temp[1000];
		in >> temp;
		s.set(temp);
		return in;
}
//=========================================================
void MYString::set(const char* str)
{
	instance.clear();
	for(int i=0;i<Strlen(str);i++)
		instance.append(str[i]);
}
//=========================================================
void MYString::set(const MYString& str)
{
		instance.clear();
		for (int i = 0; i < str.count(); i++)
			instance.append(str.instance.item(i));
}
//=========================================================
MYString& MYString::operator =(const char* str)
{
	int len=Strlen(str);
	instance.clear();
	for(int i=0;i<len;i++)
		instance.append(str[i]);
	return *this;
}
//=========================================================
MYString& MYString::operator=(const MYString& R)
{
	instance.clear();
	for(int i=0;i<R.length();i++)
		instance.append(R.instance.item(i));
	return *this;
}
//=========================================================
MYString::MYString()
{
	instance.clear();
}
//=========================================================
MYString::~MYString()
{	instance.~DynamicArray();	}
//=========================================================
MYString::MYString(const char* arg)
{
	instance.clear();
	for(int i=0;i<Strlen(arg);i++)
		instance.append(arg[i]);
}
////=========================================================
MYString::MYString(const MYString& copy)
{
	for(int i=0;i<copy.length();i++)
		instance.append(copy.instance.item(i));
}
//=========================================================
MYString::MYString(unsigned int a)
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
		instance.append(temp[j]);
}
//===========================================================
bool MYString::operator!=(const MYString str) const
{
	return Strcmp(*this,str)!=0;
}
bool MYString::operator!=(const char* str) const
{
	return Strcmp(*this,str)!=0;
}
bool MYString::operator==(const MYString str) const
{
	return Strcmp(*this,str)==0;
}
bool MYString::operator==(const char* str ) const
{
	return Strcmp(*this,str)==0;
}
bool MYString::operator<=(const MYString str) const
{
	return Strcmp(*this,str)<=0;
}
bool MYString::operator<=(const char* str) const
{
	return Strcmp(*this,str)<=0;
}
bool MYString::operator>=(const MYString str) const
{
	return Strcmp(*this,str)>=0;
}
bool MYString::operator>=(const char* str ) const
{
	return Strcmp(*this,str)>=0;
}
bool MYString::operator< (const MYString str) const
{
	return Strcmp(*this,str)<0;
}
bool MYString::operator< (const char* str) const
{
	return Strcmp(*this,str)<0;
}
bool MYString::operator> (const MYString str) const
{
	return Strcmp(*this,str)>0;
}
bool MYString::operator> (const char* str ) const
{
	return Strcmp(*this,str)>0;
}
//===========================================================
MYString MYString::operator+ (const MYString str)
{
	MYString temp;
	for(int i=0;i<length();i++)
		temp.instance.append(instance.item(i));
	for(int i=length();i<length()+str.length();i++)
		temp.instance.append(instance.item(i-length()));
	return temp;
}
//===========================================================
MYString operator+ (const char* str1, MYString str2)
{
	MYString temp;
	for(int i=0;i<Strlen(str1);i++)
		temp.instance.append(str1[i]);
	for(int i=Strlen(str1);i<Strlen(str1)+str2.length();i++)
		temp.instance.append(str2.instance.item(i-str2.length()));
	return temp;
}
//===========================================================
MYString operator+ (const char str1, MYString str2)
{
	MYString temp;
	temp.instance.append(str1);
	for(int i=1;i<1+str2.length();i++)
		temp.instance.append(str2.instance.item(i-str2.length()));
	return temp;
}
//===========================================================
MYString& MYString::operator-=(const int charcount)
{
	MYString temp;
	for(int i=charcount;i<instance.count();i++)
		temp.instance.append(instance.item(i));
	instance.clear();
	*this=temp;
	return *this;
}
//===========================================================
MYString& MYString::operator+=(const char str)
{
	instance.append(str);
	return *this;
}
//===========================================================
MYString& MYString::operator+=(const MYString& str)
{
	for(int i=0;i<str.instance.count();i++)
		instance.append(str.instance.item(i));
	return *this;
}
//===========================================================

MYString MYString::subMYString(const int s, const int to) const
{
	MYString temp;
	for(int i=s;i!=s+to;i++)
		temp.instance.append(instance.item(i));
	return temp;
}
//===========================================================
MYString MYString::substr(const int s, const int to) const
{
	MYString temp;
	for(int i=s;i!=s+to;i++)
		temp.instance.append(instance.item(i));
	return temp;

}
//===========================================================