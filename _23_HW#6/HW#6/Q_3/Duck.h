#include "DynamicArray.h"
#include "Vector2D.h"
#include "FarmBird.h"
#include <iostream>
using namespace std;
#ifndef DUCK_H_
#define DUCK_H_
class Duck : public AbstractFarmBird
{
	public:
	virtual void speak()
	{
		cout <<" Quak QUak! " <<endl;
	}
};


#endif /* DUCK_H_ */
