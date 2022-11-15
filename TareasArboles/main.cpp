#include "Busqueda.h"
//Construir una aplicación que, construya un Árbol Binario
// de Búsqueda para los proveedores de una empresa.
int main()
{
    int opc = 0, valor = 0, aBuscar = 0;
    Binario arbolBB; 
    Numeros* inicio, * encontrado;
    do
	{
		cout << "\n\n1 Insertar  2 Recorrer In-orden   " <<
			"3 Recorrer Pre-orden" << endl;
		cout << "\t4 Recorrer Pos-orden  5 Buscar  6 Salir: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\nProvedor: ";
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
			cout << "\n\t**ERROR, opci�n inv�lida" << endl << endl;
			break;
		}
	} while (opc != 6);
}