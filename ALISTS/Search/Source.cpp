#include "ListaCircular.h"

void main()
{
	int nuevo, buscado, opc;
	bool resultado;

	ListaCircular misNumeros;

	do
	{
		cout << "\n1 Insertar  2 Buscar  3 Mostrar  4 Salir: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "Entero que insertas: ";
			cin >> nuevo;
			misNumeros.Insertar(nuevo);
			cout << "\tOK. Se insertó" << endl;
			break;
		case 2:
			cout << "Entero que buscas: ";
			cin >> buscado;
			resultado = misNumeros.Buscar(buscado);
			if (resultado)
				cout << "\n\tOK. Se encontró" << endl;
			else
				cout << "\n\tNO se encontró" << endl;
			break;
		case 3:
			misNumeros.Mostrar();
			break;
		default:
			break;
		}
	} while (opc < 4);
}