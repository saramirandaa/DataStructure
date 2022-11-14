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
	bool InsertarMedio(string, string);
	string ExtraerInicio();
	string ExtraerFinal();
	string ExtraerMedio(string);
	bool Buscar(string);
	void Mostrar();
private:
	Palabra* Cabecera, * Final, * Nodo, * Revisado, * Anterior;
};

