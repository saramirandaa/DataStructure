#include "Concierto.h"

int main()
{
    int opc, contador, modulo;
    string push;
    cout<<"#BOLETOS: ";
    cin>>opc;
    ColaCircular concierto(opc);
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
            {cout<<"Nombre: ";
            cin>>push;
            concierto.Insertar(push);
            contador++;
            break;}
            case 2:
            {cout<<"Ha salido de la fila"<<endl;
            concierto.Extraer();
            contador--;
            break;}
            case 3:
            concierto.Mostrar();
            break;
            case 4:
            cout<<"Gracias, diviertase en el concierto"<<endl;
        }
        modulo = contador%5;
        if(modulo == 0)
        {
            cout<<"\t\t\tHas ganado un vale de descuento"<<endl;
        }
    } while (opc!=4);
    
}