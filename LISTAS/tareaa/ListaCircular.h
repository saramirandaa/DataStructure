#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Palabra
{
	string dato;
	Palabra* siguiente;
};
class ListaCircular
{
public:
	ListaCircular();
	~ListaCircular();
	void InsertarInicio(string);
	void InsertarFinal(string);

	string ExtraerInicio();
	string ExtraerFinal();

	bool Buscar(string);
	void MostrarInicio();
	void MostrarEncontrado();

private:
	Palabra* Cabecera, * Final, * Nodo, * Revisado, * Anterior;
};

