#include "Lista.h"

Lista::Lista()
{
	setlocale(LC_ALL, "");
	cabecera = NULL;
	fin = NULL;
}
Lista::~Lista()
{}
void Lista::Mostrar()
{
	if (!cabecera)
	{
		cout << "\n\t**La lista está vacía **\n" << endl;
		return;
	}
	nodo = cabecera;
	cout << "\nLISTA ENLAZADA: " << endl;
	while (nodo)
	{
		cout << "\t" << nodo->num;
		if (nodo == cabecera)
			cout << "\t<== Cabecera";
		cout << endl;
		nodo = nodo->siguiente;
	}
	cout << "\n\t FIN de la Lista" << endl;
}

void Lista::InsertarOrden(int nuevo)
{
	bool encontrado = false;
	Enteros* anterior, * actual;

	nodo = new Enteros;
	nodo->num = nuevo;

	if (!cabecera)
	{
		nodo->siguiente = NULL;
		cabecera = nodo;
		fin = nodo;
		cout << "\tOK. Se insertó " << nuevo << " al inicio " << endl;
		return;
	}
	anterior = NULL;
	actual = cabecera;
	while (actual)
	{
		if (nuevo < actual->num)
		{
			encontrado = true;
			break;
		}
		anterior = actual;
		actual = actual->siguiente;
	}
	if (!encontrado)
	{
		nodo->siguiente = NULL;
		fin->siguiente = nodo;
		fin = nodo;
		cout << "\tOK. Se insertó " << nuevo << " al final " << endl;
		return;
	}
	if (!anterior)
	{
		nodo->siguiente = cabecera;
		cabecera = nodo;
		cout << "\tOK. Se insertó " << nuevo << " al inicio " << endl;
	}
	else
	{
		nodo->siguiente = anterior->siguiente;
		anterior->siguiente = nodo;	 // Paso 5
		cout << "\tOK. Se insertó " << nuevo << " después de " << anterior->num << endl;
	}

	return;
}
int Lista::ExtraerFin()
{
	int extraido;
	Enteros* anterior;

	extraido = -1;

	if (!cabecera)
	{
		cout << "\n\t**Lista VACIA. NO se extrae" << endl << endl;
		return extraido;
	}

	anterior = NULL;
	nodo = cabecera;
	while (nodo->siguiente != NULL)	// Paso 1
	{
		anterior = nodo;
		nodo = nodo->siguiente;
	}
	extraido = nodo->num;	// Paso 2

	if (!anterior)
	{
		cabecera = NULL;
	}
	else
	{
		anterior->siguiente = NULL;		// Paso 3
	}
	fin = anterior;		// Paso 4
	delete nodo;	// Paso 5

	return extraido;
}
int Lista::ExtraerIni()
{
	int extraido = -1;

	if (!cabecera)
	{
		cout << "\n\t**Lista VACIA. NO se extrae" << endl << endl;
		return extraido;
	}

	nodo = cabecera;	// Paso 1
	extraido = nodo->num;	// Paso 2
	cabecera = nodo->siguiente;	// Paso 3
	delete nodo;	// Paso 4
	return extraido;
}
int Lista::ExtraerInter(int numExtraer)
{
	int  extraido = -1;
	Enteros* anterior;
	bool bandera = false;


	if (!cabecera)
	{
		cout << "\n\t**Lista VACIA. NO se extrae" << endl << endl;
		return extraido;
	}

	anterior = NULL;
	nodo = cabecera;

	while (nodo != NULL)
	{
		if (nodo->num == numExtraer)	// Paso 1
		{
			bandera = true;
			break;
		}
		anterior = nodo;
		nodo = nodo->siguiente;
	}

	if (!bandera)	// Casó en que no existe en la lista el número buscado
	{
		cout << "\n**NO existe " << numExtraer << " en la lista. NO se extrajo" << endl;
		return extraido;
	}

	extraido = nodo->num;	// Paso 2

	if (!anterior)	// Caso en que el nodo extraido es el primero de la lista
		cabecera = nodo->siguiente;
	else    // Paso 3
		anterior->siguiente = nodo->siguiente;

	if (nodo == fin)	// Caso en que el nodo extraido es el último de la lista
		fin = anterior;

	delete nodo;	// Paso 4
	return extraido;
}