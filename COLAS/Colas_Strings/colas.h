/*Empleando C++ construye una aplicación que permita Insertar y Extraer palabras
en una cola secuencial, mediante la implementación estática de TDA Cola o sea, implementada mediante arreglos
Tambien debe ofrecer la opción de Mostrar el arreglo completo y  los parametros de la fila*/
#pragma once
#include <iostream>
using namespace std;
#define TAM 6

class Cola
{
public:
    Cola();
    ~Cola();
    string Extraer();
    string Insertar(string);
    void Mostrar();
private:
    string array[TAM];
    int min, max, inicio, fin;
};