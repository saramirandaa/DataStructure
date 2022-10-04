#pragma once
#include <iostream>
using namespace std;

struct Enteros
{
    int num;
    Enteros* sig;
};

class ColaLigada
{
public:
    ColaLigada();
    ~ColaLigada();
    int Extraer();
    void Insertar(int);
    void Mostrar();
private:
    Enteros* inicio, * final, * nodo;
};