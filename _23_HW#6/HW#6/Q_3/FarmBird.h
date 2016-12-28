#ifndef FARMBIRD_H_
#define FARMBIRD_H_
#include "DynamicArray.h"
#include "Vector2D.h"
class AbstractFarmBird
{
	Vector2D position;
public:
	virtual void speak()=0;
	void setPosition(float x, float y)
	{
		position.set(x,y);
	}
	void move(float x, float y)
	{
		Vector2D v(x,y);
		position+=v;
	}
	Vector2D getPosition()
	{
		return position;
	}
	bool collides(AbstractFarmBird * m)
	{
		return (m->getPosition() - this->getPosition()).lengthSquared() < 4 ;
	}};

#endif /* FARMBIRD_H_ */
