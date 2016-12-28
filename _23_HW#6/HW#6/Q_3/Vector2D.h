#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D
{
private:
	float x,y;												// member variables
	void doError();											// force error
public:
	//Constructors - Destructors
	Vector2D();												// default constructor
	~Vector2D();											// destructor
	Vector2D(const Vector2D & copy);						// copy constructor
	Vector2D(const float x,const float y);					// init constructor


	//Setters
	void set(const Vector2D &v);							// sets both x,y via another vector
	void set(const float x,const float y);					// sets both x,y
	void setX(const float x);								// sets only x
	void X(const float tx) {setX(tx);}						// alias for setting x
	void setY(const float y);								// sets only y
	void Y(const float ty) {setY(ty);}						// alias for setting y


	//Getters
	float getX() const;										// gets x
	float X() const { return getX();}						// alias for getting x
	float getY() const;										// gets y
	float Y() const { return getY();}						// alias for getting y

	//useful methods
	float lengthSquared() const;							// length squared, for comparison
	float length() const;									// length
	Vector2D direction() const;								// direction's unit vector
	Vector2D normalize() const {return direction();}		// alias for direction

	//unary prefix operators
	Vector2D operator +() const;							// +Vector, does nothing
	Vector2D operator -() const;							// -Vector
	Vector2D& operator --();								// --Vector
	Vector2D& operator ++();								// ++Vector

	//unary postfix operators
	Vector2D operator ++(int temp);							// Vector++
	Vector2D operator --(int temp);							// Vector--

	//binary arithmetic operators
	Vector2D operator +(const Vector2D v) const;			// Vector + v2
	Vector2D operator -(const Vector2D v) const;			// Vector - v2
	float operator *(const Vector2D v) const;				// Vector * v
	Vector2D operator *(const int coefficient) const;		// Vector * int
	Vector2D operator /(const int coefficient) const;		// Vector / int
	friend Vector2D operator *(const int coeffiecient, const Vector2D v);	//int * v

	//binary relational operators
	bool operator >(const Vector2D v) const;				// Vector > v
	bool operator <(const Vector2D v) const;				// Vector < v
	bool operator >=(const Vector2D v) const;				// Vector >= v
	bool operator <=(const Vector2D v) const;				// Vector <= v
	bool operator !=(const Vector2D v) const;				// Vector != v
	bool operator ==(const Vector2D v) const;				// Vector == v

	//binary assignment operators
	Vector2D& operator = (const Vector2D &v);				// Vector = v
	Vector2D& operator += (const Vector2D v);				// Vector += v
	Vector2D& operator -= (const Vector2D v);				// Vector -= v
	Vector2D& operator *= (const int coefficient);			// Vector *= int
	Vector2D& operator /= (const int coefficient);			// Vector /= int

	//access operators
	float & operator ()(const int index)					// to access v(0) and v(1)
	{
		return (*this)[index];
	}
	float & operator ()(const char specifier)				// to access v('x') and v('y')
	{
		return (*this)[specifier];
	}
	float & operator [](const int index)					// to access v[0] and v[1]
	{
		if (index<2 && index>=0)
			return (&x)[index];
		doError();
		return x;
	}
	float & operator [](const char specifier)				// to access v['x'] and v['y']
	{
		if (specifier == 'x' || specifier == 'X')
			return x;
		if (specifier == 'y' || specifier == 'Y')
			return y;
		doError();
		return x;
	}


};

#endif /* VECTOR2D_H_ */
