#include "ListaCircular.h"

void main()
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
			cout << "\n\t¿Qué palabra insertarás?: ";
			cin >> palabraNva;
		}
		switch (opc)
		{
		case 1:
			miLista.Mostrar();
			break;
		case 2:
			miLista.InsertarInicio(palabraNva);
			cout << "\tOK. Se insertó al INICIO" << endl;
			break;
		case 3:
			cout << "\t¿Después de que palabra quieres insertar?: ";
			cin >> despuesDe;
			resultado = miLista.InsertarMedio(palabraNva, despuesDe);
			if (resultado)
				cout << "\tOK. Se insertó INTERMEDIO " << endl;
			else
				cout << "\tERROR. No existe " << despuesDe << ". Se Insertó al Final" << endl;
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
			cout << "\t¿Qué palabra quieres extraer?: ";
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
				cout << "\tLa lista está VACÍA. NO se extrajo nada" << endl;
			else
				cout << "\tSe extrajo del FINAL la palabra " << extraida << endl;
			break;
		default:
			break;
		}
	} while (opc < 8);
}