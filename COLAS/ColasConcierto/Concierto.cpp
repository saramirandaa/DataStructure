#include "Concierto.h"

ColaCircular :: ColaCircular(int tam)
{
	min = 0;
	max = tam - 1;
	inicio = fin = -1;
	palabras = new string[tam];
	for (int i = 0; i < tam; i++) palabras[i] = "----";
}
ColaCircular ::~ColaCircular()
{

}
int ColaCircular::Insertar(string nueva)
{
	if (inicio == min && fin == max) //Cola llena
		return -1;
	if (fin + 1 == inicio) //Cola circular llena
		return -1;
	fin++;
	if (fin > max) //Fin lleg� a m�ximo, regresa a inicio
		fin = min;
	if (inicio == -1) //Solamente en la primer inserci�n
		inicio = fin;
	palabras[fin] = nueva;
	return 0;
}
string ColaCircular::Extraer()
{
	string extraida;

	if (inicio < min) //Cola vac�a
		return "";
	extraida = palabras[inicio];
	palabras[inicio] = "-";

	if (inicio == fin) //Se extrajo la �ltima palabra
	{
		inicio = fin - 1;
		return extraida;
	}

	inicio++;
    if(inicio>max)
        inicio = min;
	if (inicio == max) //Inicio lleg� a max, se regresa a min
		inicio = min;

	return extraida
		;
}
void ColaCircular::Mostrar()
{
	cout << "\nPALABRAS: " << endl;
	for (int i = min; i <= max; i++)
	{
		cout << palabras[i];
		if (i == min) cout << "\t <-- Mínimo";
		if (i == max) cout << "\t <-- Máximo";
		if (i == inicio) cout << "\t <-- Inicio";
		if (i == fin) cout << "\t <-- Final";
		cout << endl;
	}
	cout << endl;
}
