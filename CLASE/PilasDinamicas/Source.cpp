#include "PilasLigadas.h"

int main()
{
    int opc, entra, sale;
    PilaLigada miPila;

    do
    {
        cout<<"\n1. Insertar    2. Extraer  3. Consultar    4. Mostrar  5. Salir";
        cout<<"\nOpcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            cin>> entra;
            miPila.Insertar(entra);
            miPila.Mostrar();
        break;
        case 2:
            miPila.Extraer();
            miPila.Mostrar();
        break;
        case 3:
            miPila.Consultar();
            miPila.Mostrar();
        break;
        case 4:
            miPila.Mostrar();
        break;
        case 5:
            cout<<"Gracias"<<endl;
        break;
        default:
        break;
         }
    } while (opc!=5);
    
}