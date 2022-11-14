#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

class listaorden
{
private:
    Node *node, *front, *end, *previous;
public:
    listaorden();
    ~listaorden();
    void pushF(int);
    void pushM(int);
    void pushE(int);
    int pullF();
    int pullM(int);
    int pullE();
    void sort();
    void display();
};



