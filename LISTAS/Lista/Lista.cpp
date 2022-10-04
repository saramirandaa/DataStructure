#include "Lista.h"

Lista::Lista()
{
    cabecera = final = nodo = NULL;
}

Lista::~Lista()
{
}

void Lista::InsertarInicio(string nueva)
{
    nodo = new Palabra;
    nodo->dato = nueva;
    nodo->sig = cabecera;
    cabecera = nodo;

    if(final == NULL)
        final = nodo;
}

void Lista::InsertarFinal(string nueva)
{
    if (!cabecera)
    {
        InsertarInicio(nueva);
        return;
    }
    nodo = new Palabra;
    nodo->dato = nueva;
    nodo->sig = NULL;
    final->sig = nodo;
    final = nodo;
}

void Lista::InsertarInter(string nueva, string anterior)
{
    Palabra * nodoAnter;
    if (!cabecera)
    {
        cout<<"Lista VACIA. Se inserta al inicio"<<endl;
        InsertarInicio(nueva);
        return;
    }
    /* Paso 1: Localizar la posición */
    nodoAnter = cabecera;
    
    while(nodoAnter)
    {
        if(nodoAnter->dato == anterior)
        {
            /* Paso 2: Crear nuevo nodo */
            nodo = new Palabra;
            /* Paso 3: Llenar campo de datos */
            nodo->dato = nueva;
            /* Paso 4: Llenar campo de enlace */
            nodo->sig = nodoAnter->sig;
            /* Paso 5: Cambiar enlace de nodo anterior */
            nodoAnter->sig = nodo;
            if (nodoAnter == final)
                final = nodo;
            return;
        }
        nodoAnter = nodoAnter->sig;
    }
    cout<<"\n No existe "<< anterior << " se inserta al final"<<endl;
    InsertarFinal(nueva);
}

void Lista::Mostrar()
{
    cout<<endl;
    if (cabecera == NULL)
    {
        cout<<"\n\tLista Vacia"<<endl;
        return;
    }
    nodo = cabecera;
    while(nodo != NULL)
    {
        cout<<"\t"<<nodo->dato;
        if(nodo == cabecera) cout << "\t<-- INICIO";
        if(nodo == final) cout << "\t<-- FINAL";
        cout<<endl;
        nodo = nodo->sig;
    }
}