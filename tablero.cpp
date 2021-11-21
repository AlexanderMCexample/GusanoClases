#include <iostream>
#include <string> //string 

#include "tablero.h"

using namespace std;   

void Tablero::imprimirMatriz()  //Método que se encarga de imprimir todo nuestro tablero de juego. Todos y cada uno de los elementos
{
	world_Mapa[comida.getPosX()][comida.getPosY()]=1;
    world_Mapa[poder.getPosX()][poder.getPosY()] = 2;
    world_Mapa[obs.getPosX()][obs.getPosY()] = 3;
    
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

    posicionesCuerpo1(); //cuerpo cambie de lugar
    posicionesCuerpo2();
}
void Tablero::buscarObstaculo()
{
    //CAMBIAR DIRECCION AL CHOCAR CON 3 = OBSTACULO
    //============
    std::string direccionGusano1 = gusano[0].control.getDireccion(); //obtiene ña dirección actual
    std::string direccionGusano2 = gusano[1].control.getDireccion();

    cambiarDireccion(direccionGusano1,gusanoX1,gusanoY1,choque1); //busca si su proximo movimiento hay un obstáculo
    cambiarDireccion(direccionGusano2,gusanoX2,gusanoY2,choque2); //Y busca un lugar vacío para cambiar de ubicación
    
    gusano[0].control.setDireccion(direccionGusano1);//cambia la tecla y dirección según la dirección de cambio de obstaculo
    gusano[1].control.setDireccion(direccionGusano2);
}

void Tablero::imprimirRegistro()
{
    cout << "||[q]     ==> si desea reiniciar||\n\n";
    cout << "Gusano1 "<< choque1 << " - Gusano2 "<< choque2 <<endl;
    cout << "Vidas: "<<vidas<<endl;
    cout << "X1: "<<gusanoX1<<" - Y1: "<<gusanoY1<<endl;
    cout << "X2: "<<gusanoX2<<" - Y2: "<<gusanoY2<<endl;
    choque1="      ";choque2="      ";
}

void Tablero::cambiarDireccion(std::string &_direccion, int gusanoX, int gusanoY, std::string &choque)
{
    if (3 <= world_Mapa[gusanoX-1][gusanoY] && _direccion == "ARRIBA")//obtener valores de gusano 
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX-1][gusanoY]>4 && world_Mapa[gusanoX-1][gusanoY]<7) //crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX-1);
            obs.setPosY(gusanoY);
            choque  = "Choque";
            vidas--;
        }
    } 
    else if (3 <= world_Mapa[gusanoX+1][gusanoY] && _direccion == "ABAJO")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX+1][gusanoY]>4 && world_Mapa[gusanoX+1][gusanoY]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX+1);
            obs.setPosY(gusanoY);
            choque  = "Choque";
            vidas--;
        }
    } 
    else if (3 <= world_Mapa[gusanoX][gusanoY+1] && _direccion == "DERECHA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX][gusanoY+1]>4 && world_Mapa[gusanoX][gusanoY+1]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX);
            obs.setPosY(gusanoY+1);
            choque  = "Choque";
            vidas--;
        }
    }
    else if (3 <= world_Mapa[gusanoX][gusanoY-1] && _direccion == "IZQUIERDA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
        if (world_Mapa[gusanoX][gusanoY-1]>4 && world_Mapa[gusanoX][gusanoY-1]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX);
            obs.setPosY(gusanoY-1);
            choque  = "Choque";
            vidas--;
        }
    }
    if (gusanoX1==gusanoX2 && gusanoY1==gusanoY2)
    {
        obs.setPosX(gusanoX);
        obs.setPosY(gusanoY);
        choque  = "Choque";
        vidas--;
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
    cuerpoX1[0] = gusanoX1;
    cuerpoY1[0] = gusanoY1;
}
void Tablero::setPosicionesCabeza2()
{
    gusanoX2 = gusano[1].getCabezaPosX();
    gusanoY2 = gusano[1].getCabezaPosY();
    cuerpoX2[0] = gusanoX2;
    cuerpoY2[0] = gusanoY2;
}   


void Tablero::crecerGusano(int *listaVaciaX, int *listaVaciaY, int _size)
{
    int _Tamanocuerpo=0;
    if (gusanoX1 == comida.getPosX() && gusanoY1 == comida.getPosY())
    {
        gusano[0].crecer(); //coloca el nuevo x,y del cuerpo
        _Tamanocuerpo = gusano[0].getTamanioCuerpo();
        cuerpoX1[_Tamanocuerpo] = cuerpoX1[_Tamanocuerpo-1];//aumentar el cuerpo
        cuerpoY1[_Tamanocuerpo] = cuerpoY1[_Tamanocuerpo-1];

        comida.generar_aleatorio(listaVaciaX, listaVaciaY, _size);//generar nueva comida
    }
    else if (gusanoX2 == comida.getPosX() && gusanoY2 == comida.getPosY())
    {
        gusano[1].crecer();
        _Tamanocuerpo = gusano[1].getTamanioCuerpo();
        cuerpoX2[_Tamanocuerpo] = cuerpoX2[_Tamanocuerpo-1];//aumentar el cuerpo
        cuerpoY2[_Tamanocuerpo] = cuerpoY2[_Tamanocuerpo-1];

        comida.generar_aleatorio(listaVaciaX, listaVaciaY, _size);//generar nueva comida
    }
}

void Tablero::reducirGusano(int *listaVaciaX, int *listaVaciaY, int _size)
{
    int _Tamanocuerpo=0;
    if (gusanoX1 == poder.getPosX() && gusanoY1 == poder.getPosY())
    {
        _Tamanocuerpo = gusano[0].getTamanioCuerpo();
        world_Mapa[cuerpoX1[_Tamanocuerpo]][cuerpoY1[_Tamanocuerpo]]=0;
        gusano[0].reducir();
        poder.activarSenial();
    }
    else if (gusanoX2 == poder.getPosX() && gusanoY2 == poder.getPosY())
    {
        _Tamanocuerpo = gusano[0].getTamanioCuerpo();
        world_Mapa[cuerpoX1[_Tamanocuerpo]][cuerpoY1[_Tamanocuerpo]]=0;
        gusano[1].reducir();
        poder.activarSenial();
    }
    poder.Generarpoder(listaVaciaX, listaVaciaY, _size);
}

void Tablero::lugaresVacios()
{
    int vaciosX=0,vaciosY=0,i=0;
    for (int row = 0; row < size; row++) //creo el tamaño de la lista de lugares vacios
    {
        for (int col = 0; col < size; col++)
        {
            if (world_Mapa[row][col] == 0) // 0 = vacio
            {
                vaciosX++;
                vaciosY++;
            }
        }   
    }
    //CREACIÓN DEL NEW LISTAS
    int *listaVaciaX = new int[vaciosX];
    int *listaVaciaY = new int[vaciosY];

    for (int row = 0; row < size; row++) //creo las posiciones de los lugares vacíos actuales
    {
        for (int col = 0; col < size; col++)
        {
            if (world_Mapa[row][col] == 0) // 0 = vacio
            {
                listaVaciaX[i] = row;
                listaVaciaY[i] = col;
                i++;
            }
        }
    }

    //MÉTODOS que tendran parámetros de lugares vacíos para colocarse
    crecerGusano(listaVaciaX, listaVaciaY, vaciosX);
    reducirGusano(listaVaciaX, listaVaciaY, vaciosX);

    delete[] listaVaciaX;
    delete[] listaVaciaY;

}

void Tablero::posicionesCuerpo1()
{
    int _tamanioCuerpo1 = gusano[0].getTamanioCuerpo();
    if (_tamanioCuerpo1>0)
    {
        world_Mapa[cuerpoX1[gusano[0].getTamanioCuerpo()]][cuerpoY1[gusano[0].getTamanioCuerpo()]]=0;
        for (_tamanioCuerpo1; _tamanioCuerpo1 > 0; _tamanioCuerpo1--)
        {
            cuerpoX1[_tamanioCuerpo1]=cuerpoX1[_tamanioCuerpo1-1];
            cuerpoY1[_tamanioCuerpo1]=cuerpoY1[_tamanioCuerpo1-1];
            world_Mapa[cuerpoX1[_tamanioCuerpo1]][cuerpoY1[_tamanioCuerpo1]]=5;
        }
    }
}
void Tablero::posicionesCuerpo2()
{
    int _tamanioCuerpo2 = gusano[1].getTamanioCuerpo();
    if (_tamanioCuerpo2>0)
    {
        world_Mapa[cuerpoX2[gusano[1].getTamanioCuerpo()]][cuerpoY2[gusano[1].getTamanioCuerpo()]]=0;
        for (_tamanioCuerpo2; _tamanioCuerpo2 > 0; _tamanioCuerpo2--)
        {
            cuerpoX2[_tamanioCuerpo2]=cuerpoX2[_tamanioCuerpo2-1];
            cuerpoY2[_tamanioCuerpo2]=cuerpoY2[_tamanioCuerpo2-1];
            world_Mapa[cuerpoX2[_tamanioCuerpo2]][cuerpoY2[_tamanioCuerpo2]]=6;
        }
    }
}

int Tablero::getVidas()
{
    return vidas;
}
