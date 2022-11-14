#include "FilaCirc.h"

int main()
{
	setlocale(LC_ALL, "");
	int opc, tam, codigo;
	string entra, sale;

	cout << "\nTama�o de la Fila: " << endl;
	cin >> tam;

	ColaCircular listaPalabras(tam);

	do
	{
		cout << "\n1 Insertar 2 Extraer 3 Mostrar 4 Salir: ";
		cin >> opc;

		switch (opc)
		{
			case 1:
				cout << "\tPalabra: ";
				cin >> entra;
				codigo = listaPalabras.Insertar(entra);
				if (codigo == 0)
					cout << "\tOK. Se insert�" << endl;
				else
					cout << "\t**Cola LLENA, no se insert�" << endl;
				break;
			case 2:
				sale = listaPalabras.Extraer();
				if (sale == "")
					cout << "\t**Cola VAC�A, nada que extraer" << endl;
				else
					cout << "\tSe extrajo la palabra " << sale << endl;
				break;
			case 3:
				listaPalabras.Mostrar();
				break;
			case 4:
				break;
			default:
				break;
		}
	} while (opc < 4);
}