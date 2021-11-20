class Poder {

    public:

    //Atributos
    Posicion pos; //LLamamos la clase posicion 
    int contador; //Creamos todos los atributos necesarios
    int senal;
    int poder_x;
    int poder_y;
    char simbolo;
    int fila;
    int columna;

    //Constructos
    Poder() //El constructor nos da valores iniciales para todos nuestro atributos
    {
    senal = 0;
    simbolo = 'P'; //Nuestro poder tiene el simbolo P, el cual sera el que se imprima en el tablero
    fila = 10;
    columna = 10;
    }
    //Destructor
    ~Poder() //Destructor de nuestra clase
    {
    }


    //Métodos
    void Generarpoder(); 
    void Comprobarsenal();
    char getSimbolo();
    
};