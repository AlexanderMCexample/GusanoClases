#include "gusano.cpp"

class Tablero {
    //Atributos
    public:
    Obstaculo obs;
    Comida comida;
    Poder poder; 
    Gusano *gusano;
    int size;
    int **world_Mapa;

    //Constructor
    Tablero(int size =10)
    {
        this -> size =size; 
        world_Mapa = new int*[size];
        for (int i = 0; i < size; i++)
        {
            world_Mapa[i] = new int[size]; 
        }
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                world_Mapa[row][col] = 0;
            }
        }
        comida=Comida(3,3);

        gusano = new Gusano[2];
        gusano[0] = Gusano(size,4,4,'&');
        gusano[1] = Gusano(size,4,6,'%');
        
    }

    //Destructor
    ~Tablero(){
        delete[] gusano;
        for (int i = 0; i < size; i++)
        {
            delete[] world_Mapa[i];
        }
    }
    
    //Métodos
	
    void imprimirMatriz();

    void generarMuros();

    void setControlGusanoUno();
    void setControlGusanoDos();

    void mandoGusanoUno();
    void mandoGusanoDos();
    void movimientoGusano();
};