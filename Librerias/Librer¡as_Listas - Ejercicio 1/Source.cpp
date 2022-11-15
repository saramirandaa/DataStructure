#include <iostream>
#include <list>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	list <string> lista;
	list <string>::iterator indi;

	int opc, tam;
	string palabra, despuesDe;

	do
	{
		cout << "\n1 InsertarIni   2 Insertar Fin   3 Consultar   4 Mostrar"
			<< "\n5 ExtraerIni   6 ExtraerFin"
			<< "   7 InsertarInter   8 ExtraerInter   9 Salir: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			cout << "\tPalabra que insertarás: ";
			cin >> palabra;
			lista.push_front(palabra);
			cout << "\tOK. Se insertó" << endl;
			break;
		case 2:
			cout << "\tPalabra que insertarás: ";
			cin >> palabra;
			lista.push_back(palabra);
			cout << "\tOK. Se insertó" << endl;
			break;
		case 3:
			cout << "\n\tLISTA DE PALABRAS:" << endl << endl;
			cout << "\t\tContiene:\t" << lista.size() << " palabras" << endl;
			if (!lista.empty()) cout << "\t\tEn inicio:\t" << lista.front() << endl;
			if (!lista.empty()) cout << "\t\tEn final:\t" << lista.back() << endl;
			break;
		case 4:
			if (lista.empty())
			{
				cout << "\n\tLa lista está vacía" << endl;
				break;
			}
			indi = lista.begin();
			while (indi != lista.end())
			{
				cout << "\t\t" << *indi;
				if (indi == lista.begin()) cout << "\t <== Inicio";
				indi++;
				if (indi == lista.end()) cout << "\t <== Final";
				cout << endl;
			}
			break;
		case 5:
			if (lista.empty())
			{
				cout << "\n\tLa lista está vacía" << endl;
				break;
			}
			palabra = lista.front();
			lista.pop_front();
			cout << "\n\tSe extrajo '" << palabra << "'" << endl;
			break;
		case 6:
			if (lista.empty())
			{
				cout << "\n\tLa lista está vacía" << endl;
				break;
			}
			palabra = lista.back();
			lista.pop_back();
			cout << "\n\tSe extrajo '" << palabra << "'" << endl;
			break;
		case 7:
			cout << "\tPalabra que insertarás: ";
			cin >> palabra;
			cout << "\tDespués de que palabra: ";
			cin >> despuesDe;
			indi = lista.begin();
			while (indi != lista.end() && *indi != despuesDe) indi++;
			if (indi == lista.end())
			{
				cout << "\n\tNO existe '" << despuesDe << "' Se insertó al final" << endl;
			}
			else
			{
				indi++;
				cout << "\n\tOK. Se insertó" << endl;
			}
			lista.insert(indi, palabra);
			break;
		case 8:
			cout << "\tPalabra que extraerás: ";
			cin >> palabra;

			indi = lista.begin();
			while (indi != lista.end() && *indi != palabra) indi++;
			if (indi == lista.end())
			{
				cout << "\n\tNO existe '" << palabra << "' NO se extrajo nada" << endl;
			}
			else
			{
				cout << "\n\tOK. Se extrajo '" << *indi << "'" << endl;
				lista.remove(palabra);
			}
			break;
		default:
			break;
		}
	} while (opc < 9);
}