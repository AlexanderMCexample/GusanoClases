#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "tablero.h"

using namespace std;   

void Tablero::imprimirMatriz()  //Método que se encarga de imprimir todo nuestro tablero de juego. Todos y cada uno de los elementos
{
	world_Mapa[comida.getPosX()][comida.getPosY()]=1;
    world_Mapa[2][2] = 2;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (world_Mapa[row][col] == 0) // 0 = vacio
                {
                    cout << "_";
                }
            else if (world_Mapa[row][col] == 1) // 1 = comida
            	{
            		cout << comida.getSimbolo();
				}
            else if (world_Mapa[row][col] == 2) // 2 = poder
                {
                    cout << poder.getSimbolo();
                }
            else if (world_Mapa[row][col] == 5) // 5 = gusano1
            {
                cout << gusano[0].getSimbolo();
            }
            else if (world_Mapa[row][col] == 6) // 6 = gusano2
            {
                cout << gusano[1].getSimbolo();
            }
        }   
        cout << endl;
    }
}

void Tablero::setControlGusanoUno()
{
    gusano[0].setControlUno();
}
void Tablero::setControlGusanoDos()
{
    gusano[1].setControlDos();
}

void Tablero::mandoGusanoUno()
{
    gusano[0].controlUno();
}   
void Tablero::mandoGusanoDos()
{
    gusano[1].controlDos();
}
void Tablero::movimientoGusano()
{
    world_Mapa[gusano[0].getCabezaPosY()][gusano[0].getCabezaPosX()]=0; //posición anterior = 0
    world_Mapa[gusano[1].getCabezaPosY()][gusano[1].getCabezaPosX()]=0;
    gusano[0].movimientoConstante(); //movimiento constante de la serpiente
    gusano[1].movimientoConstante();
    world_Mapa[gusano[0].getCabezaPosY()][gusano[0].getCabezaPosX()]=5; //coloca la nueva posición
    world_Mapa[gusano[1].getCabezaPosY()][gusano[1].getCabezaPosX()]=6;
}
