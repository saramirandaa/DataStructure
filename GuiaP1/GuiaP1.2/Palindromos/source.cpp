/*
Escribe con C++ un programa que empleando piilas, permite determinar si una palabra o frase 
*/
#include "Palindromo.h"

int main()
{
    Palindromo pal;
    string palabra;
    cout<<"PROGRAMA DE PALINDORMOS\n";
    cout<<"Escriba una palabra para determinar si es un palindromo"<<endl;
    cout<<"Palabra:";
    cin>>palabra;
    pal.Read_word(palabra);
    if (pal.Compare(palabra)==1)
        cout<<"La palabra "<<palabra<<" es un palindromo"<<endl;
    else
        cout<<"No es un palindromo"<<endl;
}