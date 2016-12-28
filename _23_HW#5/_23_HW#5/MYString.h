#include <iostream>
#include "DynamicArray.h"
using namespace std;

#ifndef MYString_H_
#define MYString_H_

class MYString
{

	//iostream operators
	friend ostream& operator <<(ostream&, const MYString&);
	friend istream& operator >>(istream&, MYString& );
	friend int Strcmp(const MYString&,const MYString&);
	friend int Strcmp(const MYString&,const char*);

private:
	DynamicArray<char>instance;		//for managing memory by DynamicArray class

public:

	MYString();						//no-arg constructor
	MYString(const char*);			//1-arg (pointer to char) constructor
	MYString(const unsigned int);			//1-arg (integer) constructor
	MYString(const MYString&);			//copy constructor
	~MYString();						//destructor


	//setters
	void set(const char*);
	void set(const MYString&);
	int count() const		//alias of length
	{
		return length();
	}
	int length() const		//string length
	{
		return instance.count();
	}


	//functions of MYString

	
	MYString subMYString(const int, const int) const;
	MYString substr(const int, const int) const;
	int position(const MYString, const int) const;
	int position(const char*, const int) const;

	
	//arithmetic operators

	MYString operator+ (const MYString);
	friend MYString operator+ (const char*, MYString);
	friend MYString operator+ (const char, MYString);

	//comparison operators

	bool operator!=(const MYString) const;
	bool operator!=(const char* ) const;

	bool operator==(const MYString) const;
	bool operator==(const char* ) const;

	bool operator<=(const MYString) const;
	bool operator<=(const char* ) const;

	bool operator>=(const MYString) const;
	bool operator>=(const char* ) const;

	bool operator< (const MYString) const;
	bool operator< (const char* ) const;

	bool operator> (const MYString) const;
	bool operator> (const char* ) const;


	//assignment operator

	MYString& operator= (const MYString&);
	MYString& operator= (const char*  );

	//compound assignment operators

	MYString& operator-=(const int charcount);

	MYString& operator+=(const char);
	MYString& operator+=(const MYString&);

	//access operators

	char& operator [](int index)	//access
{
	return instance[index];
}

const char& operator [](const int index) const	 // const (read_only)
{
	return instance[index];
}

char& operator() (const int index)
{
	return(*this)[index];
}

MYString operator ()(const int start, const int end) const
{
	return this->subMYString(start, end - start + 1);
}

	
};

#endif /* MYString_H_ */
