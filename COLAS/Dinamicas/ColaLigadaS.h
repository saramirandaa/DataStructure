#pragma once
#include <iostream>
using namespace std;

struct Cadenas
{
    string cadena;
    Cadenas* sig;
};

class ColaLigada
{
public:
    ColaLigada();
    ~ColaLigada();
    string Extraer();
    void Insertar(string);
    void Mostrar();
private:
    Cadenas* inicio, * final, * nodo;
};

///////////////////////////////

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
///
#include "Trailers.h"

int main()
{
    int opc, contador, modulo;
    string push;
    Trailer trail;
    cout<<"#BOLETOS: ";
    cin>>opc;
    ColaLigada trailers;
    opc = 0;
    do
    {
        cout<<"\t\t\tMENU\n";
        cout<<"1. Entrar a la fila\t 2. Estatus de la fila\t 3. Salir de la Fila\t 4. Salir"<<endl;
        cout<<"Seleccion: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
            {cout<<"Placas: ";
            cin>>trail.placas;
            cout<<"Producto: ";
            cin>>trail.producto;
            trailers.Insertar(trail);
            contador++;
            break;}
            case 2:
            {cout<<"Ha salido de la fila"<<endl;
            trailers.Extraer();
            contador--;
            break;}
            case 3:
            trailers.Mostrar();
            break;
            case 4:
            cout<<"Gracias, diviertase en los trailers"<<endl;
        }
        modulo = contador%5;
        if(modulo == 0)
        {
            cout<<"\t\t\tHas ganado un vale de descuento"<<endl;
        }
    } while (opc!=4);
    
}