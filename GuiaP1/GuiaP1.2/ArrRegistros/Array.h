#pragma once
#include <iostream>
using namespace std;

/*
Generar e inicializar un conjunto de registros que almacenen los datos de los empleadosde una fabrica
para cada empleado se debe almacenar su nombre, sus años de antiguedad y la cantidad de piezas fabricadas en cada unode los ultimos tres meses
se necesita que una vez inicializados los registros, los ordene en forma ascendente de acuerdo a la antiguedad, empleando el metodo burbuja
 */

class Array
{
private:
    string** empleado;
    int n_empleados;
    int datos;
public:
    Array();
    void Leer();
    void Mostrar();
    void Init();
    void Ordenar();

};