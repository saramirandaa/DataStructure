#include "Binario.h"

Binario::Binario()
{
	raiz = NULL;
}
Binario::~Binario()
{}
void Binario::CrearNodo(int valor)
{
	nodo = new Numeros;
	nodo->num = valor;
	nodo->izq = NULL;
	nodo->der = NULL;
}
Numeros* Binario::getRaiz()
{
	return raiz;
}
void Binario::Insertar(Numeros* inicio)
{
	if (!raiz)		// Si el �rbol est� vac�o
	{
		raiz = nodo;
		cout << "\n\tSe inserto en la raiz" << endl;
		return;
	}
	if (nodo->num < inicio->num)   // Se insertar� a la izquierda
	{
		if (inicio->izq == NULL)
		{
			inicio->izq = nodo;
			cout << "\tSe insert� a la izquierda de "
				<< inicio->num;
			return;
		}
		else
		{
			Insertar(inicio->izq);
			return;
		}
	}
	if (nodo->num > inicio->num)   // Se insertar� a la derecha
	{
		if (inicio->der == NULL)
		{
			inicio->der = nodo;
			cout << "\tSe insert� a la derecha de "
				<< inicio->num;
			return;
		}
		else
		{
			Insertar(inicio->der);
			return;
		}
	}
	// Si ya existe el valor, NO se inserta
	cout << "\n\tYa existe el valor en el �rbol. NO se insert�" << endl;
	delete nodo;
}
void Binario::Recorrer_inorden(Numeros* inicio)
{
	if (!raiz)
	{
		cout << "\n\tÁrbol Vacío" << endl;
		return;
	}
	if (inicio->izq != NULL) Recorrer_inorden(inicio->izq);
	cout << "\t" << inicio->num;
	if (inicio->der != NULL) Recorrer_inorden(inicio->der);
}
void Binario::Recorrer_preorden(Numeros* inicio)
{
	if (!raiz)
	{
		cout << "\n\t�rbol Vac�o" << endl;
		return;
	}
	cout << "\t" << inicio->num;
	if (inicio->izq != NULL) Recorrer_preorden(inicio->izq);
	if (inicio->der != NULL) Recorrer_preorden(inicio->der);
}
void Binario::Recorrer_posorden(Numeros* inicio)
{
	if (!raiz)
	{
		cout << "\n\tÁrbol Vacío" << endl;
		return;
	}
	if (inicio->izq != NULL) Recorrer_posorden(inicio->izq);
	if (inicio->der != NULL) Recorrer_posorden(inicio->der);
	cout << "\t" << inicio->num;
}
Numeros* Binario::Buscar(Numeros* inicio, int buscado)
{
	Numeros* encontrado;
	if (!raiz)
	{
		cout << "\n\tÁrbol Vacío" << endl;
		return NULL;
	}
	if (buscado == inicio->num)
	{
		cout << "\tOK. Se encontró el " << buscado << endl;
		return inicio;
	}
	if (buscado < inicio->num)
	{
		if (inicio->izq != NULL)
		{
			encontrado = Buscar(inicio->izq, buscado);
			return encontrado;
		}
		else
		{
			cout << "\tNO existe " << buscado << endl;
			return NULL;
		}
	}
	if (buscado > inicio->num)
	{
		if (inicio->der != NULL)
			encontrado = Buscar(inicio->der, buscado);
		else
		{
			cout << "\tNO existe " << buscado << endl;
			return NULL;
		}
	}
}
