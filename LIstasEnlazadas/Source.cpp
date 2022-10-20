#include "ListaDobleEnlace.h"

int main()
{
	setlocale(LC_ALL, "");

	ListaDobleEnlace misPalabras;
	int opc;
	string nueva, despuesDe, extraida, aExtraer;
	bool resultado;

	do
	{
		cout << "\n1 Insertar Ini      2 Insertar Fin      3 Insertar Inter";
		cout << "\n4 Extraer Ini       5 Extraer Fin       6 Extraer Inter";
		cout << "\n7 Mostrar Ini-Fin   8 Mostrar Fin-Ini   9 Salir: ";
		cin >> opc;

		if (opc < 4)
		{
			cout << "\n\t¿Qué palabra insertas?: ";
			cin >> nueva;
		}

		switch (opc)
		{
		case 1:
			misPalabras.InsertarIni(nueva);
			cout << "\tOK.Se insertó" << endl;
			break;
		case 2:
			misPalabras.InsertarFin(nueva);
			cout << "\tOK.Se insertó" << endl;
			break;
		case 3:
			cout << "\tDespúes de qué palabra quieres insertar: ";
			cin >> despuesDe;
			resultado = misPalabras.InsertarInter(nueva, despuesDe);
			if (resultado == true)
				cout << "\tOK.Se insertó despúes de " << despuesDe << endl;
			else
				cout << "\t**NO existe la palabra '" << despuesDe << "'. NO se insertó" << endl;
			break;
		case 4:
			extraida = misPalabras.ExtraerIni();
			if (extraida == "")
				cout << "\n\t**Lista VACÍA. NO se extrajo nada" << endl;
			else
				cout << "\n\tSe extrajo del INICIO la palabra: " << extraida << endl;
			break;
		case 5:
			extraida = misPalabras.ExtraerFin();
			if (extraida == "")
				cout << "\n\t**Lista VACÍA. NO se extrajo nada" << endl;
			else
				cout << "\n\tSe extrajo del FINAL la palabra: " << extraida << endl;
			break;
		case 6:
			cout << "\t¿Qué palabra quieres extraer?: ";
			cin >> aExtraer;
			extraida = misPalabras.ExtraerInter(aExtraer);
			if (extraida == "")
				cout << "\n\t**NO existe la palabra '" << aExtraer << "'. NO se extrajo" << endl;
			else
				cout << "\n\tSe extrajo la palabra INTERMEDIA: " << extraida << endl;
			break;
		case 7:
			misPalabras.MostrarIniFin();
			break;
		case 8:
			misPalabras.MostrarFinIni();
			break;
		default:
			break;
		}
	} while (opc < 9);
}