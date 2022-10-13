#include "lista.h"

int main()
{
    ListaEnlazada listaA, listaB, listaC;
    int opc, val, cont;
    do
    {
        cout<<"Menu"<<endl;
        cout<<"1. Insertar A\n2. Insertar B\n3. Combinar\n4. Mostrar\n5. Salir"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"Valor: ";
            cin>>val;
            listaA.InsertMiddle(val);
            cont++;
        break;
        case 2:
            cout<<"Valor: ";
            cin>>val;
            listaB.InsertMiddle(val);
            cont++;
        break;
        case 3:
            for (int i = 0; i < cont; i++)
            {
                val = listaA.DeleteBeginning();
                listaC.InsertMiddle(val);
                val = listaB.DeleteBeginning();
                listaC.InsertMiddle(val);
            }
        break;
        case 4:
            listaA.Display();
            listaB.Display();
            listaC.Display();
        break;
        default:
            break;
        }
    } while (opc!=5);
    
    

}
