#include "PilasLigadas.h"

PilaLigada::PilaLigada()
{
    setlocale(LC_ALL, "");
    tope = NULL;
}
PilaLigada::~PilaLigada(){}

void  PilaLigada::Insertar(int nuevo)
{
    nodo = new Nodo;
    nodo->datos = nuevo;
    nodo->anterior = tope;
    tope = nodo;
}
int  PilaLigada::Extraer()
{
    int resultado;
    if (tope == NULL)
        return -1;
    extraido = tope;
    tope = extraido->anterior;

    resultado = extraido->datos;
    delete extraido;
    return resultado;
}
int PilaLigada::Consultar()
{
	if (tope == NULL)
		return -1;
	return tope->datos;
}

void PilaLigada::Mostrar()
{
	cout << "\nPILA:" << endl;
	if (tope == NULL)
	{
		cout << "\n\tPila Vacía" << endl;
		return;
	}
	nodo = tope;
	while (nodo != NULL)
	{
		cout << "\t" << nodo->datos << "\t" << nodo->anterior;
		if (nodo == tope) cout << "\t<-- Tope";
		cout << endl;

		nodo = nodo->anterior;
	}
	cout << endl;
}