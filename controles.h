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
    
    //get
    void getTeclaPresionada(int &_tecla);
    void getDireccion(std::string &_direccion);

    void defautControlUno();
    void defautControlDos();

    void interaccionControlUno();
    void interaccionControlDos();

    //usar un mando con los cambios de dirección
    void mando1(); 
    void mando2(); 
};
