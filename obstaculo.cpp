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

char Obstaculo::getSimbolo()
{
    return simbolo;
}

