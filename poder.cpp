#include <iostream>
#include <ctime>
#include <cstdlib>  //random

//Clases
#include "poder.h"
//

void Poder::Generarpoder()
{

    if (contador < 10)
    {
        contador = contador + 1;
    }

    if (contador >=10)
    {
        senal=1;
    }

}

void Poder::Comprobarsenal()
{
    srand(time(0));

    if (senal==1)
    {
        pos.setx((rand()%(fila-2))+1);
        pos.sety((rand()%(columna-2))+1);
    }
}

char Poder::getSimbolo()
{
    return simbolo;
}