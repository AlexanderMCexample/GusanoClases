class Gusano {
    //Atributos
    public:
    Posicion pos;
    Control control;
    int tamanoGusano;
    int maxTamanoGusano;
    char simbolo;
    std::string direccion;

    //Constructor
    Gusano (int size =1, int _x = 0, int _y=0,  char simbolo = '&'){
        tamanoGusano = 0;
        maxTamanoGusano = size;
        this -> simbolo = simbolo;
        pos = Posicion(_x,_y); //pos simpre es la ubicación x,y de la cabeza 
        direccion = "";
    }

    //Destructor
    ~Gusano (){
    }
    
    //Métodos
    void crecer(); //comida
    void reducir(); //poder
    void rebotar(std::string _direccion); //rebota cuando choca con los obstaculos y con el gusano enemigo
    void perder(); //cuando no hay una casilla para rebotar y choca con si mismo
    void setControlUno();
    void setControlDos();
    void controlUno();
    void controlDos();
    void movimientoConstante();

    void setSimbolo(char _simbolo);
    void getSimbolo(char &_simbolo);
    char getSimbolo();

    void setCabezaPosX(int _x); //cabeza
    void setCabezaPosY(int _y); //cabeza

    void getCabezaPosX(int &_x); //cabeza
    void getCabezaPosY(int &_y); //cabeza
    int getCabezaPosX(); //cabeza
    int getCabezaPosY(); //cabeza

};