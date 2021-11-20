#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "tablero.h"

using namespace std;   

void Tablero::imprimirMatriz()
{
	world_Mapa[comida.getPosY()][comida.getPosX()]=1;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (world_Mapa[row][col] == 0) // 0 = vacio
                {
                    cout << "_";
                }
            else if (world_Mapa[row][col] == 1) // 1 = comida
            	{
            		cout << comida.getSimbolo();
				}
        }
        cout << endl;
    }
}
