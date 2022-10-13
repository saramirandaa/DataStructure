/*
Construye una aplicación con C++ que genere una lista circular de nombres y:
a)   Inserte tantos nombres como el usuario quiera X
b)   Informe cuantos nodos tiene X
c)    Extraiga e informe los nodos impares, reiteradamente, hasta que quede vacía 
d)   Opción para mostrar la lista completa en cualquier momento
*/

#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node* next;
};

class ECirc
{
private:
    Node * node, *previous, *head, *checked, *end;
public:
    ECirc(/* args */);
    ~ECirc();
    void InsertB(string);
    void Show();
	void InsertE(string);
	bool InsertM(string, string);
	string ExtractI();
	string ExtractE();
	string ExtractM(string);
	bool Search(string);
    void Odds();
};



