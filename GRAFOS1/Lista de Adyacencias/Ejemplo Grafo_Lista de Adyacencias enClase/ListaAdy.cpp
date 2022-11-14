#include "ListaAdy.h"

ListaAdy::ListaAdy()
{
	inicio = NULL;
}
int ListaAdy::InsertarNod(char nuevo)
{
	int existe;
	Nod* posicNodo;

	nodo = new Nod;	// Se crea el nodo
	nodo->nom = nuevo;
	nodo->nodSig = NULL;
	nodo->adySig = NULL;

	if (!inicio)	// El grafo está vacío. Se inserta el nodo
	{
		inicio = nodo;
		return 0;
	}
	existe = LocalizarNod(nuevo,posicNodo);

	if (existe == -1)	// El nodo no existe. Se inserta
	{
		posicNodo->nodSig = nodo;
		return 0;
	}

	delete nodo;	// Ya existe el nodo. NO se inserta. Se libera memoria
	return -1;
}
int ListaAdy::InsertarAdy(char ori, char des, int peso)
{
	int existeOri, existeDes, existeAdy;
	Nod* posicOri, * posicDes;
	Ady* posicAdy;

	if (!inicio)	// Grafo vacío, no existen nodos. NO se inserta
		return -1;

	adya = new Ady;		// Se crea la adyacencia
	adya->nom = des;
	adya->peso = peso;
	adya->adySig = NULL;

	existeOri = LocalizarNod(ori, posicOri);
	existeDes = LocalizarNod(des, posicDes);

	if (existeOri == -1 || existeDes == -1) // No existe nodo origen o destino. NO se inserta
		return -1;

	if (!posicOri->adySig)	// Lista de adyacencias (de origen) vacía. Se inserta al inicio
	{
		posicOri->adySig = adya;
		return 0;
	}

	existeAdy = LocalizarAdy(posicOri, des, posicAdy);

	if (existeAdy == -1)	// No existe adyacencia. Se inserta
	{
		posicAdy->adySig = adya;
		adya->dirDes = posicDes;
		return 0;
	}

	delete adya;	// Ya existe la adyacencia. NO se inserta
	return -2;
}
void ListaAdy::Mostrar()
{
	if (!inicio)
	{
		cout << "\n\tGrafo Vacío" << endl;
		return;
	}
	cout << "\nLISTA DE NODOS:" << endl;
	cout << "\n\t";

	auxnod = inicio;
	do
	{
		cout << auxnod->nom << " -> ";
		auxnod = auxnod->nodSig;
	} while (auxnod);
	cout << "NULL" << endl;
	
	cout << "\nLISTA DE ADYACENCIAS:\n" << endl;
	auxnod = inicio;
	do
	{
		cout << "\t" << auxnod->nom << " => ";
		auxady = auxnod->adySig;
		while (auxady)
		{
			cout << auxady->nom << "-" << auxady->peso << " -> ";
			auxady = auxady->adySig;
		}
		cout << "NULL" << endl;
		auxnod = auxnod->nodSig;
	} while (auxnod);
}
int ListaAdy::LocalizarNod(char nom, Nod*& posicNod)
{
	if (!inicio)	// El grafo esta vacío. NO existe el nodo
		return -1;
	auxnod = inicio;
	do
	{
		posicNod = auxnod;
		if (auxnod->nom == nom)	// Ya existe el nodo
			return 0;
		auxnod = auxnod->nodSig;
	} while (auxnod);

	return -1;	// No existe el nodo
}
int ListaAdy::LocalizarAdy(Nod* ori, char des, Ady*& posicAdy)
{
	if (!ori->adySig) // No hay adyacencias en el nodo
		return -1;
	auxady = ori->adySig;
	do
	{
		posicAdy = auxady;
		if (auxady->nom == des) // Ya existe la adyacencia
			return 0;
		auxady = auxady->adySig;
	} while (auxady);

	return -1;	// No existe la adyacencia
}