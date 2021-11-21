#include <iostream>
#include <string> //string 

#include "tablero.h"

using namespace std;   

void Tablero::imprimirMatriz()  //Método que se encarga de imprimir todo nuestro tablero de juego. Todos y cada uno de los elementos
{
	world_Mapa[comida.getPosX()][comida.getPosY()]=1; //actualiza la posición de la comida actual
    world_Mapa[poder.getPosX()][poder.getPosY()] = 2; //actualiza la posición de la comida actual
    world_Mapa[obs.getPosX()][obs.getPosY()] = 3; //actualiza la posición de la comida actual
    
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

void Tablero::generarMuros() //genera los muros del tablero como obstaculos para que el gusano rebote
{
    for (int i = 0; i < size; i++)
    {
        world_Mapa[0][i] = 3;
        world_Mapa[i][0] = 3;
        world_Mapa[size-1][i] = 3;
        world_Mapa[i][size-1] = 3;
    }
}

void Tablero::setControlGusanoUno() //selecciona las teclas del control 1
{
    gusano[0].setControlUno();
}
void Tablero::setControlGusanoDos() //selecciona las teclas del control 2
{
    gusano[1].setControlDos();
}

void Tablero::mandoGusanoUno() // Para captar las teclas del gusano 1 
{
    gusano[0].controlUno();
}   
void Tablero::mandoGusanoDos() // Para captar las teclas del gusano 2
{
    gusano[1].controlDos();
}
void Tablero::movimientoGusano()
{
    setPosicionesCabeza1(); //actualiza la posición anterior
    setPosicionesCabeza2();

    world_Mapa[gusanoX1][gusanoY1]=0; //posición anterior = 0
    world_Mapa[gusanoX2][gusanoY2]=0;

    gusano[0].movimientoConstante(); //movimiento siguiente del gusano
    gusano[1].movimientoConstante();

    setPosicionesCabeza1(); //actualiza la posición actual
    setPosicionesCabeza2();

    world_Mapa[gusanoX1][gusanoY1]=5; //coloca la nueva posición en la matriz para la impreción
    world_Mapa[gusanoX2][gusanoY2]=6;

    posicionesCuerpo1(); //para que el cuerpo pueda moverse y cambie de posición en la matriz
    posicionesCuerpo2();
}
void Tablero::buscarObstaculo()
{
    //CAMBIAR DIRECCION AL CHOCAR CON 3 = OBSTACULO
    //============
    std::string direccionGusano1 = gusano[0].control.getDireccion(); //obtiene la dirección actual
    std::string direccionGusano2 = gusano[1].control.getDireccion();

    cambiarDireccion(direccionGusano1,gusanoX1,gusanoY1,choque1); //busca si su proximo movimiento hay un obstáculo Y busca un lugar vacío para cambiar de ubicación
    cambiarDireccion(direccionGusano2,gusanoX2,gusanoY2,choque2);
    
    gusano[0].control.setDireccion(direccionGusano1);//cambia la tecla y dirección según la dirección de cambio de obstaculo o de la dirección actual
    gusano[1].control.setDireccion(direccionGusano2);
}

void Tablero::imprimirRegistro() //imprime los registros de cada gusano
{
    cout << "-= [q]  ==> si desea reiniciar =-\n\n";
    cout << "Gusano1 "<< choque1 << " - Gusano2 "<< choque2 <<endl;
    cout << "Vidas: "<<vidas<<endl;
    cout << "X1: "<<gusanoX1<<" - Y1: "<<gusanoY1<<endl;
    cout << "X2: "<<gusanoX2<<" - Y2: "<<gusanoY2<<endl;
    choque1="      ";choque2="      "; // la proxima impresión ya no saldrá el mensaje
}

void Tablero::cambiarDireccion(std::string &_direccion, int gusanoX, int gusanoY, std::string &choque)
{// encuentra si un gusano choca con un muro o con otro gusano o el mismo
    if (3 <= world_Mapa[gusanoX-1][gusanoY] && _direccion == "ARRIBA")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY); //encuentra un lugar vacío para cambiar a esa dirección
        if (world_Mapa[gusanoX-1][gusanoY]>4 && world_Mapa[gusanoX-1][gusanoY]<7) //si hay colisión con una serpiente crear un obstaculo 
        {
            obs.setPosX(gusanoX-1);
            obs.setPosY(gusanoY);
            choque  = "Choque";
            vidas--;
        }
    } 
    else if (3 <= world_Mapa[gusanoX+1][gusanoY] && _direccion == "ABAJO")
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);//encuentra un lugar vacío para cambiar a esa dirección
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
        direccionDisponible(_direccion,gusanoX,gusanoY);//encuentra un lugar vacío para cambiar a esa dirección
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
        direccionDisponible(_direccion,gusanoX,gusanoY);//encuentra un lugar vacío para cambiar a esa dirección
        if (world_Mapa[gusanoX][gusanoY-1]>4 && world_Mapa[gusanoX][gusanoY-1]<7)//crear un obstaculo si hay colisión con una serpiente
        {
            obs.setPosX(gusanoX);
            obs.setPosY(gusanoY-1);
            choque  = "Choque";
            vidas--;
        }
    }
    if (gusanoX1==gusanoX2 && gusanoY1==gusanoY2) //si los gusanos estas en el mismo lugar se crea el obstáculo
    {
        direccionDisponible(_direccion,gusanoX,gusanoY);
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

void Tablero::setPosicionesCabeza1() //actualiza la nueva posición de la cabeza gusano 1
{
    gusanoX1 = gusano[0].getCabezaPosX();
    gusanoY1 = gusano[0].getCabezaPosY();
    cuerpoX1[0] = gusanoX1;
    cuerpoY1[0] = gusanoY1;
}
void Tablero::setPosicionesCabeza2() //actualiza la nueva posición de la cabeza gusano 2
{
    gusanoX2 = gusano[1].getCabezaPosX();
    gusanoY2 = gusano[1].getCabezaPosY();
    cuerpoX2[0] = gusanoX2;
    cuerpoY2[0] = gusanoY2;
}   


void Tablero::crecerGusano(int *listaVaciaX, int *listaVaciaY, int _size)
{//hacer crecer el gusano y crear una nueva comida con las listas que contienen los lugares vacíos
    int _Tamanocuerpo=0;
    if (gusanoX1 == comida.getPosX() && gusanoY1 == comida.getPosY())
    {
        gusano[0].crecer(); //coloca el nuevo x,y del cuerpo
        _Tamanocuerpo = gusano[0].getTamanioCuerpo(); //consigue el tamaño actual del gusano 1
        cuerpoX1[_Tamanocuerpo] = cuerpoX1[_Tamanocuerpo-1];//aumentar el cuerpo
        cuerpoY1[_Tamanocuerpo] = cuerpoY1[_Tamanocuerpo-1];

        comida.generar_aleatorio(listaVaciaX, listaVaciaY, _size);//generar nueva comida
    }
    else if (gusanoX2 == comida.getPosX() && gusanoY2 == comida.getPosY())
    {
        gusano[1].crecer();//coloca el nuevo x,y del cuerpo
        _Tamanocuerpo = gusano[1].getTamanioCuerpo(); //consigue el tamaño actual del gusano 2
        cuerpoX2[_Tamanocuerpo] = cuerpoX2[_Tamanocuerpo-1];//aumentar el cuerpo
        cuerpoY2[_Tamanocuerpo] = cuerpoY2[_Tamanocuerpo-1];

        comida.generar_aleatorio(listaVaciaX, listaVaciaY, _size);//generar nueva comida
    }
}

void Tablero::reducirGusano(int *listaVaciaX, int *listaVaciaY, int _size)
{ //reduce el gusano  y crea el nuevo poder después de unas impresiones
    int _Tamanocuerpo=0;
    if (gusanoX1 == poder.getPosX() && gusanoY1 == poder.getPosY())
    {
        _Tamanocuerpo = gusano[0].getTamanioCuerpo();  //consigue el tamaño actual del gusano 1
        world_Mapa[cuerpoX1[_Tamanocuerpo]][cuerpoY1[_Tamanocuerpo]]=0; //colocar en 0 la última ubicación del gusano
        gusano[0].reducir(); // reducir el tamaño del gusano
        poder.activarSenial(); // activa la señal para activar el conteo de la aparición del nuevo poder
    }
    else if (gusanoX2 == poder.getPosX() && gusanoY2 == poder.getPosY())
    {
        _Tamanocuerpo = gusano[1].getTamanioCuerpo(); //consigue el tamaño actual del gusano 2
        world_Mapa[cuerpoX2[_Tamanocuerpo]][cuerpoY2[_Tamanocuerpo]]=0; //colocar en 0 la última ubicación del gusano
        gusano[1].reducir(); // reducir el tamaño del gusano
        poder.activarSenial(); // activa la señal para activar el conteo de la aparición del nuevo poder
    }
    poder.Generarpoder(listaVaciaX, listaVaciaY, _size); //generar el poder según las listas con los lugares vacíos
}

void Tablero::lugaresVacios() //Actualiza los lugares vacíos para poder generar el nuevo poder o comida
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
    crecerGusano(listaVaciaX, listaVaciaY, vaciosX); //condicionales para crecer el gusano si se como la comida y crear la nueva comida
    reducirGusano(listaVaciaX, listaVaciaY, vaciosX); //condicionales para reducir el gusano si se como el poder y crear el nuevo poder

    delete[] listaVaciaX;
    delete[] listaVaciaY;

}

void Tablero::posicionesCuerpo1() //actualiza las nuevas posiciones del cuerpo en la matriz
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
void Tablero::posicionesCuerpo2() //actualiza las nuevas posiciones del cuerpo en la matriz
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
