class Tablero {
    //Atributos
    public:
    int world_Mapa[10][10];
    Obstaculo obs; //Llamamos nuestra clase Obstaculo
    Comida comida; //LLamamos nuestra clase Comida
    Poder poder;  //LLamamos nuestra clase Poder


    //Constructor
    Tablero(int _sizeX=0, int _sizeY=0)  //El constructor nos da valores iniciales para todos nuestro atributos
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

    //Destructor de nuestra Clase
    ~Tablero(){
    }
    
    //Métodos
	
    void imprimirMatriz();

    void generarMuros();
};
