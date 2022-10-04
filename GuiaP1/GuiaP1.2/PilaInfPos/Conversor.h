#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Prededencias
{
	char operador;
	int preced;
};

class Conversor
{
public:
	Conversor();
	string Convertir(string infija);
	bool Llena();
	bool Vacia();
private:
	int Insertar(char op);
	char Extraer();
	Prededencias opera[6];
	int min, max, tope;
	char pila[40];
};
