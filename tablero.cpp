#include <iostream>
#include <conio.h> //gets() kbhit()
#include <cstring> //strcpy strcmp
#include <string> //string 

#include "tablero.h"

using namespace std;   

void Tablero::imprimirMatriz()
{
    world_Mapa[2][2] = 2;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (world_Mapa[row][col] == 0) // 0 = vacío
                {
                    cout << "_";
                }
            else if (world_Mapa[row][col] == 2) // 2 = poder
                {
                    cout << poder.getSimbolo();
                }
        }   
        cout << endl;
    }
}