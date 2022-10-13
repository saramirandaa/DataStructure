#include "LinkedL.h"

LkList::LkList()
{
    head = end = node = NULL;
    cont = 0;
}
LkList::~LkList(){}

Node* LkList:: get(int position)
{
    node = head;
    for (int i = 0; i < position; i++)
        node = node->next;
    return node;
};
void LkList:: PushFront(int value)
{
    cont++;
    Node *newNode = new Node(); //crea un nuevo nodo
    newNode->data = value; //le asignamos el dato que queremos asignar
    newNode->next=NULL; //la memoria es cero
    newNode->next = head; //apunta a la cabeza
    head = newNode;

    if(end == NULL)
        end = node;

}
void LkList::PushBack(int value)
{
    if (head == NULL)
    {
        PushFront(value);
        return;
    }
    
    prev = get(cont-1);
    node = new Node;
    node->data = value;
    node->next = prev->next;
    prev->next = node;
    prev = prev->next;
    cont++;
}
void LkList::PushMid(int value, int pos)
{
    cont++;
    
    if((pos == 0)||(head==NULL))
    {
        cont--;
        PushFront(value);
        return;
    }
    if(pos>=cont)
    {
        cont--;
        PushBack(value);
        return;
    }
    prev = get(pos-1);
    node = new Node;
    node->data = value;
    node->next = prev->next;
    prev->next = node;
    if ((prev == end))
    {    
        cont--;
        PushBack(value);
    }
    return;
    prev = prev->next;
}

void LkList::display()
{
    node = head;
    while(node != NULL)
    {
        cout<<node->data<<endl;
        node = node->next;
    }
}