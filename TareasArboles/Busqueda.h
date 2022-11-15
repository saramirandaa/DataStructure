#include <iostream>
using namespace std;

struct Numeros
{
	Numeros* izq;
	int num;
	Numeros* der;
};

class Binario
{
public:
	Binario();
	~Binario();
	void CrearNodo(int);
	Numeros* getRaiz();
	void Insertar(Numeros*);
	void Recorrer_inorden(Numeros*);
	void Recorrer_preorden(Numeros*);
	void Recorrer_posorden(Numeros*);
	Numeros* Buscar(Numeros*, int);
	
private:
	Numeros* raiz, * nodo;
};
