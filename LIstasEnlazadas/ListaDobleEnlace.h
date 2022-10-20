#pragma once
#include <iostream>
using namespace std;

struct Palabras
{
	Palabras* ante;
	string texto;
	Palabras* sig;
};

class ListaDobleEnlace
{ 
public:
	ListaDobleEnlace();
	void InsertarIni(string);
	void InsertarFin(string);
	bool InsertarInter(string, string);
	string ExtraerIni();
	string ExtraerFin();
	string ExtraerInter(string);
	void MostrarIniFin();
	void MostrarFinIni();
private:
	Palabras* cabecera, * final, * nodo;
};