#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "controles.h"

using namespace std;   

void Control::interaccionControlUno()
{
    int tecla=0;
    if (_kbhit()) 
    {   
        tecla = _getch();
        if (tecla == 97 || tecla == 119 || tecla == 100 || tecla == 115 || tecla == 65 || tecla == 87 || tecla == 68 || tecla == 83) //condicional para tener encuenta solo estas teclas con su mayúscula y colo calar la teclapresionada en minúscula
        {
            switch(tecla) //teclas para el gusano1 convertir la mayúscula a minúscula
            {
                case 65:
                    tecla = 97; break;
                case 87:
                    tecla = 119; break;
                case 68:
                    tecla = 100; break;
                case 83:
                    tecla = 115; break;
                default:
                    break;
            }
            teclaPresionada = tecla;
        }
    }
}

void Control::interaccionControlDos()
{
    int tecla=0;
    if (_kbhit()) 
    {       
        tecla = _getch();
        if  (tecla == 106 || tecla == 105 || tecla == 108 || tecla == 107 || tecla == 74 || tecla == 73 || tecla == 76 || tecla == 75)    //condicional para tener encuenta solo estas teclas con su mayúscula y colo calar la teclapresionada en minúscula
        {
            switch(tecla) //teclas para el gusano2 convertir la mayúscula a minúscula
            {
                case 74:
                    tecla = 106; break;
                case 73:
                    tecla = 105; break;
                case 76:
                    tecla = 108; break;
                case 75:
                    tecla = 107; break;
                default: 
                    break;
            }
            teclaPresionada = tecla;
        }
    }
}

void Control::setArriba(int _tecla)
{
    arriba = _tecla;
}
void Control::setAbajo(int _tecla)
{   
    abajo = _tecla;
}
void Control::setDerecha(int _tecla)
{
    derecha = _tecla;
}
void Control::setIzquierda(int _tecla)
{
    izquierda = _tecla;
}

void Control::setDireccion() //para saber a que dirección apunta el gusano
{
    if (teclaPresionada==arriba)
    {
        direccion = "ARRIBA";
    }
    else if (teclaPresionada==abajo)
    {
        direccion = "ABAJO";
    }
    else if (teclaPresionada==derecha)
    {
        direccion = "DERECHA";
    }
    else if (teclaPresionada==izquierda)
    {
        direccion = "IZQUIERDA";
    }
}

void Control::setDireccion(std::string _direccion) //para saber a que dirección apunta el gusano
{
    if (_direccion=="ARRIBA")
    {
        teclaPresionada = arriba;
    }
    else if (_direccion=="ABAJO")
    {
        teclaPresionada = abajo;
    }
    else if (_direccion=="DERECHA")
    {
        teclaPresionada = derecha;
    }
    else if (_direccion=="IZQUIERDA")
    {
        teclaPresionada = izquierda;
    }
    direccion = _direccion;
}
    
void Control::getDireccion(std::string &_direccion)
{
    _direccion = direccion;
}
std::string Control::getDireccion()
{
    return direccion;
}

void Control::setTeclaPresionada(int _tecla)
{
    teclaPresionada = _tecla;
}

void Control::getTeclaPresionada(int &_tecla)
{
    _tecla = teclaPresionada;
}

void Control::defautControlUno() //controles por defecto a,w,s,d
{
    setArriba(119);
    setAbajo(115);
    setDerecha(100);
    setIzquierda(97);
}
void Control::defautControlDos() //controles por defecto j,i,k,l
{
    setArriba(105);
    setAbajo(107);
    setDerecha(108);
    setIzquierda(106);
}


void Control::mando1()
{
    interaccionControlUno();
    setDireccion();
} 

void Control::mando2()
{
    interaccionControlDos();
    setDireccion();
} 