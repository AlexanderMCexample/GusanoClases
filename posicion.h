class Posicion {
	
    public:
    
    int x,y;

    Posicion(int x, int y){

        this -> x = x;
        this -> y = y;

    }

    ~Posicion(){
    }

    void setx(int _x);
    void sety(int _y);

    void getx(int &_x);
    void gety(int &_y);
	
	
	//void arriba(Control &o);
	//void abajo(Control &o);
	//void derecha(Control &o);
	//void izquierda(Control &o);
};
