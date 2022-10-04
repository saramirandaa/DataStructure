#pragma once
#include <iostream>
using namespace std;

struct Cadenas
{
    string cadena;
    Cadenas* sig;
};

class ColaLigada
{
public:
    ColaLigada();
    ~ColaLigada();
    string Extraer();
    void Insertar(string);
    void Mostrar();
private:
    Cadenas* inicio, * final, * nodo;
};