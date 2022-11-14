#include "ListaAdy.h" 

ListaAdy::ListaAdy()
{
	inicio = NULL;
	totalNodos = 0;
	topePila = -1;
	inicioCola = -1;
	finCola = -1;
}

ListaAdy::~ListaAdy()
{
}

int ListaAdy::InsertarNodo(char nom)
{
	Nod* posic = NULL;
	int existe;

	nodo = new Nod;				// Crea nuevo nodo e inicia sus campos
	nodo->nombre = nom;
	nodo->nodSig = NULL;
	nodo->adySig = NULL;

	if (!inicio)				// Inserta nodo, si la lista de nodos está vacía
	{
		inicio = nodo;
		totalNodos++;
		return 0;
	}

	existe = LocalizarNod(nom, posic);	// Localiza dirección del nodo "nom", o bien, si no existe "nom", el nodo final de la lista

	if (existe == 0)				// No existe el nodo "nom" y lo inserta al final de la lista de nodos
	{
		posic->nodSig = nodo;
		totalNodos++;
		return 0;
	}
	else						// YA existe el nodo "nom" y NO lo inserta
	{
		delete nodo;
		return -1;
	}
}
int ListaAdy::InsertarArco(char ori, char des, int peso)
{
	Nod* posicOri = NULL, * posicDes = NULL;
	Ady* posicAdy = NULL;
	int existeOri, existeDes, existeArco;

	adyad = new Ady;			// Crea nuevo arco e inicia sus campos
	adyad->nombre = des;
	adyad->peso = peso;
	adyad->adySig = NULL;

	if (!inicio)
		return -1;				// Lista Vacía, NO se insertó el arco

	existeOri = LocalizarNod(ori, posicOri);	// Revisa si existe nodo "ori" y su dirección
	existeDes = LocalizarNod(des, posicDes);	// Revisa si existe nodo "des"

	if (existeOri == 0 || existeDes == 0)
	{
		delete adyad;
		return -1;				// No existe nodo origen o nodo destino, NO se inserta arco
	}

	if (!posicOri->adySig)		// Inserta arco, si la lista de adyacencias desde "ori" está vacía
	{
		posicOri->adySig = adyad;
		adyad->dirNodo = posicDes;
		return 0;
	}

	existeArco = LocalizarAdy(posicOri, des, posicAdy);	// Desde nodo "ori" localiza dirección de adyacencia "des" o adyacencia final de la lista
	if (existeArco == -1)
	{
		delete adyad;
		return -2;				// YA existe el arco, NO se insertó
	}
	posicAdy->adySig = adyad;	// No existe el arco y lo inserta al final de la lista de adyacencias desde "ori"
	adyad->dirNodo = posicDes;

	return 0;
}
int ListaAdy::LocalizarNod(char nom, Nod*& posic)
{
	auxNod = inicio;
	do
	{
		posic = auxNod;
		if (auxNod->nombre == nom)
			return -1;			// YA existe el nodo "nom"
		auxNod = auxNod->nodSig;
	} while (auxNod);

	return 0;					// NO existe el nodo "nom"
}
int ListaAdy::LocalizarAdy(Nod* orig, char des, Ady*& posicAdy)
{
	auxAdy = orig->adySig;
	do
	{
		posicAdy = auxAdy;
		if (auxAdy->nombre == des)
			return -1;			// YA existe el arco
		auxAdy = auxAdy->adySig;
	} while (auxAdy);

	return 0;					// NO existe el arco
}
void ListaAdy::Mostrar()
{
	if (!inicio)
	{
		cout << "\tGrafo VACIO" << endl << endl;
		return;
	}

	cout << "\nLISTA DE NODOS:" << endl;
	cout << "\t";

	auxNod = inicio;
	do
	{
		cout << auxNod->nombre;
		auxNod = auxNod->nodSig;
		cout << " -> ";
	} while (auxNod);
	cout << "null" << endl;

	cout << "\nLISTA DE ADYACENCIAS:" << endl;

	auxNod = inicio;
	do
	{
		cout << "\t" << auxNod->nombre << " => ";
		auxAdy = auxNod->adySig;
		while (auxAdy)
		{
			cout << auxAdy->nombre << "-" << auxAdy->peso << " -> ";
			auxAdy = auxAdy->adySig;
		}
		cout << "null" << endl;
		auxNod = auxNod->nodSig;
	} while (auxNod);
	cout << endl;
}
void ListaAdy::RecorrerProfundidad()
{
	pila = new Nod * [totalNodos];
	visitados = new Nod * [totalNodos];
	Nod* extraido;
	Ady* arco;
	int contaVisitados = -1;
	int yaVisitado = 0, yaEnPila = 0;

	if (!inicio)
	{
		cout << "\tGrafo VACIO" << endl << endl;
		return;
	}
	InsertarPila(inicio);
	extraido = ExtraerPila();
	do
	{
		cout << "\t" << extraido->nombre << endl;
		contaVisitados++;
		visitados[contaVisitados] = extraido;
		arco = extraido->adySig;
		while (arco)
		{
			yaVisitado = 0;
			for (int i = 0; i <= contaVisitados; i++)
			{
				if (arco->dirNodo == visitados[i])
					yaVisitado = 1;
			}
			yaEnPila = 0;
			for (int i = 0; i <= topePila; i++)
			{
				if (arco->dirNodo == pila[i])
					yaEnPila = 1;
			}
			if (yaVisitado == 0 && yaEnPila == 0)
				InsertarPila(arco->dirNodo);
			arco = arco->adySig;
		}
		extraido = ExtraerPila();
	} while (extraido);
}
void ListaAdy::RecorrerAncho()
{
	cola = new Nod * [totalNodos];
	visitados = new Nod * [totalNodos];
	Nod* extraido;
	Ady* arco;
	int contaVisitados = -1;
	int yaVisitado = 0, yaEnCola = 0;

	if (!inicio)
	{
		cout << "\tGrafo VACIO" << endl << endl;
		return;
	}
	InsertarCola(inicio);
	extraido = ExtraerCola();
	do
	{
		cout << "\t" << extraido->nombre << endl;
		contaVisitados++;
		visitados[contaVisitados] = extraido;
		arco = extraido->adySig;
		while (arco)
		{
			yaVisitado = 0;
			for (int i = 0; i <= contaVisitados; i++)
			{
				if (arco->dirNodo == visitados[i])
					yaVisitado = 1;
			}
			yaEnCola = 0;
			for (int i = inicioCola; i <= finCola; i++)
			{
				if (arco->dirNodo == cola[i])
					yaEnCola = 1;
			}
			if (yaVisitado == 0 && yaEnCola == 0)
				InsertarCola(arco->dirNodo);
			arco = arco->adySig;
		}
		extraido = ExtraerCola();
	} while (extraido);
}
void ListaAdy::InsertarPila(Nod* noddo)
{
	topePila++;
	pila[topePila] = noddo;
}
Nod* ListaAdy::ExtraerPila()
{
	if (topePila == -1)
		return NULL;
	topePila--;
	return pila[topePila + 1];
}
void ListaAdy::InsertarCola(Nod* noddo)
{
	if (inicioCola == -1)
		inicioCola++;
	finCola++;
	cola[finCola] = noddo;
}
Nod* ListaAdy::ExtraerCola()
{
	if (inicioCola == -1)
		return NULL;
	if (inicioCola > finCola)
		return NULL;
	inicioCola++;
	return cola[inicioCola - 1];
}