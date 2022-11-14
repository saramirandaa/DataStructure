#pragma once
#include <iostream>
using namespace std;

struct Nod;

struct Ady
{
	char nom;
	int peso;
	Ady* adySig;
	Nod* dirDes;
};

struct Nod
{
	char nom;
	Nod* nodSig;
	Ady* adySig;
};
class ListaAdy
{
public:
	ListaAdy();
	int InsertarNod(char);
	int InsertarAdy(char, char, int);
	void Mostrar();
	int LocalizarNod(char, Nod*&);
	int LocalizarAdy(Nod*, char, Ady*&);
private:
	Nod* nodo,* auxnod, *inicio;
	Ady* adya,* auxady;
};

