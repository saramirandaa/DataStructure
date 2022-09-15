#include "ArregloRegistros.h"

void main()
{
	setlocale(LC_ALL, "");
	int cuantos;

	cout << "¿De cuántos elementos quieres el arreglo?: ";
	cin >> cuantos;
	ArregloRegistros miLista(cuantos);

	miLista.Mostrar();
	miLista.Agregar();
	miLista.Mostrar();
	cout << "\n\t ... ordenando arreglo ...\n" << endl;
	miLista.Ordenar();
	miLista.Mostrar();
	cout << endl;

	system("pause");
}