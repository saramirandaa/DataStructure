#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LkList
{
public:
    LkList();
    ~LkList();
    Node* get(int position);
    void PushFront(int);
    void PushMid(int, int);
    void PushBack(int);
    void display();

    Node* end, *head, *node, *prev;
    int cont;
};