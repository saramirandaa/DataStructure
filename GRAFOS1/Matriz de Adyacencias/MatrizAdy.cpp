#include "MatrizAdy.h"

MatrizAdy::MatrizAdy(int tam)
{
	maxNodos = tam;
	ocupados = 0;
	Nodos = new char[tam];	// Arreglo de nodos
	Arcos = new int* [tam];	// Renglones de la matriz de arcos
	for (int i = 0; i < tam; i++)
		Arcos[i] = new int[tam];	// Columnas de la matriz de arcos
	for (int i = 0; i < tam; i++)	// Inicializando el arreglo de Nodos
		Nodos[i] = '=';
	for (int i = 0; i < tam; i++)	//Inicializando la matriz de arcos
	{
		for (int j = 0; j < tam; j++)
			Arcos[i][j] = -1;
	}

}
int MatrizAdy::InsertarNodo(char nuevo)
{
	if (ocupados == maxNodos)	// Arreglo de Nodos lleno. NO se insertó
		return -2;
	if (BuscarNodo(nuevo) != -1)	// Ya existe el nodo. NO se insertó
		return -1;

	Nodos[ocupados] = nuevo;	// OK. Se insertó el nodo
	ocupados++;
	return 0;
}
int MatrizAdy::InsertarArco(char ori, char des, int peso)
{
	if (ocupados == 0)	// Grafo vacío. No existen nodos de origen y destino. NO se insertó
		return -1;

	posiOri = BuscarNodo(ori);
	posiDes = BuscarNodo(des);

	if (posiOri == -1 || posiDes == -1)	// No existe el nodo de origen o el de destino. NO se insertó
		return -1;

	if (Arcos[posiOri][posiDes] != -1)	// Ya existe el arco. NO se insertó
		return -2;

	Arcos[posiOri][posiDes] = peso;	// OK. Se inserta el arco bidireccional
	Arcos[posiDes][posiOri] = peso;
	return 0;
}
void MatrizAdy::Mostrar()
{
	cout << " \nMATRIZ DE ADYACENCIAS:" << endl;
	if (ocupados == 0)
	{
		cout << "\n\tMatriz vacía" << endl;
		return;
	}
	cout << "\n\t";
	for (int i = 0; i < maxNodos; i++)
		cout << "\t" << Nodos[i];
	cout << endl;
	for (int i = 0; i < maxNodos; i++)
	{
		cout << "\t" << Nodos[i];
		for (int j = 0; j < maxNodos; j++)
		{
			if (Arcos[i][j] == -1)
				cout << "\t" << "-";
			else
				cout << "\t" << Arcos[i][j];
		}
		cout << endl;
	}
}
int MatrizAdy::BuscarNodo(char buscado)
{
	for (int i = 0; i < ocupados; i++)
	{
		if (buscado == Nodos[i])
			return i;
	}
	return -1;
}