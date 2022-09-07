#include "PilaStrings.h"

PilaStrings::PilaStrings()
{
    setlocale(LC_ALL, "");
    min = 0;
    max = TAM - 1;
    tope = min -1;
    pila = new string[TAM];
    for(int i=0; i<TAM; ++i)
    {
        *(pila+i) = "0000";
    }
}

PilaStrings::~PilaStrings(){}

int PilaStrings::Insertar(string nuevo)
{
    // Paso 1: Verificar que existe capacidad
    if(tope >= max)
        return -1;
    // Paso 2: Incrementa valor de tope
    tope++;
    //Paso 3: Insertar el nuevo valor en la posición de tope
    *(pila+tope) = nuevo;
    return 0;
}

string PilaStrings:: Extraer()
{
    string extraido;
    // Paso 1: Verificar que hay valores en la pila
    if(tope<min)
        return "-1";
    //Paso 2: Extraer el valor de la posición señalada por tope
    extraido = pila[tope];
    //Paso 3: Decrementar el valor de tope
    tope--;
    return extraido;
}

void PilaStrings:: Mostrar()
{
    cout<<"\nPILA: "<<endl;
    for(int i = max; i>=0; i--)
    {
        cout<<"\t"<<pila[i];
        if(i == min) cout <<"\t<= Mínimo";
        if(i == max) cout << "\t<= Máximo";
        if(i == tope) cout << "\t<= Tope"; 
    }
}

string PilaStrings::Consultar()
{
    //Paso 1: Verificar si hay valores
    if (tope<min)
        return "-1";
    return pila[tope];
}
