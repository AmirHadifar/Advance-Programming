#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

const double PI=3.141596;
class Shape
{
public:
	virtual double Mohit()=0;
	virtual double Masahat()=0;
	virtual void setWidth(double)=0;
	virtual void setHeight(double)=0;
	virtual void getWidth()=0;
	virtual void getHeight()=0;
};
class Circle:public Shape
{
private:
	double r;
public:
	Circle():r(0.0) {}
	double Mohit()	{	return 2*PI*r;	}
	double Masahat(){	return PI*r*r;	}
	void setWidth(double x){	r=x;	}
	void setHeight(double x){	r=x;	}
	void getWidth()
	{	cout<<"Enter Radius of the Circle :";cin>>r;}
	void getHeight()
	{	cout<<"Enter Radius of the Circle :";cin>>r;}
};
class Triangle:public Shape
{
private:
	double h;
	double b;
	double x1;
	double x2;
	double x3;
public:
	Triangle():h(0),b(0),x1(h),x2(b),x3(b) {}
	double Mohit()
	{
		if(x1==0.0)
		{	x1=h;	
			x2=x3=b;
		}
		return x1+x2+x3;
	}
	double Masahat()	{	return (b*h)/2;	}
	void setWidth(double x){	b=x;	}
	void setHeight(double x){	h=x;	}
	void setSide(double s1,double s2,double s3){ x1=s1; x2=s2;	x3=s3;	}
	void getWidth()
	{	cout<<"Enter Base of the Triangle :";cin>>b;	}
	void getHeight()
	{	cout<<"Enter Height of the Triangle :";cin>>h;	}
	void getSide()
	{
		cout<<"Enter Side 1 :";cin>>x1;
		cout<<"Enter Side 2 :";cin>>x2;
		cout<<"Enter Side 3 :";cin>>x3;
	}
};
class Rectangle:public Shape
{
private:
	double h;
	double w;
public:
	Rectangle():h(0),w(0) {}
	double Mohit(){	return 2*(h+w);	};
	double Masahat(){	return h*w;	};
	void setWidth(double x){	w=x;	}
	void setHeight(double x){	h=x;	}
	void getWidth()
	{ cout<<"Enter Width of the Rectangle :";cin>>w;	}
	void getHeight()
	{	cout<<"Enter Height of the Rectangle :";cin>>h;	}
};
class Calc
{
	public:
	static double density(Shape* shape)
	{
		return shape->Masahat()/shape->Mohit();
	}
};
#endif