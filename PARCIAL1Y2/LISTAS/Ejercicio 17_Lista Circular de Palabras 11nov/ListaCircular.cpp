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
	Nodo->siguiente = Cabecera;
	Final = Nodo;
}

bool ListaCircular::InsertarMedio(string nva, string despuesDe)
{
	bool encontrado;

	if (!Cabecera)
	{
		InsertarInicio(nva);
		return true;
	}

	encontrado = Buscar(despuesDe);

	if (!encontrado)
	{
		InsertarFinal(nva);
		return false;
	}
	Nodo = new Palabra;
	Nodo->dato = nva;
	Nodo->siguiente = Revisado->siguiente;
	Revisado->siguiente = Nodo;

	if (Revisado == Final)
		Final = Nodo;

	return true;
}

string ListaCircular::ExtraerInicio()
{
	string extraida = "";
	if (!Cabecera)
		return "";
	Nodo = Cabecera;
	extraida = Nodo->dato;
	if (Revisado == Cabecera)
		Revisado = Cabecera->siguiente;
	if (Final == Cabecera)
		Cabecera = Final = NULL;
	else
	{
		Cabecera = Nodo->siguiente;
		Final->siguiente = Nodo->siguiente;
	}

	delete Nodo;

	return extraida;
}

string ListaCircular::ExtraerFinal()
{
	string extraida = "";

	if (!Cabecera)
		return "";
	Nodo = Revisado;
	while (Nodo->siguiente != Final)
		Nodo = Nodo->siguiente;
	if (Revisado == Final)
		Revisado = Cabecera;
	Final = Nodo;
	Nodo = Nodo->siguiente;
	extraida = Nodo->dato;
	Final->siguiente = Cabecera;

	delete Nodo;

	return extraida;
}

string ListaCircular::ExtraerMedio(string aExtraer)
{
	bool encontrada;
	string extraida;

	if (!Cabecera)
		return "";

	encontrada = Buscar(aExtraer);

	if (!encontrada)
		return "";
	if (Nodo == Cabecera)
	{
		extraida = ExtraerInicio();
		return extraida;
	}
	if (Revisado == Nodo)
		Revisado = Cabecera;
	if (Final == Nodo)
		Final = Anterior;

	extraida = Nodo->dato;

	Anterior->siguiente = Nodo->siguiente;
	Revisado = Anterior->siguiente;

	delete Nodo;

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
void ListaCircular::Mostrar()
{

	if (!Cabecera)
	{
		cout << "\n\t *** Lista VAC�A ***" << endl;
		return;
	}
	Nodo = Cabecera;
	cout << "\nLISTA:" << endl;
	do
	{
		cout << "\t" << Nodo->dato;
		if (Nodo == Cabecera)
			cout << "\t<-- Cabecera";
		if (Nodo == Final)
			cout << "\t<-- Final";
		cout << endl;
		Nodo = Nodo->siguiente;
	} while (Nodo != Cabecera);

}