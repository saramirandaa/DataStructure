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