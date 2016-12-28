#ifndef MORGH_H_
#define MORGH_H_

#include "DynamicArray.h"
#include "Vector2D.h"
#include "FarmBird.h"
#include <iostream>
using namespace std;

class Morgh : public AbstractFarmBird
{
	public:
	virtual void speak()
	{
		cout <<" Ghod Ghod Ghodaa " <<endl;
	}

};

#endif /* MORGH_H_ */
