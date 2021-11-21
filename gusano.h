class Gusano {

    public:
    //Atributos
    Posicion pos; //LLamamos nuestra clase Posicion
    Control control;
    int tamanoGusano;
    int size;
    int maxTamanoGusano;
    char simbolo;
    int cuerpoX;
    int cuerpoY;
    std::string direccion;

    //Constructor
    Gusano (int size =1, int _x = 0, int _y=0,  char simbolo = '&'){ //El constructor nos da valores iniciales para todos nuestro atributos
        tamanoGusano = 1;
        maxTamanoGusano = size;
        this->size = size;
        this -> simbolo = simbolo;
        pos = Posicion(_x,_y); //pos simpre es la ubicación x,y de la cabeza 
        direccion = "";

        cuerpoX = 0; //tamaño del cuerpo
        cuerpoY = 0;      
    }

    //Destructor de nuestra Clase
    ~Gusano (){
    }
    
    //Métodos
    void crecer(); //comida
    void reducir(); //poder
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

    void getCuerpo(int &_cuerpoX, int &_cuerpoY);
    int getTamanioCuerpo();

};