#include "ListaCircular.h"

void main()
{
	string palabraNva, despuesDe, extraida, aExtraer, buscada;
	int opc;
	bool resultado;

	setlocale(LC_ALL, "");
	ListaCircular miLista;

	do
	{
		cout << "\n1 Mostrar INI   2 Insertar Inicio      4 Insertar Final" << endl;
		cout << "                5 Extraer Inicio       7 Extraer Final" << endl;
		cout << "                8 Mostrar ENCONTRADA   9 Salir: ";
		cin >> opc;

		if (opc > 1 && opc < 5)
		{
			cout << "\n\t¿Qué palabra insertarás?: ";
			cin >> palabraNva;
		}
		switch (opc)
		{
		case 1:
			miLista.MostrarInicio();
			break;
		case 2:
			miLista.InsertarInicio(palabraNva);
			cout << "\tOK. Se insertó al INICIO ===" << endl;
			break;
		case 3:
			cout << "\n\t=== Opción NO disponible ===" << endl;

			break;
		case 4:
			miLista.InsertarFinal(palabraNva);
			cout << "\tOK. Se insertó al FINAL" << endl;
			break;
		case 5:
			extraida = miLista.ExtraerInicio();
			if (extraida == "")
				cout << "\tLa lista está VACÍA. NO se extrajo nada" << endl;
			else
				cout << "\tSe extrajo del INICIO la palabra " << extraida << endl;
			break;
		case 6:
			cout << "\n\t=== Opción NO disponible ===" << endl;
			break;
		case 7:
			extraida = miLista.ExtraerFinal();
			if (extraida == "")
				cout << "\tLa lista está VACÍA. NO se extrajo nada" << endl;
			else
				cout << "\tSe extrajo del FINAL la palabra " << extraida << endl;
			break;
		case 8:
			cout << "\n¿Que palabra buscas?: ";
			cin >> buscada;
			resultado=miLista.Buscar(buscada);
			if (resultado)
				cout << "\n\tOK. Se encontró " << buscada << " en la lista" << endl;
			else
				cout << "\n\t== NO Se encontró " << buscada << " en la lista ==" << endl;
			miLista.MostrarEncontrado();
			break;
		case 9:
			cout << "\n\tFINAL  ... <enter> para terminar ..." << endl;
			break;
		default:
			cout << "\n\t**ERROR, opción inválida" << endl;
			break;
		}
	} while (opc != 9);
}