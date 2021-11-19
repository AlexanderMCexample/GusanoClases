class Poder {

    public:
    
    //Atributos
    Posicion pos;
    int contador;
    int senal;
    int poder_x;
    int poder_y;
    char simbolo;
    int fila;
    int columna;

    //Constructos
    Poder()
    {
    senal = 0;
    simbolo = 'P';
    fila = 10;
    columna = 10;
    }
    //Destructor
    ~Poder()
    {

    }


    //Metodos
    void Generarpoder();
    void Comprobarsenal();
    char getSimbolo();
    
};