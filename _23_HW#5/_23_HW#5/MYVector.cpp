#include <iostream>
#include <cmath>
#include "MYVecotr.h"
using namespace std;
//==========================================================
MYVector::MYVector():x(0),y(0) {}
//==========================================================
MYVector::MYVector(const float X,const float Y):x(X),y(Y) {}
//==========================================================
MYVector::MYVector(const MYVector& right)
{
	x=right.x;
	y=right.y;
}
//==========================================================
MYVector::~MYVector()
{
	x=0;
	y=0;
}
//==========================================================
float MYVector::length()const
{
	return sqrt(pow(x,2)+pow(y,2));
}
//==========================================================
float MYVector::lengthSquared()const
{
	return (pow(this->length(),2));
}
//==========================================================
MYVector MYVector::direction()const
{
	float unit=this->length();
	return MYVector((this->x)/unit,(this->y)/unit);//return Temporary Nameless Object
}
//==========================================================
void MYVector::set(const float X,const float Y)
{
	x=X;
	y=Y;
}
//==========================================================
void MYVector::set(const MYVector& vec)
{
	x=vec.x;
	y=vec.y;
}
//==========================================================
void MYVector::setX(const float X)
{	x=X;	}
//==========================================================
void MYVector::setY(const float Y)
{	y=Y;	}
//==========================================================
bool MYVector::operator<(const MYVector &vec)const
{
	return ( this->length() < vec.length() );
}
//==========================================================
bool MYVector::operator<=(const MYVector &vec)const
{
	return ( this->length() <= vec.length() );
}
//==========================================================
bool MYVector::operator>(const MYVector& vec)const
{
	return ( this->length() > vec.length() );
}
//==========================================================
bool MYVector::operator>=(const MYVector& vec)const
{
	return ( this->length() >= vec.length() );
}
//==========================================================
bool MYVector::operator==(const MYVector& vec)const
{
	return ( this->length() == vec.length() );
}
//==========================================================
bool MYVector::operator!=(const MYVector& vec)const
{
	if(x!=vec.x && y!=vec.y)
		return true;
	else
		return false;
}
//=========================================================
MYVector MYVector::operator +()const
{	return *this;	}
//=========================================================
MYVector MYVector::operator -()
{
	MYVector temp=*this;
	temp.x*=-1;
	temp.y*=-1;
	return temp;
}
//=========================================================
MYVector& MYVector::operator--()
{
	(this->x)-=1;
	(this->y)-=1;
	return *this;
}
//=========================================================
MYVector& MYVector::operator++()
{
	(this->x)+=1;
	(this->y)+=1;
	return *this;
}
//=========================================================
MYVector MYVector::operator--(int)
{
	MYVector temp=*this;
	(this->x)--;
	(this->y)--;
	return temp;
}
//=========================================================
MYVector MYVector::operator++(int)
{
	MYVector temp=*this;
	(this->x)++;
	(this->y)++;
	return temp;
}
//=========================================================
MYVector MYVector::operator *(const int a)
{
	return MYVector(this->x*a,this->y*a);
}
//=========================================================
MYVector MYVector::operator -(const MYVector& vec)
{
	float x1=this->x-vec.x;
	float y1=this->y-vec.y;
	return MYVector(x1,y1);
}
//=========================================================
MYVector MYVector::operator /(const int a)
{
	return MYVector(this->x/a,this->y/a);
}
//=========================================================
MYVector operator +(const MYVector& vec1,const MYVector& vec2)
{
	float X=vec1.x+vec2.x;
	float Y=vec1.y+vec2.y;
	return MYVector(X,Y);
}
//=========================================================
float operator*(const MYVector& vec1,const MYVector& vec2)
{
	float scalar=vec1.x*vec2.x+vec1.y*vec2.y;
	return scalar;
}
//=========================================================
 MYVector operator *(const int a,const MYVector vec)
{
	return MYVector(vec.x*a,vec.y*a);
}
//=========================================================
MYVector& MYVector::operator +=(const MYVector& vec)
{
	this->x+=vec.x;
	this->y+=vec.y;
	return *this;
}
//=========================================================
MYVector& MYVector::operator -=(const MYVector& vec)
{
	(this->x)-=vec.x;
	(this->y)-=vec.y;
	return *this;
}
//=========================================================
MYVector& MYVector::operator = (const MYVector& vec)
{
	(this->x)=vec.x;
	(this->y)=vec.y;
	return *this;
}
//=========================================================
MYVector& MYVector::operator /=(const int a)
{
	(this->x)/=a;
	(this->y)/=a;
	return *this;
}
//=========================================================
MYVector& MYVector::operator *=(const int a)
{
	this->x*=a;
	this->y*=a;
	return *this;
}
//=========================================================
float& MYVector::operator()(const char specifier)
{
	return (*this)[specifier];
}
//=========================================================
float& MYVector::operator()(const int index)
{
	return (*this)[index];
}
//=========================================================
float& MYVector::operator [](const char specifier)				// to access v['x'] and v['y']
{
		if (specifier == 'x' || specifier == 'X')
			return x;
		if (specifier == 'y' || specifier == 'Y')
			return y;
		return x;
}
//=========================================================
float& MYVector::operator [](const int index)					// to access v[0] and v[1]
{
		if (index<2 && index>=0)
			return (&x)[index];
		doError();
		return x;
}
//=========================================================
void MYVector::doError()
{
	cout<<"Fatal Error !"<<endl;
	int b = 0;
	int a = 10 / b;
	b = a;
}
//=========================================================