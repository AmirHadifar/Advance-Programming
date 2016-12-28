#include"Farm.h"
#include"Morgh.h"
Farm::Farm() :
	totalGhodghod(0){}
void Farm::AddMorgh(Morgh * m)
{
	m->setPosition(rand() % Farm::width, rand() % Farm::height);
	morgh.append(m);
}
void Farm::RemoveMorgh(int index)
{
	morgh.remove(index);
}
void Farm::Cycle()
{
	for (int i = 0; i < morgh.count(); ++i)
		morgh[i]->move();
}