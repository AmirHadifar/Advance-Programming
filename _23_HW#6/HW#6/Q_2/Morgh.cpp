#include"Morgh.h"
Morgh::Morgh(Farm *a)
{
	farm_ = a;
}
void Morgh::speak()
{
	cout <<" Ghod Ghod Ghodaa " <<endl;
}
void Morgh::setPosition(float x, float y)
{
	position.set(x,y);
}
void Morgh::move()
{
	Vector2D v(rand() % 5, rand() % 5);
	position+=v;
	for (int i = 0; i < (farm_)->morgh.count(); ++i)
		if (collides((farm_)->morgh[i]))
		{
				(farm_)->morgh[i]->speak();
				(farm_)->totalGhodghod++;
		}
}
Vector2D Morgh::getPosition()
{
	return position;
}
bool Morgh::collides(Morgh * m)
{
	if(this != m)
		return (m->getPosition() - this->getPosition()).lengthSquared() < 4 ;
	else
		return 0;
}