#include "ListaEnlazada.h"

int main()
{
    ListaEnlazada list;
    int choice, value;
    cout<<list.n_nodes;
    do
    {
        cout<<"\tMENÚ\n1.Insert\n2.Delete\n3.Display\n4.Exit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Number: ";
                cin>>value;
                list.InsertMiddle(value);
                cout<<"...INSERTED...";
                break;
            case 2:
                cout<<"Delete: ";
                cin>>value;
                list.DeleteMiddle(value);
                cout<<"...DELETED...";
                break;
            case 3:
                list.Display();
            default:
                break;
        }
    } while (choice!=4);
    
    


}