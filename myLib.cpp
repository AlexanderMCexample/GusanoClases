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
#include "poder.cpp"
#include "tablero.cpp"

using namespace std;

void tablero()
{
    int size=0;
    cout << "Ingrece el tamaño de su tablero: ";
    cin >> size;
    Tablero tabla(size); 
    tabla.generarMuros();
    tabla.setControlGusanoDos();
    tabla.setControlGusanoUno();
    
    while(true)
    {
        tabla.movimientoGusano(); //Actualiza los movimientos del gusano
        tabla.imprimirMatriz();
        for (double time = 0; time < 600-tabla.poder.getVelocidadJuego();time+=0.05)  //tiempo para imprimir y capturar la tecla
        {
            tabla.mandoGusanoUno();
            tabla.mandoGusanoDos();
        }
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        tabla.buscarObstaculo();
        tabla.lugaresVacios();        
    }


}
