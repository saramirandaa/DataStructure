#include "ListaDobleEnlace.h"

ListaDobleEnlace::ListaDobleEnlace()
{
	cabecera = final = NULL;
}
void ListaDobleEnlace::InsertarIni(string nva)
{
	nodo = new Palabras;	
	nodo->texto = nva;		
	nodo->sig = cabecera;	
	nodo->ante = NULL;		
	if (cabecera != NULL)	
		cabecera->ante = nodo;
	else
		final = nodo;
	cabecera = nodo;		
}
void ListaDobleEnlace::InsertarFin(string nva)
{
	if (cabecera == NULL)
	{
		InsertarIni(nva);
		return;
	}
	nodo = new Palabras;	
	nodo->texto = nva;		
	nodo->sig = NULL;		
	nodo->ante = final;		
	final->sig = nodo;		
	final = nodo;			
}
bool ListaDobleEnlace::InsertarInter(string nva, string despuesDe)
{
	bool encontrada = false;
	Palabras* anterior;
	if (!cabecera)
		return false;
	anterior = cabecera;
	do
	{
		if (anterior->texto == despuesDe)	
		{
			encontrada = true;
			break;
		}

		anterior = anterior->sig;

	} while (anterior != NULL);

	if (encontrada == false)
		return false;

	if (anterior == final)
	{
		InsertarFin(nva);
		return true;
	}
	nodo = new Palabras;		
	nodo->texto = nva;			
	nodo->sig = anterior->sig;	
	nodo->ante = anterior;		
	anterior->sig = nodo;		
	nodo->sig->ante = nodo;		

	return true;
}
string ListaDobleEnlace::ExtraerIni()
{
	string extraida;

	if (!cabecera)
		return "";

	nodo = cabecera;
	extraida = nodo->texto;

	cabecera = nodo->sig;	
	if (nodo == final)		
		final = NULL;
	else
		nodo->sig->ante = NULL;

	delete nodo;			

	return extraida;
}
string ListaDobleEnlace::ExtraerFin()
{
	string extraida;

	if (cabecera == NULL)
		return "";
	nodo = final;
	extraida = nodo->texto;

	final = nodo->ante;		
	if (nodo == cabecera)	
		cabecera = NULL;
	else
		final->sig = NULL;
	delete nodo;			

	return extraida;
}
string ListaDobleEnlace::ExtraerInter(string aExtraer)
{
	string extraida;
	bool encontrada = false;

	if (!cabecera)
		return "";

	nodo = cabecera;
	do					
	{
		if (nodo->texto == aExtraer)
		{
			encontrada = true;
			break;
		}
		nodo = nodo->sig;
	} while (nodo != NULL);
	if (!encontrada)	
		return "";
	if (nodo == cabecera)	
	{
		extraida = ExtraerIni();
		return extraida;
	}
	if (nodo == final)		
	{
		extraida = ExtraerFin();
		return extraida;
	}
	extraida = nodo->texto;
	nodo->ante->sig = nodo->sig;	
	nodo->sig->ante = nodo->ante;
	delete nodo;					

	return extraida;
}
void ListaDobleEnlace::MostrarIniFin()
{
	cout << "\nLista de Palabras:" << endl;
	cout << "\n\t === INICIO de la lista ===" << endl;
	if (!cabecera)
	{
		cout << "\n\t** Lista VAC�A" << endl;
		return;
	}
	nodo = cabecera;
	do
	{
		cout << "\t" << nodo->texto;
		if (nodo == cabecera) cout << "\t<== Cabecera";
		if (nodo == final) cout << "\t<== Final";
		cout << endl;

		nodo = nodo->sig;

	} while (nodo != NULL);
	cout << "\n\t === FIN de la lista ===" << endl;
}
void ListaDobleEnlace::MostrarFinIni()
{
	cout << "\nLista de Palabras:" << endl;
	if (!cabecera)
	{
		cout << "\n\t** Lista VAC�A" << endl;
		return;
	}

	cout << "\n\t === FIN de la lista ===" << endl;
	nodo = final;
	do
	{
		cout << "\t" << nodo->texto;
		if (nodo == cabecera) cout << "\t<== Cabecera";
		if (nodo == final) cout << "\t<== Final";
		cout << endl;

		nodo = nodo->ante;

	} while (nodo != NULL);
	cout << "\n\t === INICIO de la lista ===" << endl;
}