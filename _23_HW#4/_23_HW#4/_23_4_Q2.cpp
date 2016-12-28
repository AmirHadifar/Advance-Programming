//String Class include
//< append,erase, string=const char* , string=string , string +=string , ... >
#include <iostream>
using namespace std;
class String
{
private:
	int length;
	char* chptr;
public:
	~String();
	String(const char* ="");
	String(const String&);
	int Size();
	void Erase(int,int);//erase from parameter 1 to parameter 2
	void Erase(int);// erase from parameter untill end of string
	void Erase();//erase all character of string
	void Append(const String&);
	String& operator +=(const String&);
	String& operator = (const String&);
	String& operator = (const char*);
	friend ostream& operator << (ostream&,const String&);
	friend istream& operator >> (istream&,String&);
};
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
ostream& operator<<(ostream& strm , const String& S)
{
	strm<<S.chptr;
	return strm;
}
//=========================================================
istream& operator>>(istream& strm , String& Str)
{
	if(Strlen(Str.chptr)>0)
		delete []Str.chptr;
	char sth[500];
	strm>>sth;
	Str.chptr=new char[Strlen(sth)+1];
	Strcpy(Str.chptr,sth);
	return strm;
}
//=========================================================
String& String::operator =(const char* str)
{
	int len=Strlen(str);
	if(length>0)
		delete []chptr;
	length=len;
	chptr=new char[len+1];
	Strcpy(chptr,str);
	return *this;
}
//=========================================================
String& String::operator=(const String& R)
{
	if(length>0)
		delete []chptr;
	length=R.length;
	chptr=new char[length+1];
	Strcpy(chptr,R.chptr);
	return *this;
}
//=========================================================
String::~String()
{	delete []chptr;	}
//=========================================================
String::String(const char* arg):length((arg!=0)?Strlen(arg):0)
{
	chptr=new char[Strlen(arg)+1];
	int i;
	for(i=0;arg[i]!='\0';i++)
		chptr[i]=arg[i];
	chptr[i]='\0';
}
//=========================================================
String::String(const String& copy)
{
	int i;
	length=copy.length; // copy length
	chptr=new char[length+1];
	for(i=0;copy.chptr[i]!='\0';i++)
		chptr[i]=copy.chptr[i];	// copy string
	chptr[i]='\0';
}
//=========================================================
void String::Erase()
{
	int size=(*this).Size(); // length of the String
	for(int i=0;i<size;i++)
		chptr[i]='\0';
}
//=========================================================
void String::Erase(int From)// from : make string null at From to end of the String
{
	int size=(*this).Size();
	
	if(From > size || From < 0 )
	{
		cout<<"This application has requested the Runtime to terminate it in an unsual way."<<endl
			<<"Please enter the appropriate input."<<endl;
	}
	else
	{
		for(int i=From; i<size; i++)
			chptr[i]='\0';
	}
}
//=========================================================
void String::Erase(int beg,int len_del)
{

	int size=(*this).Size(); // length of the String
	
	if( beg < 0 || len_del < 0 || beg > size)
	{
		cout<<"This application has requested the Runtime to terminate it in an unsual way."<<endl
			<<"Please enter the appropriate input."<<endl;
	}
	else
	{
		if(size < len_del ) 
			for(int i=beg;i<size;i++)
				chptr[i]='\0';
		else
			for(int i=beg;i<(beg+len_del);i++)
				for(int j=beg;chptr[j]!='\0';j++)
                    chptr[j]=chptr[j+1];
	}
}
//=========================================================
void String::Append(const String& app)
{
	char* temp=new char[strlen(this->chptr)+1];
	Strcpy(temp,chptr);
	delete []chptr;
	chptr=0;
	chptr=new char[app.length+Strlen(temp)+1];
	int i,j;
	for(i=0;temp[i]!='\0';i++)
		chptr[i]=temp[i];
	for(j=0;app.chptr[j]!='\0';j++)
		chptr[i+j]=app.chptr[j];
	chptr[i+j]='\0';
	delete []temp;
}
//=========================================================
int String::Size()
{
	int i=0;
	while(chptr[i]!='\0')
		i++;
	return i;
}
//=========================================================
String& String::operator += (const String& app)
{
	char* temp=new char[strlen(this->chptr)+1];
	Strcpy(temp,chptr);
	delete []chptr;
	chptr=0;
	chptr=new char[app.length+Strlen(temp)+1];
	int i,j;
	for(i=0;temp[i]!='\0';i++)
		chptr[i]=temp[i];
	for(j=0;app.chptr[j]!='\0';j++)
		chptr[i+j]=app.chptr[j];
	chptr[i+j]='\0';
	delete []temp;
	return *this;

}
//=========================================================
int main()
{
	String a,b("Amir_hadifar");
	String c=b;
	cout<<"NO arg constructor :"<<a<<endl;
	cout<<"1 arg constructor :"<<b<<endl;
	cout<<"copy constructor :"<<c<<endl;
	a=b;
	cout<<"==============================\n"
		<<"assignment : a=b \n"
		<<" a :"<<a<<endl
		<<" b :"<<b<<endl;
	cout<<"==============================\n";
	cout<<"Enter first String :";cin>>a;
	cout<<"Enter second String :";cin>>b;
	cout<<"Append :\n";
		a.Append(b);
	cout<<a<<endl;
	cout<<"==============================\n"
		<<"Enter first String :";cin>>a;
	cout<<"Enter second String :";cin>>b;
	cout<<"+= operator :\n";
	a+=b;
	cout<<a<<endl;
	cout<<"Size of String a is :"<<a.Size()<<endl;
	cout<<"==============================\n";

	system("pause");
	return 1905;
}

