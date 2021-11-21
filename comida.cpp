#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 
//Clases
#include "comida.h"
using namespace std; 

void Comida::setSimbolo(char _simbolo) //Este Método nos sirve para llamar al simbolo de nuestra comida
{
    simbolo = _simbolo; 
}
void Comida::setPosX(int _x) //Método que establece la posición X de nuestra comida
{
    pos_comida.setx(_x);
}
void Comida::setPosY(int _y) //Método que establece la posición X de nuestra comida
{
    pos_comida.sety(_y);
}
void Comida::getPosX(int &_x) //Método que llama la posición X de nuestra comida (Usada por otras clases)
{
    pos_comida.getx(_x);
}
void Comida::getPosY(int &_y)  //Método que llama la posición X de nuestra comida (Usada por otras clases)
{
    pos_comida.gety(_y);
}
int Comida::getPosX() //Return posicición X
{
    return pos_comida.getx(); 
}
int Comida::getPosY()
{
    return pos_comida.gety();
}
void Comida::generar_aleatorio(int size) //Return posicición Y
{
	srand(time(0));
	setPosX((rand()%(size-2))+1);
    setPosY((rand()%(size-2))+1);
}
char Comida::getSimbolo() //Return del simbolo de nuestra comida
{
    return simbolo;
}

