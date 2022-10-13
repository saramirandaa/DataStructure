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
    int DeleteBeginning();
    int DeleteEnd();
    int Order(int);
public:
    ListaEnlazada();
    ~ListaEnlazada();
    int DeleteMiddle(int);
    void InsertMiddle(int);
    void Display();
    int n_nodes;
};

