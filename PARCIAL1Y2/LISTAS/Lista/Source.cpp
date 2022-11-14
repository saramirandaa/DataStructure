#include "Lista.h"

int main()
{
    int opc = 0, modulo;
    string push, num;
    Lista insertar;
    do
    {
        cout<<"\t\t\tMENU\n";
        cout<<"1. Insertar Inicio\t 2. Insertar Inter\t 3. Insertar Final\t 4. Mostrar \t5. Salir"<<endl;
        cout<<"Seleccion: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
            {
                cout<<"Cadena: ";
                cin>>push;
                insertar.InsertarInicio(push);
            break;
            }
            case 2:
            {
                cout<<"Cadena anterior: ";
                cin>>num;
                cout<<"Cadena: ";
                cin>>push;
                insertar.InsertarInter(push, num);
                break;
            }
            case 3:
                cout<<"Cadena: ";
                cin>>push;
                insertar.InsertarFinal(push);
            break;
            case 4:
                insertar.Mostrar();
            break;
            case 5:
            cout<<"Gracias"<<endl;
            break;
        }
        
    } while (opc!=5);
    
}