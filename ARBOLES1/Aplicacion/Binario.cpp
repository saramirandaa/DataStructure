#include "Binario.h"

Binario::Binario()
{
	setlocale(LC_ALL, "");
	raiz = NULL;
}
Binario::~Binario()
{}
void Binario::CrearNodo(int id, string nombre)
{
	nodo = new Proveedor;
	nodo->id = id;
	nodo->nombre = nombre;
	nodo->izq = NULL;
	nodo->der = NULL;
}
Proveedor* Binario::getRaiz()
{
	return raiz;
}
void Binario::Insertar(Proveedor* inicio)
{
	if (!raiz)		// Si el �rbol est� vac�o
	{
		raiz = nodo;
		cout << "\n\tSe inserto en la raiz" << endl;
		return;
	}
	if (nodo->id < inicio->id)   // Se insertar� a la izquierda
	{
		if (inicio->izq == NULL)
		{
			inicio->izq = nodo;
			cout << "\tSe insert� a la izquierda de "
				<< inicio->id;
			return;
		}
		else
		{
			Insertar(inicio->izq);
			return;
		}
	}
	if (nodo->id > inicio->id)   // Se insertar� a la derecha
	{
		if (inicio->der == NULL)
		{
			inicio->der = nodo;
			cout << "\tSe insert� a la derecha de "
				<< inicio->id;
			return;
		}
		else
		{
			Insertar(inicio->der);
			return;
		}
	}
	// Si ya existe el proveedor, NO se inserta
	cout << "\n\tYa existe el proveedor en el �rbol. NO se insert�" << endl;
	delete nodo;
}
void Binario::Recorrer_inorden(Proveedor* inicio)
{
	if (!raiz)
	{
		cout << "\n\t�rbol Vac�o" << endl;
		return;
	}
	if (inicio == raiz)
		cout << "\nCat�logo de Proveedores:" << endl;
	if (inicio->izq != NULL) Recorrer_inorden(inicio->izq);
	cout << "\t" << inicio->id << "\t" << inicio->nombre << endl;;
	if (inicio->der != NULL) Recorrer_inorden(inicio->der);
}

Proveedor* Binario::Consultar(Proveedor* inicio, int provConsultado)
{
	Proveedor* encontrado;
	if (!raiz)
	{
		cout << "\n\t�rbol Vac�o" << endl;
		return NULL;
	}
	if (provConsultado == inicio->id)	// Se encontr� el proveedor
	{
		return inicio;
	}
	if (provConsultado < inicio->id)	// Se busca a la izquierda
	{
		if (inicio->izq != NULL)
		{
			encontrado = Consultar(inicio->izq, provConsultado);
			return encontrado;
		}
		else               // No existe el proveedor consultado
		{
			return NULL;
		}
	}
	if (provConsultado > inicio->id)	// Se busca a la derecha
	{
		if (inicio->der != NULL)
		{
			encontrado = Consultar(inicio->der, provConsultado);
			return encontrado;
		}
		else               // No existe el proveedor consultado
		{
			return NULL;
		}
	}
}
