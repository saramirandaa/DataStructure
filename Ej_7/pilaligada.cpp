#include "pilaligada.h"

PilaLigada::PilaLigada()
{
    setlocale(LC_ALL, "");
    top = NULL;
}
void PilaLigada::push(Empleado nvoEmp)
{
    nuevo = new Empleado;
    *nuevo = nvoEmp;
    nuevo->anterior = top;
    top = nuevo;
}

Empleado PilaLigada::pop()
{
    Empleado vacio;
	vacio.cve = -1;
	Empleado resultado;
	if (top == NULL)
		return vacio;
	extraido = top;
	top = extraido->anterior;
	resultado = *extraido;
	delete extraido;
	return resultado;

}

void PilaLigada:: show()
{

}

void PilaLigada::clean(Empleado nodo)
{
    nodo.cve = 0;
    nodo.nom= "";

}