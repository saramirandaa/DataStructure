#include "Binario.h"

Binario::Binario()
{
	setlocale(LC_ALL, "");
	raiz = NULL;
	nodo = NULL;
	aux = NULL;
}

Binario::~Binario()
{
}

Numero* Binario::Iniciar()
{
	return raiz;
}

void Binario::CrearNodo(int num)
{
	nodo = new Numero;
	nodo->valor = num;
	nodo->Izq = NULL;
	nodo->Der = NULL;
}

void Binario::Insertar(Numero* inicio)
{
	if (!raiz)
	{
		raiz = nodo;
		cout << "\tSe insert� como raiz" << endl;
		return;
	}
	if (nodo->valor < inicio->valor)	// Se insertar� a la izquierda
	{
		if (inicio->Izq == NULL)
		{
			inicio->Izq = nodo;
			cout << "\tSe insert� a la izquierda de " << inicio->valor << endl;
			return;
		}
		else
		{
			Insertar(inicio->Izq);
			return;
		}
	}
	if (nodo->valor > inicio->valor)	// Se insertar� a la derecha
	{
		if (inicio->Der == NULL)
		{
			inicio->Der = nodo;
			cout << "\tSe insert� a la derecha de " << inicio->valor << endl;
			return;
		}
		else
		{
			Insertar(inicio->Der);
			return;
		}
	}
	// Ya existe el valor. NO se inserta
	cout << "\tYa existe el valor " << nodo->valor << " NO se insert�" << endl;
	delete nodo;
}
void Binario::RecorrerINorden(Numero* inicio)
{
	if (!raiz)
	{
		cout << "\tEl �rbol est� vac�o" << endl;
		return;
	}
	if (inicio->Izq != NULL) RecorrerINorden(inicio->Izq);
	cout << "\t" << inicio->valor;
	if (inicio->Der != NULL)  RecorrerINorden(inicio->Der);
}
void Binario::RecorrerPREorden(Numero* inicio)
{
	if (!raiz)
	{
		cout << "\tEl �rbol est� vac�o" << endl;
		return;
	}
	cout << "\t" << inicio->valor;
	if (inicio->Izq != NULL) RecorrerPREorden(inicio->Izq);
	if (inicio->Der != NULL)  RecorrerPREorden(inicio->Der);
}
void Binario::RecorrerPOSorden(Numero* inicio)
{
	if (!raiz)
	{
		cout << "\tEl �rbol est� vac�o" << endl;
		return;
	}
	if (inicio->Izq != NULL) RecorrerPOSorden(inicio->Izq);
	if (inicio->Der != NULL)  RecorrerPOSorden(inicio->Der);
	cout << "\t" << inicio->valor;
}
void Binario::Extraer(Numero* padre, Numero* inicio, int valor, string subArbol)
{
	int aux;
	if (inicio == NULL)		// �rbol Vac�o
	{
		cout << "El valor NO existe en el arbol" << endl;
		return;
	}
	if (valor < inicio->valor)	// Busca por la izquierda
	{
		Extraer(inicio, inicio->Izq, valor, "izq");
		return;
	}
	if (valor > inicio->valor)	// Busca por la derecha
	{
		Extraer(inicio, inicio->Der, valor, "der");
		return;
	}

	if (inicio->Izq == NULL && inicio->Der == NULL)		// Caso 1: Nodo sin hijos
	{
		cout << "\tOK. (C1) se extrajo el valor " << inicio->valor << endl << endl;
		if (subArbol == "izq")
			padre->Izq = NULL;
		if (subArbol == "der")
			padre->Der = NULL;
		if (raiz == inicio)
			raiz = NULL;

		delete inicio;
		return;
	}

	if (inicio->Izq == NULL)		// Caso 2a: Solo hijo Der
	{
		if (subArbol == "izq")
			padre->Izq = inicio->Der;
		if (subArbol == "der")
			padre->Der = inicio->Der;
		cout << "\tOK. (C2) se extrajo el valor " << inicio->valor << endl << endl;
		if (raiz == inicio)
			raiz = inicio->Der;
		delete inicio;
		return;
	}
	if (inicio->Der == NULL)		// Caso 2b: Solo hijo Izq
	{
		if (subArbol == "izq")
			padre->Izq = inicio->Izq;
		if (subArbol == "der")
			padre->Der = inicio->Izq;
		cout << "\tOK. (C2) se extrajo el valor " << inicio->valor << endl << endl;
		if (raiz == inicio)
			raiz = inicio->Izq;
		delete inicio;
		return;
	}
	padreEnlace = "izq";
	Intercambiar(inicio, inicio, inicio->Izq, "izq");		// Caso 3: Nodo con 2 hijos
}
void Binario::Intercambiar(Numero* encontrado, Numero* actual, Numero* siguiente, string subArbol)
{
	int aux;
	if (subArbol == "izq")	// SubArbol Izquierdo
	{
		if (siguiente->Der == NULL)		// Es el nodo m�s a la derecha
		{
			cout << "\t(C3) Se intercambi� " << encontrado->valor << " por " << siguiente->valor << endl;
			aux = encontrado->valor;
			encontrado->valor = siguiente->valor;
			siguiente->valor = aux;
			Extraer(actual, siguiente, siguiente->valor, padreEnlace);
			return;
		}
		else        // Todav�a hay nodos m�s a la derecha, seguir avanzando a la derecha
		{
			padreEnlace = "der";
			Intercambiar(encontrado, siguiente, siguiente->Der, "izq");
			return;
		}
	}
	if (subArbol == "der")		// SubArbol Derecho
	{
		if (siguiente->Izq == NULL)		// Es el nodo m�s a la izquierda
		{
			cout << "\t(C3) Se intercambi� " << encontrado->valor << " por " << siguiente->valor << endl;
			aux = encontrado->valor;
			encontrado->valor = siguiente->valor;
			siguiente->valor = aux;
			Extraer(actual, siguiente, siguiente->valor, padreEnlace);
			return;
		}
		else       // Todav�a hay nodos m�s a la izquierda, seguir avanzando a la izquierda
		{
			padreEnlace = "izq";
			Intercambiar(encontrado, siguiente, siguiente->Izq, "der");
			return;
		}
	}
}