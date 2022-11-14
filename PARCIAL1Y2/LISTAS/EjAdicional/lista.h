#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

class ListaEnlazada
{
private:
    Node* node, *head, *end, *previous;
    void InsertFront(int);
    void InsertEnd(int);
	int DeleteEnd();
    int DeleteMiddle(int);
    int Order(int);
public:
    ListaEnlazada();
    ~ListaEnlazada();
    void InsertMiddle(int);
    int DeleteBeginning();
    void Display();
    int n_nodes;
};

