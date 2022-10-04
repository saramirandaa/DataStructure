#include "Conversor.h"

void main()
{
	Conversor infApos;

	string infija, posfija;
	char otra;

	do
	{
		cout << "\nEscribe la expresion infija, sin espacios: ";
		getline(cin, infija);
		posfija = infApos.Convertir(infija);
		cout << "\nCadena posfija: " << posfija << endl << endl;
		cout << "Quieres convertir otra expresion <s/n>: ";
		cin >> otra;
		cin.ignore();
	} while (otra == 's');
	cout << endl;


	system("pause");
}
