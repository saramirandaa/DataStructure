#include "PilasLigadas.h"

PilaLigada::PilaLigada()
{
    tope = NULL;
}
PilaLigada::~PilaLigada(){}

void  PilaLigada::Insertar(int nuevo)
{
    nodo = new Nodo;
    nodo->datos = nuevo;
}
int  PilaLigada::Extraer(){}
void  PilaLigada::Consultar(){}
void  PilaLigada::Mostrar(){}