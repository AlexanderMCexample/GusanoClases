#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "obstaculo.h"

using namespace std;   

void Obstaculo::setSimbolo(char _simbolo)
{
    simbolo = _simbolo; 
}
void Obstaculo::setPosX(int _x)
{
    pos.setx(_x);
}
void Obstaculo::setPosY(int _y)
{
    pos.sety(_y);
}

void Obstaculo::getPosX(int &_x)
{
    pos.getx(_x);
}
void Obstaculo::getPosY(int &_y)
{
    pos.gety(_y);
}
void Obstaculo::getSimbolo(char &_simbolo)
{
    _simbolo = simbolo;
}

void Obstaculo::cambioDireccion(std::string &_direccion, int gusanoX, int gusanoY)
{
    int obsX,obsY;
    getPosX(obsX);
    getPosY(obsY);

    if (obsX == gusanoX && obsY == gusanoY)
    {
        _direccion = "ARRIBA";
    } 
}