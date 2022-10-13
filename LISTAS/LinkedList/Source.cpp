/*Crear una lista enlazada con la opcion de insertar al principio, final o intermedio*/
#include "LinkedL.h"

int main()
{
    int opc = 0, modulo;
    int push, num;
    LkList insertar;
    do
    {
        cout<<"\t\t\tMENU\n";
        cout<<"1. Insertar Inicio\t 2. Insertar Inter\t 3. Insertar Final\t 4. Mostrar \t5. Salir"<<endl;
        cout<<"\tConsideracion -- se tienen #"<<insertar.cont<<" en la lista"<<endl;
        cout<<"Seleccion: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
            {
                cout<<"Cadena: ";
                cin>>push;
                insertar.PushFront(push);
                cout<<"**Se inserto"<<endl;
            break;
            }
            case 2:
            {
                cout<<"Cadena anterior: ";
                cin>>num;
                cout<<"Cadena: ";
                cin>>push;
                insertar.PushMid(push, num);
                break;
            }
            case 3:
                cout<<"Cadena: ";
                cin>>push;
                insertar.PushBack(push);
            break;
            case 4:
                insertar.display();
            break;
            case 5:
            cout<<"Gracias"<<endl;
            break;
        }
        
    } while (opc!=5);
    
}