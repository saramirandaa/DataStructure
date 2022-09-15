#include "Postfija.h"

Postfija::Postfija()
{
    setlocale(LC_ALL, "");
    min = 0;
    max = TAM - 1;
    top = min -1;
    pila = new string[TAM];
    for(int i=0; i<TAM; ++i)
    {
        *(pila+i) = "0000";
    }
}
Postfija::~Postfija(){}

int Postfija:: Push(string nuevo)
{
    if(top >= max)
        return -1;
    top++;
    *(pila+top) = nuevo;
    return 0;
}
string Postfija::Pop()
{
    string popped;
    if(top<min)
        return "-1";
    popped = pila[top];
    pila[top]="0000";
    top--;
    return popped;
}
string Postfija::Pull()
{
    if (top<min)
        return "-1";
    return pila[top];
}
void Postfija::Show()
{
    cout<<"\nPILA: "<<endl;
    for(int i = max; i>=0; i--)
    {
        cout<<"\t"<<pila[i];
        if(i == min) cout <<"\t<= Mínimo";
        if(i == max) cout << "\t<= Máximo";
        if(i == top) cout << "\t<= Tope"; 
        cout<<endl;
    }
}

int Postfija::Top()
{
    return top;
}


