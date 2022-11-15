#include <iostream>
#include <queue>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	queue <char> letras;

	int opc, tam;
	char letra;

	do
	{
		cout << "\n1 Insertar   2 Extraer   3 Tamaño   4 Consultar   5 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\tLetra: ";
			cin >> letra;
			letras.push(letra);
			break;
		case 2:
			if (letras.empty())
				cout << "\n\tLa fila está vacía" << endl;
			else
			{
				letra = letras.front();
				letras.pop();
				cout << "\n\tSe extrajo la letra: " << letra << endl;
			}
			break;
		case 3:
			tam = letras.size();
			cout << "\n\tExisten " << tam << " letras en la fila" << endl;
			break;
		case 4:
			if (letras.empty())
				cout << "\n\tLa fila está vacía" << endl;
			else
			{
				letra = letras.front();
				cout << "\t" << "'" << letra << "' se encuentra al inicio de la fila" << endl;
				letra = letras.back();
				cout << "\t" << "'" << letra << "' se encuentra al final de la fila" << endl;
			}
			break;
		default:
			break;
		}
	} while (opc < 5);
}