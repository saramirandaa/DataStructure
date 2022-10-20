#include "listaorden.h"

listaorden::listaorden()
{
    node = front = end = previous = NULL;
}
listaorden::~listaorden(){}

void listaorden::pushF(int value)
{
    node = new Node;
    node->value = value;
    node->next = front; 
    front = node;
}
void listaorden::pushM(int){}
void listaorden::pushE(int){}
int listaorden::pullF(){}
int listaorden::pullM(int){}
int listaorden::pullE(){}
void listaorden::display(){}
void listaorden::sort(){}
