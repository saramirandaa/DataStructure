#include "Super.h"

int main()
{
    int opc, contador, modulo, c20, c25, caja;
    string push, pulled; bool fail = false;
    ColaLigada Caja20;
    ColaLigada Caja25;
    ColaLigada Caja10;
    opc = 0;
    do
    {
        cout<<"\t\t\tMENU\n";
        cout<<"1. Asignar turno\t 2. Estatus de las filas\t 3. Cobrar\t 4. Salir"<<endl;
        cout<<"Seleccion: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
            {
                contador++;  
                cout<<"Turno: ";
                cin>>push;
                if((contador%2) != 0)
                {
                    c20++;
                    Caja20.Insertar(push);
                }
                else
                {
                    c25++;
                    Caja25.Insertar(push);
                }
                if((c20<c25+1)||(c20+1>c25))
                    fail = true;
                break;
            }
            case 2:
            {
                contador--;
                cout<<"De que caja quiere cobrar?: "<<endl;
                cin>>caja;
                switch(caja)
                {
                    case 20: 
                        Caja20.Extraer();
                        c20--;
                    break;
                    case 25: 
                        Caja25.Extraer();
                        c25--;
                    break;
                    case 10:
                        Caja10.Extraer();
                    break;
                }
            break;
            }
            case 3:
                Caja20.Mostrar();
                cout<<endl;
                Caja25.Mostrar();
                cout<<endl;
                Caja10.Mostrar();
                cout<<endl;
            break;
            case 4:
            cout<<"Adiós"<<endl;
        }
        if(fail == true)
        {
            for (int i = 0; i < c20; i++)
            {
                pulled = Caja20.Extraer();
                Caja10.Insertar(pulled);
            }
            for (int i = 0; i < c25; i++)
            {
                pulled = Caja25.Extraer();
                Caja10.Insertar(pulled);
            }
            
        }
       
    } while (opc!=4);
    
}

