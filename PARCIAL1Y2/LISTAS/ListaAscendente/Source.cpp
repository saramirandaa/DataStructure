/*Crear una lista enlazada con la opcion de insertar al principio, final o intermedio*/
#include "ListA.h"

int main()
{
    int opc = 0, modulo;
    int push, num;
    Lista_Ordenada insertar;
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
                insertar.Push(push);
                cout<<"**Se inserto"<<endl;
            break;
            }
            case 2:
                insertar.display();
            break;
            case 3:
            cout<<"Gracias"<<endl;
            break;
        }
        
    } while (opc!=3);
    
}