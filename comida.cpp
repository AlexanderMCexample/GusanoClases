#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "comida.h"

using namespace std; 
void Comida::setSimbolo(char _simbolo)
{
    simbolo = _simbolo; 
}
void Comida::setPosX(int _x)
{
    pos_comida.setx(_x);
}
void Comida::setPosY(int _y)
{
    pos_comida.sety(_y);
}
void Comida::getPosX(int &_x)
{
    pos_comida.getx(_x);
}
void Comida::getPosY(int &_y)
{
    pos_comida.gety(_y);
}
int Comida::getPosX()
{
    return pos_comida.getx();
}
int Comida::getPosY()
{
    return pos_comida.gety();
}
void Comida::generar_aleatorio()
{
	srand(time(0));
	setPosX((rand()%(10-2))+1);
    setPosY((rand()%(10-2))+1);
}
char Comida::getSimbolo()
{
    return simbolo;
}

