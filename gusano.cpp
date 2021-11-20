#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "gusano.h"

using namespace std;   

void Gusano::crecer()
{
    if(tamanoGusano <= maxTamanoGusano)
    {
        tamanoGusano++;
        //pos[tamanoGusano].setx(pos[tamanoGusano-1].getx());
        //pos[tamanoGusano].sety(pos[tamanoGusano-1].gety());
    }

}
void Gusano::reducir()
{
    if(tamanoGusano > 0) //para que no elimine la cabeza
    {
        //pos[tamanoGusano].setx(0);
        //pos[tamanoGusano].sety(0);
        tamanoGusano--;
    }
}
void Gusano::rebotar(std::string _direccion)
{
    _direccion = "";
}
void Gusano::perder()
{

}
void Gusano::setControlUno()
{
    control.defautControlUno();
}
void Gusano::setControlDos()
{
    control.defautControlDos();
}
void Gusano::movimientoConstante()
{
    control.getDireccion(direccion);
    if (direccion == "ARRIBA")
    {
        pos.incrementarY(-1);
    }
    else if (direccion == "ABAJO")
    {
        pos.incrementarY(1);
    }
    else if (direccion == "DERECHA")
    {
        pos.incrementarX(1);
    }
    else if (direccion == "IZQUIERDA")
    {
        pos.incrementarX(-1);
    }
}

void Gusano::controlUno()
{
    control.mando1();
}
void Gusano::controlDos()
{   
    control.mando2();
}

void Gusano::setSimbolo(char _simbolo)
{
    simbolo = _simbolo;
}
void Gusano::getSimbolo(char &_simbolo)
{
    _simbolo = simbolo;
}
char Gusano::getSimbolo()
{
    return simbolo;
}

void Gusano::setCabezaPosX(int _x)
{
    pos.setx(_x);
}
void Gusano::setCabezaPosY(int _y)
{
    pos.sety(_y);
}

void Gusano::getCabezaPosX(int &_x)
{
    pos.getx(_x);
}
void Gusano::getCabezaPosY(int &_y)
{
    pos.gety(_y);
}

int Gusano::getCabezaPosX()
{
    return pos.getx();
}

int Gusano::getCabezaPosY()
{

    return pos.gety();
}