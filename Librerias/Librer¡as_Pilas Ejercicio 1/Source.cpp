#include <iostream>
#include <stack>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	stack <int> pila;

	int opc, num, tam;

	do
	{
		cout << "\n1 Insertar   2 Extraer   3 Tamaño   4 Consultar Tope   5 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\tEntero: ";
			cin >> num;
			pila.push(num);
			break;
		case 2:
			if (pila.empty())
				cout << "\n\tLa pila está vacía" << endl;
			else
			{
				num = pila.top();
				pila.pop();
				cout << "\n\tSe extrajo el entero: " << num << endl;
			}
			break;
		case 3:
			tam = pila.size();
			cout << "\n\tLa pila contiene " << tam << " enteros" << endl;
			break;
		case 4:
			if (pila.empty())
				cout << "\n\tLa pila está vacía" << endl;
			else
			{
				num = pila.top();
				cout << "\n\tEn el tope se encuentra el entero: " << num << endl;
			}
			break;
		default:
			break;
		}
	} while (opc < 5);
}