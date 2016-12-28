
#include "DynamicArray.h"
#include "Vector2D.h"
#include <iostream>
#include "Farm.h"
using namespace std;
#ifndef MORGH_H_
#define MORGH_H_
class Morgh
{
	Vector2D position;
	Farm* farm_;
	public:
	Morgh(Farm *a);
	void speak();
	void setPosition(float x, float y);
	void move();
	Vector2D getPosition();
	bool collides(Morgh * m);
};

#endif /* MORGH_H_ */
