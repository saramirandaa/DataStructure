#pragma once
#include <iostream>
using namespace std;
#define TAM 4

class ArrBidim
{
public:
    ArrBidim();
    void Mostrar();
    void Nombre();
    void Ordenar();
    void Poblar();
private:
    string nombre;
    int** array;
    int reng;
    int col;
};

