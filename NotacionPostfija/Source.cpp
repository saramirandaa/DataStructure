#include "Postfija.h"
#include<cstring>
/*
Lea en una cadena una expresión algebraica en notación infija y empleando
pilas la convierta a la notación polaca postfija y la muestre como una cadena.
*/
void Infija(string [], int *);
int main()
{
    Postfija objeto;
    int menu, num;
    int size = 0;
    int i2;
    string array[TAM];
    string signo[TAM];
    Infija(array, &size);
    cout<<"\n\tNOTACION INFIJA: ";
    for(int i = size; i>=0; --i)
    {
        cout<<array[i]<<" ";
        objeto.Push(*(array+i));
    }
    cout<<"\n\tNOTACION POSFIJA: ";
    for(int j=0; j<size; ++j)
    {
        i2 = j;
        if((objeto.Pull() == "+")||(objeto.Pull() == "*")||(objeto.Pull() == "/")||(objeto.Pull() == "-"))
        {
            signo[j] = objeto.Pull();
        }
        else
        {
            i2--;
            cout<<objeto.Pull();
        }
        objeto.Pop();
    }
    for (int h = size; h > 0 ; h--)
    {
        cout<<signo[h];
    }
    cout<<endl;
    

}

void Infija(string array[], int *size)
{
    string expresion1;
    cout<<"Escriba una expresion algebraica: ";
    cin>>expresion1;
    *size = expresion1.length();
    for (int i = 0; i < *size; i++)
    {
        array[i] = expresion1.at(i);
    }

}