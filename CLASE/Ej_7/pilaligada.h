#pragma once
#include <iostream>
using namespace std;

struct Empleado
{
    int cve;
    string nom;
    int sdo;
    Empleado* anterior;
};

class PilaLigada
{
public:
    PilaLigada();
    void push(Empleado);
    Empleado pop();
    void show();
    void clean(Empleado);
private:
    Empleado* top;
    Empleado* nuevo;

};