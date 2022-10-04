#pragma once
#include <iostream>
using namespace std;

struct Palabra
{
    string dato;
    Palabra* sig;
};
class Lista
{
private:
    Palabra* cabecera, *final, *nodo;
public:
    Lista();
    ~Lista();
    void InsertarInicio(string);
    void InsertarFinal(string);
    void InsertarInter(string, string);
    void Mostrar();
};
