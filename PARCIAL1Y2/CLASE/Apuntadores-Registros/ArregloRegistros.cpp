#include "ArregloRegistros.h"


ArregloRegistros::ArregloRegistros(int tam)
{
	setlocale(LC_ALL, "");
	tamano = tam;
	lista = new	Empleado[tamano];
	for (int i = 0; i < tamano; i++)
		(lista + i)->piezas = new int[3];

	ocupados = 0;
}

ArregloRegistros::~ArregloRegistros()
{
}

void ArregloRegistros::Agregar()
{
	char otro = 's';
	while (otro == 's')
	{
		if (ocupados >= tamano)
		{
			cout << "\n\t%Arreglo LLENO. NO se puede agregar" << endl;
			return;
		}
		cout << "antigüedad: ";
		cin >> (lista + ocupados)->anti;
		cout << "nombre: ";
		cin.ignore();
		getline(cin, (lista + ocupados)->nom);
		for (int i = 0; i < 3; i++)
		{
			cout << "piezas(entero) " << i << ": ";
			cin >> (lista + ocupados)->piezas[i];
		}

		ocupados++;
		cout << "\n\tQuieres agregar otro Empleado? (s/n): ";
		cin >> otro;
	}
}

void ArregloRegistros::Mostrar()
{
	cout << "\n\t\tA R R E G L O\n" << endl;
	if (ocupados == 0)
		cout << "\t *** Arreglo vacío ***" << endl;
	for (int i = 0; i < ocupados; i++)
	{
		cout << "Antigüedad: " << (lista + i)->anti
			 << "\t" << "Nombre: " << (lista + i)->nom;
		cout << "\tPiezas:";
		for (int j = 0; j < 3; j++)
			cout << "\t" << (lista + i)->piezas[j];
		cout << endl;
	}
	cout << endl;
}

void ArregloRegistros::Ordenar()
{
	Empleado aux;
	int iter = 0;
	bool orden = false;

	while (!orden)
	{
		orden = true;
		for (int i = 0; i < ocupados - 1 - iter; i++)
		{
			if ((lista + i)->anti > (lista + i + 1)->anti)
			{
				orden = false;
				aux = *(lista + i);
				*(lista + i) = *(lista + i + 1);
				*(lista + i + 1) = aux;
			}
		}
		iter++;
	}
}