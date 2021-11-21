//Clase Posicion
//Esta clase nos ayuda a establecer y llamar la posición de todos nuestros objetos en el tablero, obstaculos, comida, poder, gusano.
//Esta clase es utilizada por la mayoría de las demas clases.
//Métodos creados: 
// incrementarY; incrementarX; gety; getx; sety; setx

class Posicion {
	
    public:
    int x,y;

    Posicion(int x=0, int y=0){ //Iniciamos nuestros atributos principales
        this -> x = x;
        this -> y = y;
    }

    ~Posicion(){ //Destructor de nuestra clase
    }

    //Métodos
    void setx(int _x);
    void sety(int _y);

    void getx(int &_x);
    void gety(int &_y);
	int getx();
	int gety();
    void incrementarX(int _x);
    void incrementarY(int _y);
};
