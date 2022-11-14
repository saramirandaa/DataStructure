#include "Lista.h"

int main()
{
	int nuevoEntero, anterior, extraido;
	int opcion;
	Lista miLista;
	setlocale(LC_ALL, "");

	do
	{
		cout << "\n1 Mostrar  2 Insertar   3 Extraer Prin  "
			<< "\n 4 Extraer Final  5 Extraer Inter  6 Salir: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			miLista.Mostrar();
			break;
		case 2:
			cout << "\n\t¿Qué entero insertas?: ";
			cin >> nuevoEntero;
			miLista.InsertarOrden(nuevoEntero);
			break;
		case 3:
			extraido = miLista.ExtraerIni();
			if (extraido != -1)
				cout << "\n\t se extrajo del INICIO: " << extraido << endl << endl;
			break;
		case 4:
			extraido = miLista.ExtraerFin();
			if (extraido != -1)
				cout << "\n\t se extrajo del FINAL: " << extraido << endl << endl;
			break;
		case 5:
			cout << "\n\tQué entero quieres extraer?: ";
			cin >> nuevoEntero;
			extraido = miLista.ExtraerInter(nuevoEntero);
			if (extraido != -1)
				cout << "\n\t se extrajo INTERMEDIO: " << extraido << endl << endl;
			break;
		default:
			break;
		}

	} while (opcion < 6);


	cout << endl << endl << endl;
	return 0;
}