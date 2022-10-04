#pragma once
#include <iostream>
using namespace std;

struct Trailer
{
    int placas;
    string producto;
};
struct Cadenas
{
    Trailer cadena;
    Cadenas* sig;
};

class ColaLigada
{
public:
    ColaLigada();
    ~ColaLigada();
    string Extraer();
    void Insertar(Trailer);
    void Mostrar();
private:
    Cadenas* inicio, * final, * nodo;
};