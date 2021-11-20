#include "gusano.cpp"

class Tablero {
    //Atributos
    public:
    Obstaculo obs; //Llamamos nuestra clase Obstaculo
    Comida comida; //LLamamos nuestra clase Comida
    Poder poder;  //LLamamos nuestra clase Poder
    Gusano *gusano;
    int size;
    int **world_Mapa;

    //Constructor
    Tablero(int size =10)  //El constructor nos da valores iniciales para todos nuestro atributos
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

    //Destructor de nuestra Clase
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