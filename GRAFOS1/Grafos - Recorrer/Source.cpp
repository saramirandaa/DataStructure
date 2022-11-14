#include "ListaAdy.h" 

void main()
{
	int opc, peso, resulta;
	char nodo, orig, dest;

	ListaAdy grafo;

	do
	{
		cout << "\n1 Insertar Nodo  2 Insertar Arco  3 Mostrar" << endl;
		cout << "                   4 Recorrer Profundidad  5 Recorrer Ancho  6 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Que nodo quieres insertar (una letra): ";
			cin >> nodo;
			resulta = grafo.InsertarNodo(nodo);
			if (resulta == 0)
				cout << "\tOK. Se agrego nodo" << endl << endl;
			if (resulta == -1)
				cout << "\t%*YA EXISTE EL NODO. NO se inserto el nodo" << endl << endl;
			break;
		case 2:
			cout << "\tNodo origen (una letra): ";
			cin >> orig;
			cout << "\tNodo destino (una letra): ";
			cin >> dest;
			cout << "\tPeso del Arco: ";
			cin >> peso;

			resulta = grafo.InsertarArco(orig, dest, peso);		// Inserta ARCO Orig - Dest
			if (resulta == 0)
				cout << "\tOK. Se agrego el Arco " << orig << dest << endl << endl;
			if (resulta == -1)
				cout << "\t%*ERROR, NO existe el Nodo de origen o el Nodo de destino" << endl;
			if (resulta == -2)
				cout << "\t%*ERROR, YA existe el Arco. NO se inserto" << endl;

			resulta = grafo.InsertarArco(dest, orig, peso);		// Inserta ARCO Dest - Orig
			if (resulta == 0)
				cout << "\tOK. Se agrego el Arco " << dest << orig << endl << endl;
			if (resulta == -1)
				cout << "\t%*ERROR, NO existe el Nodo de origen o el Nodo de destino" << endl;
			if (resulta == -2)
				cout << "\t%*ERROR, YA existe el Arco. NO se inserto" << endl;
			break;
		case 3:
			grafo.Mostrar();
			break;
		case 4:
			grafo.RecorrerProfundidad();
			break;
		case 5:
			grafo.RecorrerAncho();
			break;
		default:
			break;
		}
	} while (opc < 6);

	cout << endl;
}