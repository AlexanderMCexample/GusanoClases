#include "gusano.cpp"

class Tablero {
    //Atributos
    public:
    Obstaculo obs; //Llamamos nuestra clase Obstaculo
    Comida comida; //LLamamos nuestra clase Comida
    Poder poder;  //LLamamos nuestra clase Poder
    Gusano *gusano;
    int size;
    int gusanoX1, gusanoY1, gusanoX2, gusanoY2;
    int **world_Mapa;
    int *cuerpoX1,*cuerpoY1,*cuerpoX2,*cuerpoY2;
    int vidas;
    std::string choque1,choque2;

    //Constructor
    Tablero(int size =10)  //El constructor nos da valores iniciales para todos nuestro atributos
    {
        this -> size =size; 
        gusanoX1=0; gusanoY1=0; gusanoX2=0; gusanoY2=0, vidas=5;
        choque1="      ";choque2="      ";
        
        cuerpoX1 = new int[size];
        cuerpoX2 = new int[size];
        cuerpoY1 = new int[size];
        cuerpoY2 = new int[size];

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
        comida = Comida(2,2);
        poder = Poder(size,2,size-3);

        gusano = new Gusano[2];
        gusano[0] = Gusano(size,size/2,size/2-1,'&');
        gusano[1] = Gusano(size,size/2,size/2+1,'%');
        
    }

    //Destructor de nuestra Clase
    ~Tablero(){
        delete[] gusano;
        delete[] cuerpoX1;
        delete[] cuerpoX2;
        delete[] cuerpoY1;
        delete[] cuerpoY2;
        
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

    void setPosicionesCabeza1();
    void setPosicionesCabeza2();

    void mandoGusanoUno();
    void mandoGusanoDos();
    void movimientoGusano();
    void cambiarDireccion(std::string &_direccion, int gusanoX, int gusanoY,std::string &choque);
    void direccionDisponible(std::string &_direccion, int gusanoX, int gusanoY);
    void buscarObstaculo();

    void crecerGusano(int *listaVaciaX, int *listaVaciaY, int _size);
    void reducirGusano(int *listaVaciaX, int *listaVaciaY, int _size);
    void lugaresVacios();
    void posicionesCuerpo1();
    void posicionesCuerpo2();
    int getVidas();
    void imprimirRegistro();
};
