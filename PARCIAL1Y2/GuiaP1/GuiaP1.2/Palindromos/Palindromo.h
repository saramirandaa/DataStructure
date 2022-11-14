#pragma once
#include <iostream>
#include<cstring>
using namespace std;
#define TAM 10


struct Nodo
{
    string datos;
    Nodo* anterior;
};
class Palindromo
{
public:
    Palindromo();
    ~Palindromo();
    void Insertar(string);
    string Extraer();
    string Consultar();
    int Compare(string);
    void Read_word(string);
private:
    Nodo *tope, *nodo, *extraido;
};

