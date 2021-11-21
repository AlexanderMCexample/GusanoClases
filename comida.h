#include <cstdlib>
#include <ctime>
//Clase Comida
//Esta clase se encarga de la generación de la comida dentro de neustro juego, para esto utiliza diferentes metodos que ayudan a encontrar la posición correcta.
//Además usa otras clases, principalmente la clase Posicion la cual se encarga de establecer un punto X y Y de nuestra matriz (tablero de juego)
//Métodos creados: setSimbolo; setPosX ; setPosY; getPosX; getPosY (Existe un método con y sin parametro para cada get); generar_aleatorio; getSimbolo.



class Comida {
    //Atributos
    public:
    Posicion pos_comida;   //LLamamos la clase Posicion
    char simbolo; //Creamos el simbolo el cual representara la comida dentro del juego

    //Constructor
    Comida(int comida_x =0, int comida_y=0,  char simbolo = '@'){ //El constructor nos da valores iniciales para todos nuestro atributos
		pos_comida = Posicion(comida_x,comida_y);
        this -> simbolo = simbolo; 
    }

    //Destructor de neustra clase
    ~Comida(){
    }
    
    //Métodos
    void setSimbolo(char _simbolo);
    void setPosX(int _x);
    void setPosY(int _y);
    
    void getPosX(int &_x);
    void getPosY(int &_y);
    int getPosX();
    int getPosY();
    
    void generar_aleatorio(int *listaVaciaX, int *listaVaciaY, int size);
    char getSimbolo();
    

};
