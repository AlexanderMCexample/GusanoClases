//Clases
#include "poder.h"
//

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
    srand(time(0)); 
  
//    if (contador < 10)
//    {
//        contador = contador + 1;
//    }
//    if (contador >=10)
//    {
//        senal=1; //Tras cierto tiempo se envia la señal que el poder esta listo para ser creado
//    }
//    if (senal==1) //Se confirma que la señal fue reicibida
//    {
       setPosX(listaVaciaX[rand()%(size-1)]);  //Se crea una posición aleatorea para x
      setPosY(listaVaciaX[rand()%(size-1)]);//Se crea una posición aleatorea para y
//    }

}

//void Poder::Comprobarsenal() //Este método resive la señal de nuestro método GenerarPoder
//{
//    srand(time(0)); 

//    if (senal==1) //Se confirma que la señal fue reicibida
//    {
//        pos.setx(listaVaciaX[rand()%(size-1)]);  //Se crea una posición aleatorea para x
//        pos.sety(listaVaciaX[rand()%(size-1)]);//Se crea una posición aleatorea para y
//    }
//}
char Poder::getSimbolo() //Método que le servira a diferentes clases para obtener el simbolo de nuestro poder
{
    return simbolo;
}
