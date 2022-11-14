#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
	setlocale(LC_ALL, "");
	Cabecera = Final = NULL;
	Revisado = Anterior = NULL;
	Nodo = NULL;
}

ListaCircular::~ListaCircular()
{}

void ListaCircular::InsertarInicio(string nva)
{
	Nodo = new Palabra();
	Nodo->dato = nva;
	if (!Cabecera)
	{
		Cabecera = Nodo;
		Final = Nodo;
		Revisado = Nodo;
	}
	Nodo->siguiente = Cabecera;
	Final->siguiente = Nodo;
	Cabecera = Nodo;
	Revisado = Nodo;
}

void ListaCircular::InsertarFinal(string nva)
{
	if (!Cabecera)
	{
		InsertarInicio(nva);
		return;
	}
	Nodo = new Palabra;
	Nodo->dato = nva;
	Final->siguiente = Nodo;
	Final = Nodo;
	Nodo->siguiente = Cabecera;
}

string ListaCircular::ExtraerInicio()
{
	string extraida = "";
	if (!Cabecera)
		return "";
	Nodo = Cabecera;
	if (Final == Cabecera)
		Cabecera = Final = Revisado = NULL;
	else
	{
		Cabecera = Nodo->siguiente;
		Final->siguiente = Nodo->siguiente;
	}
	if (Revisado == Nodo)
		Revisado = Nodo->siguiente;
	extraida = Nodo->dato;
	delete Nodo;

	return extraida;
}

string ListaCircular::ExtraerFinal()
{
	string extraida = "";
	Palabra* penultimo = NULL, * ultimo = NULL;

	if (!Cabecera)
		return "";
	if (Cabecera == Final)
	{
		extraida = ExtraerInicio();
		return extraida;
	}
	ultimo = Cabecera;
	penultimo = Final;
	while (ultimo->siguiente != Cabecera)
	{
		penultimo = ultimo;
		ultimo = ultimo->siguiente;
	}
	penultimo->siguiente = Cabecera;
	extraida = ultimo->dato;
	Final = penultimo;
	if (Revisado == ultimo)
		Anterior = Revisado = NULL;

	delete ultimo;
	return extraida;
}

bool ListaCircular::Buscar(string buscada)
{
	if (!Cabecera)
		return false;
	if (Revisado == NULL)
	{
		Revisado = Cabecera;
		Anterior = Final;
	}

	Nodo = Revisado;
	do
	{
		if (Nodo->dato == buscada)
		{
			Revisado = Nodo;
			return true;
		}
		else
		{
			Anterior = Nodo;
			Nodo = Nodo->siguiente;
		}
	} while (Nodo != Revisado);

	return false;
}
void ListaCircular::MostrarInicio()
{
	if (!Cabecera)
	{
		cout << "\n\t *** Lista VACÍA ***" << endl;
		return;
	}
	Nodo = Cabecera;
	cout << "\nLISTA (desde inicio):" << endl;
	do
	{
		cout << "\t" << Nodo->dato;
		if (Nodo == Cabecera)
			cout << "\t<-- Cabecera";
		if (Nodo == Final)
			cout << "\t<-- Final";
		if (Nodo == Revisado)
			cout << "\t<-- Encontrado";
		cout << endl;
		Nodo = Nodo->siguiente;
	} while (Nodo != Cabecera);

}
void ListaCircular::MostrarEncontrado()
{
	if (!Cabecera)
	{
		cout << "\n\t *** Lista VACÍA ***" << endl;
		return;
	}
	Nodo = Revisado;
	cout << "\nLISTA (desde Encontrada):" << endl;
	do
	{
		cout << "\t" << Nodo->dato;
		if (Nodo == Cabecera)
			cout << "\t<-- Cabecera";
		if (Nodo == Final)
			cout << "\t<-- Final";
		if (Nodo == Revisado)
			cout << "\t<-- Encontrado";
		cout << endl;
		Nodo = Nodo->siguiente;
	} while (Nodo != Revisado);

}