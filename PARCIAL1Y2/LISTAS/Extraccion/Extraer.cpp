#include "Extraer.h"

Lista::Lista()
{
    cabecera = final = nodo = NULL;
}
Lista::~Lista(){}

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

string Lista::ExtraerInicio()
{
    string extraida;

    if(cabecera == NULL) //if (!cabecera)
        return "";
    // Paso 1: Localizar primer nodo 
    nodo = cabecera;
    // Paso 2: Tomar y devolver la información a extraer
    extraida = nodo ->dato;
    // Paso 3 Apuntar a cabecera al nodo siguiente
    cabecera = nodo->sig;
    // Paso 4: Liberar el nodo extraido
    delete nodo;

    return extraida;
}

string Lista::ExtraerFinal()
{
    string extraida;
    Palabra * nodoAnter;
    if(cabecera == NULL)
        return "";
    if(final == cabecera) //caso en que solo hay un nodo en la lista
    {
        extraida = ExtraerInicio();
        return extraida;
    }

    nodoAnter = NULL;
    nodo = cabecera;

    while(nodo != final)
    {
        nodoAnter = nodo;
        nodo = nodo->sig;
    }

    //Paso 2: Tomar y devolver informacion a extraer
    extraida = nodo->dato;
    //Paso 3: Apunta a NULL el enlace de nodo anterior
    nodoAnter->sig = NULL;
    //Apuntar Final a nodo anterior
    final = nodoAnter;
    //Paso 5: Liberar el nodo extraido
    delete nodo;

    return extraida;
}

string Lista::ExtraerInter(string aExtraer)
{
    string extraida;
    Palabra * nodoAnter;
    bool encontrado = false;
    if(cabecera == NULL)
        return "";
    nodoAnter = NULL;
    nodo = cabecera;
    
    while(nodo!=NULL)
    {
        if(nodo->dato==aExtraer)
        {
            encontrado = true;
            break;
        }
        nodoAnter = nodo;
        nodo = nodo->sig;

    }
    //Paso 2: Tomar y devolcer la informacion extraida
    if(!encontrado)
        return "";
    extraida = nodo->dato;
    //Paso 3: Apuntar enlace de nodo anterior al nodo siguiente al extraido
    nodoAnter->sig = nodo->sig;

    if(nodo == cabecera) //Caso en que el nodo extraido es el primero
        cabecera = nodo->sig;
    if (nodo == final)
        final == nodoAnter; // Caso en el que el nodo extraido es el final
    
    delete nodo;
    return extraida;
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