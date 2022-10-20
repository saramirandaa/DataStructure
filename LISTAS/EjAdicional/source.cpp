#include "lista.h"

int main()
{
    ListaEnlazada listaA, listaB, listaC;
    int opc, val, val2, cont = 0;
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
           while(cont==0)
           {
                cont-=2;
                val = listaA.DeleteBeginning();
                listaC.InsertMiddle(val);
                val2 = listaB.DeleteBeginning();
                listaC.InsertMiddle(val2);
                cout<<cont<<endl;
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
