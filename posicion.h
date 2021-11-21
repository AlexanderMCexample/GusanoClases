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
