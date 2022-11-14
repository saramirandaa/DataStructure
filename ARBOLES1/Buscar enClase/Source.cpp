#include "Binario.h"

int main()
{
	setlocale(LC_ALL, "");

	Numeros* inicio;
	Numeros* encontrado;
	int valor, opc, aBuscar;

	Binario arbolBB;

	do
	{
		cout << "\n\n1 Insertar  2 Recorrer In-orden   " <<
			"3 Recorrer Pre-orden" << endl;
		cout << "\t4 Recorrer Pos-orden  5 Buscar  6 Salir: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\nValor que insertarás: ";
			cin >> valor;
			arbolBB.CrearNodo(valor);
			inicio = arbolBB.getRaiz();
			arbolBB.Insertar(inicio);
			break;
		case 2:
			inicio = arbolBB.getRaiz();
			arbolBB.Recorrer_inorden(inicio);
			break;
		case 3:
			inicio = arbolBB.getRaiz();
			arbolBB.Recorrer_preorden(inicio);
			break;
		case 4:
			inicio = arbolBB.getRaiz();
			arbolBB.Recorrer_posorden(inicio);
			break;
		case 5:
			cout << "\tEntero que buscas: ";
			cin >> aBuscar;
			inicio = arbolBB.getRaiz();
			encontrado = arbolBB.Buscar(inicio, aBuscar);
			if (encontrado!=NULL)
			{
				cout << "\tSub-arbol IN-orden:" << endl;
				arbolBB.Recorrer_inorden(encontrado);
			}
			break;
		case 6:
			break;
		default:
			cout << "\n\t**ERROR, opción inválida" << endl << endl;
			break;
		}
	} while (opc != 6);
}
