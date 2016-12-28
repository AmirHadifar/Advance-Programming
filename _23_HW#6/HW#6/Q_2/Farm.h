//#include "Morgh.h"
#include <math.h>
#include"DynamicArray.h"
#ifndef FARM_H_
#define FARM_H_
class Morgh;
class Farm
{
public:
	DynamicArray<Morgh*> morgh;
	static const int width = 640;
	static const int height = 480;
	int totalGhodghod;
	Farm();
	void AddMorgh(Morgh * m);
	void RemoveMorgh(int index);
	void Cycle();
};

#endif /* FARM_H_ */
