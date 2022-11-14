#include "ECirc.h"

int main()
{
	string palabraNva, despuesDe, extraida, aExtraer;
	int opc, count;
	bool resultado;

	setlocale(LC_ALL, "");
	ECirc miLista;

	do
	{
		cout << "\n1 Mostrar\n2 Insertar Inicio\n3 Insertar Medio\n4 Insertar Final" << endl;
		cout << "5 Extraer Inicio\n6 Extraer Medio\n7 Extraer Final" << endl;
		cout << "8 Impares\n9 Salir: "<<endl;
        cout<<"OPCION: ";
		cin >> opc;

		if (opc > 1 && opc < 5)
		{
			cout << "\n\t¿Qué palabra insertarás?: ";
			cin >> palabraNva;
		}
		switch (opc)
		{
		case 1:
            cout<<"\tContamos con "<<count<<" nodos"<<endl;
			miLista.Show();
			break;
		case 2:
			miLista.InsertB(palabraNva);
			cout << "\tOK. Se insertó al INICIO" << endl;
            count++;
			break;
		case 3:
			cout << "\t¿Después de que palabra quieres insertar?: ";
			cin >> despuesDe;
			resultado = miLista.InsertM(despuesDe, palabraNva);
            count++;
			if (resultado)
				cout << "\tOK. Se insertó INTERMEDIO " << endl;
			else
				cout << "\tERROR. No existe " << despuesDe << ". Se Insertó al Final" << endl;
			break;
		case 4:
			miLista.InsertE(palabraNva);
            count++;
			cout << "\tOK. Se insertó al FINAL" << endl;
			break;
		case 5:
			extraida = miLista.ExtractI();
			if (extraida == "")
				cout << "\tLa lista está VACÍA. NO se extrajo nada" << endl;
			else
				{cout << "\tSe extrajo del INICIO la palabra " << extraida << endl;
                count--;}
			break;
		case 6:
			cout << "\t¿Qué palabra quieres extraer?: ";
			cin >> aExtraer;
			extraida = miLista.ExtractM(aExtraer);
			if (extraida == "")
				cout << "\tNo existe la palabra " << aExtraer << ". NO se extrajo nada" << endl;
			else
				{cout << "\tSe extrajo INTERMEDIA la palabra " << extraida << endl;
                count--;}
			break;
		case 7:
			extraida = miLista.ExtractE();
			if (extraida == "")
				cout << "\tLa lista está VACÍA. NO se extrajo nada" << endl;
			else
            {
                cout << "\tSe extrajo del FINAL la palabra " << extraida << endl;
                count--;
            }
			break;
        case 8:
            miLista.Odds();
            cout<<"\tSe eliminaron los impares"<<endl;
            break;
		default:
			break;
		}
	} while (opc < 9);
}