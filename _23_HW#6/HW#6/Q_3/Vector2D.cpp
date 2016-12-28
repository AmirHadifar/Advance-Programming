#include "Vector2D.h"
#include <math.h>


Vector2D Vector2D::operator --(int temp)
{
	Vector2D t(*this);
	x--;
	y--;
	return t;
}



bool Vector2D::operator >=(const Vector2D v) const
{
	return (this->lengthSquared()>= v.lengthSquared());
}



float Vector2D::lengthSquared() const
{
	return (x*x)+(y*y);
}



Vector2D & Vector2D::operator =(const Vector2D &v)
{
	set(v);
	return *this;
}



Vector2D & Vector2D::operator +=(const Vector2D v)
{
	set(this->getX()+v.getX(),this->getY()+v.getY());
	return *this;
}



Vector2D::Vector2D(const float tx, const float ty)
:x(tx),y(ty)
{

}



Vector2D & Vector2D::operator -=(const Vector2D v)
{
	set(this->getX()-v.getX(),this->getY()-v.getY());
	return *this;
}



float Vector2D::getY() const
{
	return y;
}



Vector2D Vector2D::operator +(const Vector2D v) const
{
	return Vector2D(this->getX()+v.getX(),this->getY()+v.getY());
}



Vector2D::Vector2D()
{
}



float Vector2D::operator *(const Vector2D v) const
{
	return (this->getX()*v.getX()+this->getY()*v.getY());

}



Vector2D::Vector2D(const Vector2D & copy)
{
	set(copy);
}



bool Vector2D::operator <(const Vector2D v) const
{
	return (this->lengthSquared()<v.lengthSquared());
}



Vector2D Vector2D::direction() const
{
	return Vector2D(this->getX()/this->length(),this->getY()/this->length());
}



void Vector2D::set(const Vector2D &v)
{
	this->setX(v.getX());
	this->setY(v.getY());
}

Vector2D operator *(const int coeffiecient, const Vector2D v)
{
	return Vector2D(v.getX()*coeffiecient, v.getY()*coeffiecient);
}

Vector2D Vector2D::operator /(const int coefficient) const
{
	return Vector2D(this->getX()/coefficient,this->getY()/coefficient);
}

Vector2D & Vector2D::operator *=(const int coefficient)
{
	this->set(this->getX()*coefficient,this->getY()*coefficient);
	return *this;
}



Vector2D Vector2D::operator ++(int temp)
{
	Vector2D t(*this);
	x++;
	y++;
	return t;
}



Vector2D::~Vector2D()
{

}



bool Vector2D::operator ==(const Vector2D v) const
{
	return (this->getX()==v.getX() && this->getY()==v.getY());
}



void Vector2D::doError()
{
	int b=0;
	int a=10/b;
	b=a;
}



float Vector2D::getX() const
{
	return x;
}



Vector2D Vector2D::operator -() const
{
	return Vector2D(-this->getX(),-this->getY());
}



Vector2D Vector2D::operator +() const
{
	return Vector2D(+this->getX(),+this->getY());
}




float Vector2D::length() const
{
	return sqrt(this->lengthSquared());
}



bool Vector2D::operator <=(const Vector2D v) const
{
	return (this->lengthSquared()<=v.lengthSquared());
}



bool Vector2D::operator >(const Vector2D v) const
{
	return (this->lengthSquared()>v.lengthSquared());
}



void Vector2D::setX(const float x)
{
	this->x=x;
}



Vector2D Vector2D::operator *(const int coefficient) const
{
	return Vector2D(this->getX()*coefficient,this->getY()*coefficient);
}



Vector2D Vector2D::operator -(const Vector2D v) const
{
	return Vector2D(this->getX()-v.getX(),this->getY()-v.getY());
}



void Vector2D::set(const float x, const float y)
{
	this->setX(x);
	this->setY(y);
}



void Vector2D::setY(const float y)
{
	this->y=y;
}



Vector2D & Vector2D::operator --()
{
	x--;
	y--;
	return *this;
}




bool Vector2D::operator !=(const Vector2D v) const
{
	return (this->lengthSquared()!=v.lengthSquared());
}



Vector2D & Vector2D::operator ++()
{
	x++;
	y++;
	return *this;
}

Vector2D & Vector2D::operator /=(const int coefficient)
{
	this->set(this->getX()/coefficient,this->getY()/coefficient);
	return *this;
}





