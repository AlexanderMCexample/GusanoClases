#include <iostream>
#include <math.h> //para formulas matemáticas
#include <conio.h> //gets()
#include <cstring> //strcpy strcmp
#include <string> //string 
//clases
#include "controles.cpp"
#include "posicion.cpp"
#include "obstaculo.cpp"
#include "comida.cpp"
#include "tablero.cpp"

using namespace std;

void controles()
{
    Control cont1,cont2;
    std::string direccion1;
    cont1.defautControlUno();
    cont2.defautControlDos();
    while (true)
    {
        cont1.mando1();
        cont2.mando2();
        cont1.getDireccion(direccion1);
        cout <<direccion1<<endl;
    }
}
void posicion()
{
	Posicion gus1(10,10);
	Posicion gus2(0,0);
	Posicion comida(5,5);
	Posicion poder(7,7);
}

void tablero()
{
    Tablero tabla;
    tabla.imprimirMatriz();
}
