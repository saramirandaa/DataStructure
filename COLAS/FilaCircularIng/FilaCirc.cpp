#include "FilaCirc.h"

ColaCircular :: ColaCircular(int tam)
{
	min = 0;
	max = tam - 1;
	front = end = -1;
	words = new string[tam];
	for (int i = 0; i < tam; i++) words[i] = "-";
}
ColaCircular ::~ColaCircular()
{

}
int ColaCircular::Push(string nueva)
{
	if (front == min && end == max) //Cola llena
		return -1;
	if (end + 1 == front) //Cola circular llena
		return -1;
	end++;
	if (end > max) //Fin lleg� a m�ximo, regresa a inicio
		end = min;
	if (front == -1) //Solamente en la primer inserci�n
		front = end;
	words[end] = nueva;
	return 0;
}
string ColaCircular::Pull()
{
	string extraida;

	if (front < min) //Cola vac�a
		return "";
	extraida = words[front];
	words[front] = "-";

	if (front == end) //Se extrajo la �ltima palabra
	{
		front = end - 1;
		return extraida;
	}

	front++;
    if(front>max)
        front = min;
	if (front == max) //Inicio lleg� a max, se regresa a min
		front = min;

	return extraida
		;
}
void ColaCircular::Mostrar()
{
	cout << "\nPALABRAS: " << endl;
	for (int i = min; i <= max; i++)
	{
		cout << words[i];
		if (i == min) cout << "\t <-- Mínimo";
		if (i == max) cout << "\t <-- Máximo";
		if (i == front) cout << "\t <-- Inicio";
		if (i == end) cout << "\t <-- Final";
		cout << endl;
	}
	cout << endl;
}
