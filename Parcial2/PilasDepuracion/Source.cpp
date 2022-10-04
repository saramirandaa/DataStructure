#include "PilaDepurada.h"

/*
    Aplicación que maneja dos pilas de enteros, en su implementación estáticas,
    la pila original y la pila depurada.
    En la pila original podrás ir insertando y extrayendo enteros a solicitud de usuario
    Cuando el usuario elija la opción depurar, debes solicitarle un entero menor y traspalear
    los enteros de la pila "original" a la pila "depurada", descartando los enteros menores a menor
    En todo momento habrá opción de mostrar ambas pilas
*/
void Depuration();

int main()
{
    PilaDepurada pila_inicial;
    PilaDepurada pila_depurada;
    bool depuracion =false; int menu, num;
    
    do
    {
        cout<<"1. Push\t 2. Pop\t 3. Show\t 4. Pull\t 5. Depurate\t 6. Exit"<<endl;
        cout<<"Selection: "; cin>>menu;
        switch(menu)
        {
            case 1:
            {
                pila_inicial.Push(num);
                break;
            }
            case 2:
            {
                pila_inicial.Pop();
                break;
            }
            case 3:
            {
                cout<<"\tPila Inicial"<<endl;
                pila_inicial.Show();
                cout<<"\tPila Depurada"<<endl;
                pila_depurada.Show();
                break;
            }
            case 4:
            {
                cout<<"Top: "<<pila_inicial.Pull()<<endl;
                break;
            }
            case 5:
            {
                Depuration();
                break;
            }
            case 6:
            {
                cout<<"Hasta Pronto"<<endl;
                break;
            }
            default:
                cout<<"\tVuelva a intentarlo"<<endl;
                break;
            
            
        }
    } while (menu!=6);
}

void Depuration()
{
    for(int i = 0; i<)
}