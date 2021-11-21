#include "poder.h"

void Poder::setSimbolo(char _simbolo) //Este Método nos sirve para llamar al simbolo de nuestra comida
{
    simbolo = _simbolo; 
}
void Poder::setPosX(int _x) //Método que establece la posición X de nuestra comida
{
    pos.setx(_x);
}
void Poder::setPosY(int _y) //Método que establece la posición X de nuestra comida
{
    pos.sety(_y);
}
void Poder::getPosX(int &_x) //Método que llama la posición X de nuestra comida (Usada por otras clases)
{
    pos.getx(_x);
}
void Poder::getPosY(int &_y)  //Método que llama la posición X de nuestra comida (Usada por otras clases)
{
    pos.gety(_y);
}
int Poder::getPosX() //Return posicición X
{
    return pos.getx(); 
}
int Poder::getPosY()
{
    return pos.gety();
}

void Poder::Generarpoder(int *listaVaciaX, int *listaVaciaY, int size) //Este método cuenta el tiempo para que el siguiente poder sea creado
{  
    if (contador < 10 && senal==1) //dependiendo el tamaño del tablero aumetnará la velocidad del juego
    {
        contador = contador + 1;
    }
    else if (contador >=10)
    {
        srand(time(0)); 
        setPosX(listaVaciaX[rand()%(size-1)]);  //Se crea una posición aleatorea para x
        setPosY(listaVaciaX[rand()%(size-1)]);//Se crea una posición aleatorea para y
        contador =0;
        senal=0;
        velocidad_juego = 0;
    }

}

void Poder::activarSenial() //Activa el aumento de la velocidad del juego y el contador para crear el nuevo poder
{
    if (senal == 0)
    {
        velocidad_juego = 300;
        setPosX(0);
        setPosY(0);
        senal = 1;
    }
}

char Poder::getSimbolo() //Método que le servira a diferentes clases para obtener el simbolo de nuestro poder
{
    return simbolo;
}

int Poder::getVelocidadJuego()
{
    return velocidad_juego;
}