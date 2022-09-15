#include "ArrBidim.h"

ArrBidim::ArrBidim()
{
    setlocale(LC_ALL, "");
  cout<<"Cuantos renglones?: ";
  cin>>reng;
  cout<<"Cuantas columnas?: ";
  cin>>col;

  array = new int*[reng];
    for (int i = 0; i<reng; ++i)
    {
        *(array+i) = new int[col];
    }
}

void ArrBidim::Mostrar()
{
    cout<<"\n"<<nombre<<"tu arreglo es: "<< endl;
    for(int i = 0; i<reng; i++)
    {
        for (int j = 0; j<col; ++j)
        {
            cout<<"\t"<<*(*(array+i)+j);
        }
        cout<<endl;
    }
}
void ArrBidim::Poblar()
{
    cout<<"\n"<<nombre<<"tu arreglo es: "<< endl;
    for(int i = 0; i<reng; i++)
    {
        for (int j = 0; j<col; ++j)
        {
            cout<<"num: ";
            cin>>*(*(array+i)+j);
        }
        cout<<endl;
    }
}

void ArrBidim::Nombre()
{
    cout<<"\nDime tu nombre: ";
    cin.ignore();
    getline(cin, nombre);
}


void ArrBidim::Ordenar()
{
    cout<<"\n\t\t... ordenando ..."<<endl;
    bool ordenado;
    int it;
    int aux;

    for(int i = 0; i<reng; ++i)
    {
        ordenado = false;
        it = 0;
        while(!ordenado)
        {
            ordenado = true;
            for(int j = 0; j<(col-1-it); j++)
            {
                if(*(*(array+i)+j)>*(*(array+i)+j+1))
                {
                    aux = *(*(array+i)+j);
                    *(*(array+i)+j) = *(*(array+i)+j+1);
                    *(*(array+i)+j+1)=aux;
                    ordenado = false;
                }
            }
            it++;
    
        }
    }
    Mostrar();
}