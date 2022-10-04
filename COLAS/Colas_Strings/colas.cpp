#include "colas.h"

Cola::Cola()
{
    min = 0;
    max = TAM -1;
    inicio = fin = -1;
    for(int i = 0; i<TAM; ++i)
    {
        array[i] = "0000";
    }
}

Cola::~Cola(){};

string Cola::Extraer()
{
    string extraido;
    if(fin < min && inicio < min) return "-1";
    if(inicio>fin) return "-1";
    extraido = array[inicio];
    array[inicio] = "0000";
    inicio++;
    return extraido;
}

string Cola::Insertar(string nuevo)
{
    if (fin == max) return "-1";
    fin++;
    if(inicio == -1) inicio++;
    array[fin] = nuevo;
    return "0";
}

void Cola::Mostrar()
{
    cout<<"\nCOLA: "<<endl;
    for (int i = TAM -1; i>=0; --i)
    {
        cout<<"\t"<<array[i];
        if(i==min) cout << "\t<== Minimo";
        if(i==max) cout << "\t<== Maximo";
        if(i==inicio) cout << "\t<== Inicio";
        if(i==fin) cout << "\t<== Final";
        cout<<endl;
    }
}

