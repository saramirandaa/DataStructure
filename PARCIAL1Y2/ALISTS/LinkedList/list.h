#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
public: 
    List();
    ~List();
    void addF(int);
    void addM(int, int);
    void addB(int);

    int delF();
    int delM(int);
    int delB();

    void print();
private:
    Node *front, *end, *node;

};