#include "ArrBidim.h"

int main()
{
    ArrBidim myArray;
    int sel;

    do
    {
        cout<<"1. Registro \t 2. Poblar \t 3. Ordenar \t 4. Mostrar \t 5. Salir"<<endl;
        cout<<"seleccion: ";
        cin>>sel;
        switch (sel)
        {
        case 1:
            myArray.Nombre();
            break;
         case 2:
            myArray.Poblar();
            break;
         case 3:
            myArray.Ordenar();
            break;
         case 4:
            myArray.Mostrar();
            break;
         case 5:
            cout<<"BYE"<<endl;
            break;
        default:
            cout<<"OPCION INVALIDA"<<endl;
            break;
        }
    } while (sel != 5);
    
}