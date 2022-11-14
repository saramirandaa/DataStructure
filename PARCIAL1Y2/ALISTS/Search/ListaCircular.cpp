#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
	setlocale(LC_ALL, "");
	cabecera = final = nodo = revisado = NULL;
}
void ListaCircular::Insertar(int nuevo)
{
	nodo = new Numero;
	nodo->num = nuevo;
	
	if (cabecera == NULL)	// Si es el único nodo
	{
		cabecera = revisado = nodo;
	}
	else
	{
		final->sig = nodo;
	}
	nodo->sig = cabecera;
	final = nodo;
}
bool ListaCircular::Buscar(int buscado)
{
	nodo = revisado;
	if (cabecera == NULL)
	{
		cout << "\n\tLista VACÍA. No encontrado" << endl;
		return false;
	}
	do
	{
		if (nodo->num == buscado)
		{
			revisado = nodo;
			return true;
		}
		nodo = nodo->sig;
	} while (nodo != revisado);

	return false;
}
void ListaCircular::Mostrar()
{
	nodo = cabecera;
	cout << "\nLISTA DE ENTEROS:" << endl;

	if (cabecera == NULL)
	{
		cout << "\n\tLista VACÍA" << endl;
		return;
	}
	do
	{
		cout << "\t" << nodo->num;
		if (nodo == cabecera)
			cout << "\t" << "<-- cabecera";
		cout << endl;

		nodo = nodo->sig;
	} while (nodo != cabecera);
}