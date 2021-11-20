class Tablero {
    //Atributos
    public:
    int world_Mapa[10][10];
    Comida comida;
    
    //Constructor
    Tablero (int _sizeX=0, int _sizeY=0)
    {
        for (int row = 0; row < 10; row++)
        {
            for (int col = 0; col < 10; col++)
            {
                world_Mapa[row][col] = 0;
            }
        }
        comida=Comida(3,3);
    }

    //Destructor
    ~Tablero(){
    }
    
    //Métodos
	
    void imprimirMatriz();
};
