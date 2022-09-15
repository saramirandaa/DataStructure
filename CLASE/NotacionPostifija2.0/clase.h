#include <iostream>
using namespace std;

struct Precedencias
{
    char operador;
    int preced;
};

class Conversor
{
public:
    Conversor();
    string Convertir();
};