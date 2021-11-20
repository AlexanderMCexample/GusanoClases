#include <cstdlib>
#include <ctime>
class Comida {
    //Atributos
    public:

    Posicion pos_comida;   //LLamamos la clase Posicion
    char simbolo;


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
    
    void generar_aleatorio();
    char getSimbolo();
    

};
