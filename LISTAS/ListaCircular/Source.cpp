#include "ListaCircular.h"

int main()
{
    int nuevo, buscado, opc;
    bool resultado;

    ListaCircular misNumeros;

    do
    {
        cout << "\n1. Insertar\t2. Buscar\t3. Mostrar\t4. Salir"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"Entero: ";
            cin>>nuevo;
            misNumeros.Insertar(nuevo);
            cout<<"**OK se insertó"<<endl;
        break;
        case 2:
        cout<<"Entero que buscas: ";
            cin>>buscado;
            resultado = misNumeros.Buscar(buscado);
            if (resultado)
                cout<<"\n\tOK. Se encontró"<<endl;
            else
                cout<<"\n\tNO se encontró"<<endl;            
        break;
        case 3:
            misNumeros.Mostrar();
        default:
            break;
        }
    } while (opc<4);
    
}