#include "PilaDepurada.h"

PilaDepurada::PilaDepurada()
{
    setlocale(LC_ALL, "");
    min = 0;
    max = TAM - 1;
    top = min -1;
    pila = new int[TAM];
    for(int i=0; i<TAM; ++i)
    {
        *(pila+i) = 0;
    }
}
PilaDepurada::~PilaDepurada(){}

int PilaDepurada:: Push(int nuevo)
{
    if(top >= max)
        return -1;
    top++;
    *(pila+top) = nuevo;
    return 0;
}
int PilaDepurada::Pop()
{
    int popped;
    if(top<min)
        return -1;
    popped = pila[top];
    pila[top]=0000;
    top--;
    return popped;
}
int PilaDepurada::Pull()
{
    if (top<min)
        return -1;
    return pila[top];
}
void PilaDepurada::Show()
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
int PilaDepurada::Depuration(int index)
{
    return pila[index];
}

int PilaDepurada::Top()
{
    return top;
}

