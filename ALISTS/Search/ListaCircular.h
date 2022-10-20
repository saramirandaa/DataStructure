#pragma once
#include <iostream>
using namespace std;

struct Numero
{
	int num;
	Numero* sig;
};
class ListaCircular
{
public:
	ListaCircular();
	void Insertar(int);
	bool Buscar(int);
	void Mostrar();
private:
	Numero* cabecera, * final, * nodo, * revisado;
};

