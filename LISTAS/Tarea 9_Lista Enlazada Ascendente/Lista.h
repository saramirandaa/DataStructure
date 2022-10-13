#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Enteros
{
	int num;
	Enteros* siguiente;
};

class Lista
{
public:
	Lista();
	~Lista();
	void Mostrar();
	void InsertarOrden(int nuevo);
	int ExtraerFin();
	int ExtraerIni();
	int ExtraerInter(int numExtraer);
private:
	Enteros* cabecera, * fin, * nodo;
};

