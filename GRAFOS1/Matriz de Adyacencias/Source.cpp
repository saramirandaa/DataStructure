#include "MatrizAdy.h"

int main()
{
	setlocale(LC_ALL, "");

	int numNodos, opc, codigo, peso;
	char nodo, ori, des;

	cout << "\nMáximo número de nodos: ";
	cin >> numNodos;
	MatrizAdy grafo(numNodos);

	do
	{
		cout << "\n1 Insertar Nodo   2 Insertar Arco   3 Mostrar   4 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\tNodo que insertarás (una letra): ";
			cin >> nodo;
			codigo = grafo.InsertarNodo(nodo);
			if (codigo == 0)
				cout << "\tOK. se insertó el Nodo" << endl;
			if (codigo == -1)
				cout << "\t**ERROR, ya existe el nodo. NO se insertó" << endl;
			if (codigo == -2)
				cout << "\t**ERROR, Arreglo lleno. NO se insertó" << endl;
			break;
		case 2:
			cout << "\tNodo de origen (una letra): ";
			cin >> ori;
			cout << "\tNodo de destino (una letra): ";
			cin >> des;
			cout << "\tPeso del arco (entero): ";
			cin >> peso;
			codigo = grafo.InsertarArco(ori, des, peso);
			if (codigo == 0)
				cout << "\tOK. Se insertó el Arco Bidireccional" << endl;
			if (codigo == -1)
				cout << "\t**ERROR, No existe el nodo de origen o el nodo de destino" << endl;
			if (codigo == -2)
				cout << "\t**ERROR, YA existe el arco. NO se insertó" << endl;
			break;
		case 3:
			grafo.Mostrar();
			break;
		case 4:
			break;
		default:
			cout << "\n\t**ERROR, Opción inválida" << endl;
			break;
		}
	} while (opc != 4);
}
