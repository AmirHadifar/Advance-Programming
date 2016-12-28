#ifndef MYVECTOR_H
#define MYVECTOR_H

class MYVector
{
private:
	float x,y;
public:
	//constructors & destructors
	MYVector(const float,const float);
	MYVector();
	MYVector(const MYVector&);
	~MYVector();

	
	//unit vector
	MYVector direction()const;
	MYVector normalize()const{return direction();}

	//vector size
	float length()const;
	float lengthSquared()const;
	
	//setters & getters
	void set(const float,const float);
	void set(const MYVector&);
	void setX(const float);
	void setY(const float);
	float getX()const{return x;}
	float getY()const{return y;}

	//Comparison operators
	bool operator < (const MYVector&)const;
	bool operator > (const MYVector&)const;
	bool operator ==(const MYVector&)const;
	bool operator >=(const MYVector&)const;
	bool operator <=(const MYVector&)const;
	bool operator !=(const MYVector&)const;

	//unary operator
	MYVector operator +()const;
	MYVector operator -();
	MYVector& operator--();
	MYVector& operator++();
	MYVector operator--(int);
	MYVector operator++(int);

	//binary operator
	MYVector operator *(const int);
	MYVector operator -(const MYVector&);
	MYVector operator /(const int );
	friend MYVector operator +(const MYVector&,const MYVector&);
	friend float operator*(const MYVector&,const MYVector&);
	friend MYVector operator*(const int,const MYVector);

	//binary assignment operator
	MYVector& operator +=(const MYVector&);
	MYVector& operator -=(const MYVector&);
	MYVector& operator = (const MYVector&);
	MYVector& operator /=(const int);
	MYVector& operator *=(const int);

	//access operator
	float& operator ()(const int);
	float& operator [](const char);
	float& operator ()(const char);
	float& operator [](const int );
	
	//doError
	void doError();
	
};

#endif