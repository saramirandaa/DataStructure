#include "ColaLigadaS.h"

ColaLigada::ColaLigada()
{
    inicio = final = nodo = NULL;
}

ColaLigada::~ColaLigada()
{}
void ColaLigada::Insertar(string nvo)
{
    nodo = new Cadenas;
    nodo->cadena = nvo;
    nodo->sig = NULL;
    if (inicio == NULL)
        inicio = nodo;
    if(final!=NULL)
        inicio = nodo;
    if (final != NULL)
        final->sig = nodo;
    final = nodo;
}
string ColaLigada::Extraer()
{
    string extraido;
    if(inicio == NULL)
        return "0000";
    nodo = inicio;
    extraido = nodo->cadena;
    inicio = nodo->sig;
    if(inicio == NULL)
        final = NULL;
    delete nodo;
}
void ColaLigada::Mostrar()
{
    cout<<"\nFRASES: "<<endl;
    if (inicio == NULL)
    {
        cout<<"\n\tCola Vacia"<<endl;
        return;
    }
    nodo = inicio;
    while(nodo != NULL)
    {
        cout<<nodo->cadena;
        if(nodo == inicio) cout << "\t<-- INICIO"<<endl;
        if(nodo == final) cout << "\t<-- FINAL"<<endl;
        cout<<endl;
        nodo = nodo->sig;
    }
}