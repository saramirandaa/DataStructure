#include "Palindromo.h"
#include <string>
Palindromo::Palindromo()
{
    setlocale(LC_ALL, "");
    tope = NULL;
}
Palindromo::~Palindromo(){}

void  Palindromo::Insertar(string nuevo)
{
    nodo = new Nodo;
    nodo->datos = nuevo;
    nodo->anterior = tope;
    tope = nodo;
}
string  Palindromo::Extraer()
{
    string resultado;
    if (tope == NULL)
        return "-1";
    extraido = tope;
    tope = extraido->anterior;

    resultado = extraido->datos;
    delete extraido;
    return resultado;
}
string Palindromo::Consultar()
{
	if (tope == NULL)
		return "-1";
	return tope->datos;
}
/*
void Palindromo::Read_word(string palabra)
{
    string array[TAM];
    int size;
    size = palabra.length();
    for (int i = 0; i < size; i++)
    {
        array[i] = palabra.at(i);
    }
}
*/
void Palindromo::Read_word(string palabra)
{
   int size = palabra.length(); string word;
    for (int i = 0; i < size; i++)
    {
        word = palabra.at(i);
        Insertar(word);
    } 
}

int Palindromo::Compare(string palabra)
{
    int size = palabra.length(); string word;
    string word_char;
    for (int i = 0; i < size; i++)
    {
        word_char = tope->datos;
        word.append(word_char);
        Extraer();
    }
    if(word == palabra)
        return 1;
    else
        return -1;

}