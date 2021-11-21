//Clase Control
//Esta clase es la encargada del movimiento de nuestro gusano, más que la posición a DONDE se va a mover.
//Para cumplir su objetivo hemos creado una serie de métodos: 
//setArriba; setAbajo; setIzquerida; setDerecha; setTeclaPresionada; setDireccion; getTeclaPresionada; getDireccion; defautControlUno; defautControlDos; interaccionControlUno; interaccionControlDos; mando1, mando2

class Control {
    //Atributos
    public:
    int arriba,abajo,derecha,izquierda,teclaPresionada;
    std::string direccion;

    //Constructor
    Control(int arriba = 0, int abajo = 0, int derecha = 0, int izquierda = 0){
        this -> arriba = arriba;
        this -> abajo = abajo;
        this -> derecha = derecha;
        this -> izquierda = izquierda;
        teclaPresionada = 0;
        direccion = "";
    }
    //Destructor
    ~Control(){
    }

    //set
    void setArriba(int _tecla);
    void setAbajo(int _tecla);
    void setDerecha(int _tecla);
    void setIzquierda(int _tecla);
    void setTeclaPresionada(int _tecla);
    void setDireccion();
    void setDireccion(std::string _teclaPresionada);
    
    //get
    void getTeclaPresionada(int &_tecla);
    void getDireccion(std::string &_direccion);
    std::string getDireccion();

    void defautControlUno();
    void defautControlDos();

    void interaccionControlUno();
    void interaccionControlDos();

    //usar un mando con los cambios de dirección
    void mando1(); 
    void mando2(); 
};
