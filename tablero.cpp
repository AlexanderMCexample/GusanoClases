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
    world_Mapa[obs.getPosX()][obs.getPosY()]=3;

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
            else if (world_Mapa[row][col] == 3) // 3 = ostáculo
            {
                cout << obs.getSimbolo();
            }
        }   
        cout << endl;
    }
}

void Tablero::generarMuros()
{
    for (int i = 0; i < size; i++)
    {
        world_Mapa[0][i] = 3;
        world_Mapa[i][0] = 3;
        world_Mapa[size-1][i] = 3;
        world_Mapa[i][size-1] = 3;
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
    setPosicionesCabeza1(); //actualiza la posición anterior
    setPosicionesCabeza2();

    world_Mapa[gusanoX1][gusanoY1]=0; //posición anterior = 0
    world_Mapa[gusanoX2][gusanoY2]=0;

    gusano[0].movimientoConstante(); //movimiento constante de la serpiente
    gusano[1].movimientoConstante();

    setPosicionesCabeza1(); //actualiza la posición actual
    setPosicionesCabeza2();

    world_Mapa[gusanoX1][gusanoY1]=5; //coloca la nueva posición para la impreción
    world_Mapa[gusanoX2][gusanoY2]=6;
}
void Tablero::buscarObstaculo()
{
    //CAMBIAR DIRECCION AL CHOCAR CON 3 = OBSTACULO
    //============
    std::string direccionGusano1 = gusano[0].control.getDireccion(); //obtiene ña dirección actual
    std::string direccionGusano2 = gusano[1].control.getDireccion();

    cout << "Gusano1 "<<direccionGusano1 << "Gusano2 "<< direccionGusano2 <<endl;
    cout << "X1 "<<gusanoX1<<" Y1 "<<gusanoY1<<endl;
    cout << "X2 "<<gusanoX2<<" Y2 "<<gusanoY2<<endl;

    cambiarDireccion(direccionGusano1,gusanoX1,gusanoY1); //busca si su proximo movimiento hay un obstáculo
    cambiarDireccion(direccionGusano2,gusanoX2,gusanoY2); //Y busca un lugar vacío para cambiar de ubicación
    
    gusano[0].control.setDireccion(direccionGusano1);//cambia la tecla y dirección según la dirección de cambio de obstaculo
    gusano[1].control.setDireccion(direccionGusano2);
}

void Tablero::cambiarDireccion(std::string &_direccion, int gusanoX, int gusanoY)
{
    if (3 <= world_Mapa[gusanoX-1][gusanoY] && _direccion == "ARRIBA")//obtener valores de gusano 
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX-1][gusanoY]>4 && world_Mapa[gusanoX-1][gusanoY]<7) //crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX-1);
            obs.setPosY(gusanoY);
        }
    } 
    else if (3 <= world_Mapa[gusanoX+1][gusanoY] && _direccion == "ABAJO")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX+1][gusanoY]>4 && world_Mapa[gusanoX+1][gusanoY]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX+1);
            obs.setPosY(gusanoY);
        }
    } 
    else if (3 <= world_Mapa[gusanoX][gusanoY+1] && _direccion == "DERECHA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX][gusanoY+1]>4 && world_Mapa[gusanoX][gusanoY+1]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX);
            obs.setPosY(gusanoY+1);
        }
    }
    else if (3 <= world_Mapa[gusanoX][gusanoY-1] && _direccion == "IZQUIERDA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX][gusanoY-1]>4 && world_Mapa[gusanoX][gusanoY-1]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX);
            obs.setPosY(gusanoY-1);
        }
    }
    if (gusanoX1==gusanoY1 && gusanoY1==gusanoY2)
    {
        obs.setPosX(gusanoX);
        obs.setPosY(gusanoY-1);
    }
}

void Tablero::direccionDisponible(std::string &_direccion, int gusanoX, int gusanoY)  //Método que nos ayuda a buscar una casilla vacía dentro de nuestro tablero para que los gusanos puedan cambiar su direción al chocar
{
    if (3 > world_Mapa[gusanoX-1][gusanoY])//si en una dirección esta vacia el gusano rebotará en esa direccion
    {
        _direccion = "ARRIBA";
    } 
    else if (3 > world_Mapa[gusanoX+1][gusanoY])
    {
        _direccion = "ABAJO";
    } 
    else if (3 > world_Mapa[gusanoX][gusanoY+1])
    {
        _direccion = "DERECHA";
    }
    else if (3 > world_Mapa[gusanoX][gusanoY-1])
    {
        _direccion = "IZQUIERDA";
    }
    else
    { 
        _direccion = "LOSE";
    }
}

void Tablero::setPosicionesCabeza1()
{
    gusanoX1 = gusano[0].getCabezaPosX();
    gusanoY1 = gusano[0].getCabezaPosY();
}
void Tablero::setPosicionesCabeza2()
{
    gusanoX2 = gusano[1].getCabezaPosX();
    gusanoY2 = gusano[1].getCabezaPosY();
}   


void Tablero::crecerGusano()
{
    if (gusanoX1 == comida.getPosX() && gusanoY1 == comida.getPosY())
    {
        gusano[0].crecer();
        comida.generar_aleatorio(size);
    }
}