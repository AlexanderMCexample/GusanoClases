#include <iostream>
#include <ctime>
#include <cstdlib>  //random

//Clases
#include "poder.h"
//

void Poder::Generarpoder() //Este método cuenta el tiempo para que el siguiente poder sea creado
{

    if (contador < 10)
    {
        contador = contador + 1;
    }

    if (contador >=10)
    {
        senal=1; //Tras cierto tiempo se envia la señal que el poder esta listo para ser creado
    }

}

void Poder::Comprobarsenal() //Este método resive la señal de nuestro método GenerarPoder
{
    srand(time(0)); 

    if (senal==1) //Se confirma que la señal fue reicibida
    {
        pos.setx((rand()%(fila-2))+1);  //Se crea una posición aleatorea para x
        pos.sety((rand()%(columna-2))+1);//Se crea una posición aleatorea para y
    }
}

char Poder::getSimbolo() //Método que le servira a diferentes clases para obtener el simbolo de nuestro poder
{
    return simbolo;
}