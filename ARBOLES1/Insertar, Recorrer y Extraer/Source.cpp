#include "Binario.h"

void main()
{
	setlocale(LC_ALL, "");

	int valor, opc;
	Numero* inicio = NULL;

	Binario arbolBB;

	do
	{
		cout << "\n1 Insertar  2 Recorrer In-orden "
			"  3 Recorrer Pre-orden    4 Recorrer Pos-orden "
			"  5 Extraer   6 Salir: ";
		cin >> opc;
		if (opc < 6)
			inicio = arbolBB.Iniciar();
		switch (opc)
		{
		case 1:
			cout << "\tValor que insertarás: ";
			cin >> valor;
			arbolBB.CrearNodo(valor);
			arbolBB.Insertar(inicio);
			break;
		case 2:
			arbolBB.RecorrerINorden(inicio);
			cout << endl;
			break;
		case 3:
			arbolBB.RecorrerPREorden(inicio);
			cout << endl;
			break;
		case 4:
			arbolBB.RecorrerPOSorden(inicio);
			cout << endl;
			break;
		case 5:
			cout << "Que numero quieres extraer: ";
			cin >> valor;
			arbolBB.Extraer(NULL, inicio, valor, "");
		default:
			break;
		}
	} while (opc < 6);
}