class Obstaculo {
    //Atributos
    public:

    Posicion pos;    
    char simbolo;


    //Constructor
    Obstaculo(int x =0, int y=0,  char simbolo = '#'){
        pos = Posicion(x,y);       
        this -> simbolo = simbolo;
    }

    //Destructor
    ~Obstaculo(){
    }
    
    //Métodos
    void setSimbolo(char _simbolo);
    void setPosX(int _x);
    void setPosY(int _y);
    
    void getPosX(int &_x);
    void getPosY(int &_y);
    void getSimbolo(char &_simbolo);

    void cambioDireccion(std::string &_direccion, int gusanoX, int gusanoY);
};