#include "colas.h"


int main()
{
	setlocale(LC_ALL, "");
	Cola Cadenas;
	int opc; string num, resultado;

	do
	{
		cout << "\n1 Insertar 2 Extraer 3 Mostrar 4 salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\t¿Qué cadena quieres insertar?: ";
			cin >> num;
			resultado = Cadenas.Insertar(num);
			if (resultado == "-1")
				cout << "\n\t**Cola LLENA. NO se inertó" << endl;
			else
				cout << "\n\tOK. Se insertó correctamente " << endl;
			break;
		case 2:
			resultado = Cadenas.Extraer();
			if (resultado == "-1")
				cout << "\n\t**Cola VACÍA. Nada que extraer " << endl;
			else
				cout << "\n\tSe extrajo el entero: " << resultado << endl;
			break;
		case 3:
			Cadenas.Mostrar();
			break;
		default:
			break;
		}
			

	} while (opc < 4);
}