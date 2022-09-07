#pragma once
#include <iostream>
using namespace std;
#define TAM 5

class PilaEnteros
{
public:
    PilaEnteros();
    ~PilaEnteros();
    int Insertar(int);
    int Extraer();
    void Mostrar();
    int Consultar();
private:
    int min, max, tope;
    int* pila;
};