#include "ColaLigada.h"

ColaLigada::ColaLigada()
{
    inicio = final = nodo = NULL;
}

ColaLigada::~ColaLigada()
{}
void ColaLigada::Insertar(int nvo)
{
    nodo = new Enteros;
    nodo->num = nvo;
    nodo->sig = NULL;
    if (inicio == NULL)
        inicio = nodo;
    if(final!=NULL)
        inicio = nodo;
    if (final != NULL)
        final->sig = nodo;
    final = nodo;
}
int ColaLigada::Extraer()
{
    int extraido;
    if(inicio == NULL)
        return -1;
    nodo = inicio;
    extraido = nodo->num;
    inicio = nodo->sig;
    if(inicio == NULL)
        final = NULL;
    delete nodo;
}
