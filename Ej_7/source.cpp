#include "pilaligada.h"

int main()
{
	Empleado fuera, sale;
	int opt, clave, sueldo;
	string nombre;
	PilaLigada miPila;

	do
	{
		cout << "\n1 Contratar  2 Despedir  3 Consultar  4 Mostrar  5 Salir: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "\tClave del nuevo empleado: ";
			cin >> clave;
			cout << "\tNombre nuevo empleado: ";
			cin >> nombre;
			cout << "\tSueldo del nuevo empleado: ";
			cin >> sueldo;
			miPila.push(clave, nombre, sueldo);
			break;
		case 2:
			fuera = miPila.pop();
			if (fuera.cve == -1)
				cout << "\n\t%Pila Vac�a. Nada que extraer" << endl;
			else
				cout << "\tSe extrajo el empleado: " << fuera.nom << endl;
			break;
		case 3:
			sale = miPila.();
			if (sale.cve == -1)
			{
				cout << "\n\tPila Vac�a";
			}
			else
			{
				cout << "El empleado consultado es: " << sale.nom << endl;
				cout << "La clave del empleado es: " << sale.cve << endl;
				cout << "El sueldo del empleado es: " << sale.sdo << endl;
			}
			break;
		case 4:
			miPila.Mostrar();
			break;
		default:
			break;
		}
	} while (opt < 5);
}