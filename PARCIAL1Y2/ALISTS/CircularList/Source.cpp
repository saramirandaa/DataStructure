#include "ListaCircular.h"

int main()
{
	string palabraNva, despuesDe, extraida, aExtraer;
	int opc;
	bool resultado;

	setlocale(LC_ALL, "");
	ListaCircular miLista;

	do
	{
		cout << "\n1 Mostrar   2 Insertar Inicio   3 Insertar Medio   4 Insertar Final" << endl;
		cout << "            5 Extraer Inicio    6 Extraer Medio    7 Extraer Final" << endl;
		cout << "            8 Salir: ";
		cin >> opc;

		if (opc > 1 && opc < 5)
		{
			cout << "\n\t�Qu� palabra insertar�s?: ";
			cin >> palabraNva;
		}
		switch (opc)
		{
		case 1:
			miLista.Mostrar();
			break;
		case 2:
			miLista.InsertarInicio(palabraNva);
			cout << "\tOK. Se insert� al INICIO" << endl;
			break;
		case 3:
			cout << "\t�Despu�s de que palabra quieres insertar?: ";
			cin >> despuesDe;
			resultado = miLista.InsertarMedio(palabraNva, despuesDe);
			if (resultado)
				cout << "\tOK. Se insert� INTERMEDIO " << endl;
			else
				cout << "\tERROR. No existe " << despuesDe << ". Se Insert� al Final" << endl;
			break;
		case 4:
			miLista.InsertarFinal(palabraNva);
			cout << "\tOK. Se insert� al FINAL" << endl;
			break;
		case 5:
			extraida = miLista.ExtraerInicio();
			if (extraida == "")
				cout << "\tLa lista est� VAC�A. NO se extrajo nada" << endl;
			else
				cout << "\tSe extrajo del INICIO la palabra " << extraida << endl;
			break;
		case 6:
			cout << "\t�Qu� palabra quieres extraer?: ";
			cin >> aExtraer;
			extraida = miLista.ExtraerMedio(aExtraer);
			if (extraida == "")
				cout << "\tNo existe la palabra " << aExtraer << ". NO se extrajo nada" << endl;
			else
				cout << "\tSe extrajo INTERMEDIA la palabra " << extraida << endl;
			break;
		case 7:
			extraida = miLista.ExtraerFinal();
			if (extraida == "")
				cout << "\tLa lista est� VAC�A. NO se extrajo nada" << endl;
			else
				cout << "\tSe extrajo del FINAL la palabra " << extraida << endl;
			break;
		default:
			break;
		}
	} while (opc < 8);
}