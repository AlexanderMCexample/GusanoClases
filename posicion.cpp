#include <iostream>
#include "posicion.h"

using namespace std;   

void Posicion::setx(int _x)
{
	x=_x;
}
void Posicion::sety(int _y)
{
	y=_y;
}
void Posicion::getx(int &_x)
{
	_x=x;
}
void Posicion::gety(int &_y)
{
	_y=y;
}
int Posicion::getx()
{
	return x;
}
int Posicion::gety()
{
	return y;
}
