#include <iostream>
#include "posicion.h"

using namespace std;   

void Posicion::setx(int _x)  //Método que nos servira para establecer una posición X
{
	x=_x;
}
void Posicion::sety(int _y) //Método que nos servira para establecer una posición X
{
	y=_y;
}
void Posicion::getx(int &_x) //Método que nos servira para llamar X anteriormente establecida
{
	_x=x;
}
void Posicion::gety(int &_y) //Método que nos servira para llamar Y anteriormente establecida
{
	_y=y;
}
int Posicion::getx() //Return de la posición X
{
	return x;
}
int Posicion::gety() //Return de la posición Y
{
	return y;
}

void Posicion::incrementarX(int _x) //aumentar o disminuir el valor la coordenada x
{
	x+=_x;
}

void Posicion::incrementarY(int _y) //aumentar o disminuir el valor la coordenada y
{
	y+=_y;
}
