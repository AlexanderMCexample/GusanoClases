class Obstaculo {
    //Atributos
    public:

    Posicion pos;    //Llamamos nuestra clase Posicion
    char simbolo;


    //Constructor
    Obstaculo(int x =0, int y=0,  char simbolo = '#'){   //El constructor nos da valores iniciales para todos nuestro atributos
        pos = Posicion(x,y);       
        this -> simbolo = simbolo;
    }

    //Destructor de nuestra clase
    ~Obstaculo(){
    }
    
    //Métodos
    void setSimbolo(char _simbolo);
    void setPosX(int _x);
    void setPosY(int _y);
    
    void getPosX(int &_x);
    void getPosY(int &_y);
    void getSimbolo(char &_simbolo);
    char getSimbolo();
    
};