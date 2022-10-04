#pragma once
#include <iostream>
using namespace std;

class ColaCircular
{
public:
    ColaCircular(int);
    int Insertar(string);
    string Extraer();
    void Mostrar();
private:
    int min, max, inicio, fin;
    string* palabras;
};