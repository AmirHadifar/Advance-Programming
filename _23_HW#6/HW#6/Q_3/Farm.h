#ifndef FARM_H_
#define FARM_H_
#include "DynamicArray.h"
#include "FarmBird.h"
class Farm
{
	DynamicArray<AbstractFarmBird*> bird;

public:
	static const int width = 640;
	static const int height = 480;
	int totalspeak;
	Farm() :
		totalspeak(0)
	{

	}
	void AddBird(AbstractFarmBird * m)
	{
		m->setPosition(rand() % Farm::width, rand() % Farm::height);
		bird.append(m);
	}
	void RemoveBird(int index)
	{
		bird.remove(index);
	}
	void Cycle()
	{
		for (int i = 0; i < bird.count(); ++i)
			bird[i]->move(rand() % 5, rand() % 5);

		for (int j = 0; j < bird.count(); ++j)
			for (int i = 0; i < bird.count(); ++i)
				if (i != j && bird[i]->collides(bird[j]))
				{
					bird[i]->speak();
					this->totalspeak++;
				}
	}
};

#endif /* FARM_H_ */
