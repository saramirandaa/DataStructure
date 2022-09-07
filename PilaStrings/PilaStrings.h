#include <iostream>
using namespace std;
#define TAM 5

class PilaStrings
{
public:
    PilaStrings();
    ~PilaStrings();
    int Insertar(string);
    string Extraer();
    string Consultar();
    void Mostrar();
    int Seleccion(int);
private:
    int min, max, tope;
    string* pila;
};