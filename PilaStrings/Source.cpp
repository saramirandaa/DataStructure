#include "PilaStrings.h"

/* Empleando C++, Realiza la implementación de pilas sobre un arreglo estático del tamaño que tu decidas de una Pila de
pantallas. Para cada pantalla se registrará su modelo qeu inicia con una letra, seguida de digitos
*/

int main()
{
    PilaStrings pila;
    int seleccion;
    string val;

    pila.Mostrar();
    
    do
    {
        cout<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Consultar"<<endl;
        cout<<"4. Mostrar"<<endl;
        cout<<"\nSeleccion: ";
        cin>>seleccion;
        switch(seleccion)
        {
            case 1:
            {
                cout<<"\n\tNuevo valor: ";
                cin>>val;
                pila.Insertar(val);
                pila.Mostrar();
                break;
            }
            case 2:
            {
                pila.Extraer();
                pila.Mostrar();
                break;
            }
            case 3:
            {
                cout<<"\tTope: "<<pila.Consultar();
                break;
            }
            case 4:
            {
                pila.Mostrar();
                break;
            }
            default:
                cout<<"vuelva a intentarlo";
                break;      
        }
        
    } while (seleccion!=0);
    
    
}