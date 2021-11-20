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

    if (obsY == gusanoY-1 && _direccion == "ARRIBA")//obtener valres de gusano 
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
    } 
    else if (obsY == gusanoY+1 && _direccion == "ABAJO")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
    } 
    else if (obsX == gusanoX+1 && _direccion == "DERECHA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
    }
    else if (obsX == gusanoX-1 && _direccion == "IZQUIERDA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
    }
}
void Obstaculo::direccionDisponible(std::string &_direccion, int gusanoX, int gusanoY)
{
    if (0 == gusanoY-1)//si en una dirección esta vacia el gusano rebotará en esa direccion
    {
        _direccion = "ARRIBA";
    } 
    else if (0 == gusanoY+1)
    {
        _direccion = "ABAJO";
    } 
    else if (0 == gusanoX+1)
    {
        _direccion = "DERECHA";
    }
    else if (0 == gusanoX-1)
    {
        _direccion = "IZQUIERDA";
    }
    //else direccion = lose
}

