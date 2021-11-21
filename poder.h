//Clase Poder
//Esta clase es la que se encarga de la creación de nuestros objetos poder. Este fue nuestra propuesta cómo grupo en la entrega anterior. El poder reducira el tamaño de nuestro gusano, a diferencia de la comida que lo da más tamaño; y también dará mayor velocidad al juego.
//Métodos creados:
//getSimbolo; Generarpoder; getVelocidadJuego; getPosY; getPosX; activarSenial; setPosY; setPosX; setSimbolo;

class Poder {

    public:
    //Atributos
    Posicion pos; //LLamamos la clase posicion 
    int contador; //Creamos todos los atributos necesarios
    int senal;
    int poder_x;
    int poder_y;
    char simbolo;
    int velocidad_juego;
    int aparicion;

    //Constructos
    Poder(int size =0 ,int poder_x =0, int poder_y=0, char simbolo='P') //El constructor nos da valores iniciales para todos nuestro atributos
    {
    senal = 0;
    contador=0;
    pos = Posicion(poder_x,poder_y);
    this -> simbolo = simbolo;
    velocidad_juego = 0; 
    aparicion = size;
    }

    //Destructor
    ~Poder() //Destructor de nuestra clase
    {
    }

    //Métodos
    void setSimbolo(char _simbolo);
    void setPosX(int _x);
    void setPosY(int _y);
    void activarSenial();

    void getPosX(int &_x);
    void getPosY(int &_y);
    int getPosX();
    int getPosY();
    int getVelocidadJuego();
    
    void Generarpoder(int *listaVaciaX, int *listaVaciaY, int size); 
    char getSimbolo();
    
};
