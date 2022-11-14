#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Lista_Ordenada
{
public:
    Lista_Ordenada();
    ~Lista_Ordenada();
    Node* get(int position);
    void Push(int);
    //void PushMid(int, int);
    //void PushBack(int);
    void display();

    Node* end, *head, *node, *prev;
    int cont;
};