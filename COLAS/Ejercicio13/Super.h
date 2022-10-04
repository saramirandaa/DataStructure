#pragma once
#include <iostream>
using namespace std;

struct Enteros
{
    string cadena;
    Enteros* sig;
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
    Enteros* inicio, * final, * nodo;
};