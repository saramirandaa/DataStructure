#include "list.h"

int main()
{
    int opc = 0, modulo;
    int push, num;
    List insertar;
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
                insertar.addF(push);
            break;
            }
            case 2:
            {
                cout<<"Cadena anterior: ";
                cin>>num;
                cout<<"Cadena: ";
                cin>>push;
                insertar.addM(push, num);
                break;
            }
            case 3:
                cout<<"Cadena: ";
                cin>>push;
                insertar.addB(push);
            break;
            case 4:
                insertar.delF();
            break;
            case 5:
                cout<<"Cadena: ";
                cin>>push;
                insertar.delM(push);
            break;
            case 6:
                insertar.delB();
            break;
            case 7:
                insertar.print();
            break;
            case 8:
                cout<<"salir"<<endl;
            break;
            default:
                cout<<"null"<<endl;
            break;
        }
        
    } while (opc!=8);
    
}