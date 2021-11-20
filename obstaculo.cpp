#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "obstaculo.h"

using namespace std;   

void Obstaculo::setSimbolo(char _simbolo)  //Método que establecera el simbolo de nuestro obstaculo
{
    simbolo = _simbolo; 
}
void Obstaculo::setPosX(int _x) //Método que establece la posición X de los obstaculos
{
    pos.setx(_x);
}
void Obstaculo::setPosY(int _y) //Método que establece la posición Y de los obstaculos
{
    pos.sety(_y);
}

void Obstaculo::getPosX(int &_x) //Método que llama la posición X del obstaculo
{
    pos.getx(_x);
}
void Obstaculo::getPosY(int &_y) //Método que llama la posición Y del obstaculo
{
    pos.gety(_y);
}
void Obstaculo::getSimbolo(char &_simbolo) //Método que llama el simbolo de nuestros obstaculos
{
    _simbolo = simbolo;
}

void Obstaculo::cambioDireccion(std::string &_direccion, int gusanoX, int gusanoY) 
{
    int obsX,obsY;
    getPosX(obsX);
    getPosY(obsY);

    if (obsY == gusanoY-1 && _direccion == "ARRIBA")//obtener valores de gusano 
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
void Obstaculo::direccionDisponible(std::string &_direccion, int gusanoX, int gusanoY)  //Método que nos ayuda a buscar una casilla vacía dentro de nuestro tablero para que los gusanos puedan cambiar su direción al chocar
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

