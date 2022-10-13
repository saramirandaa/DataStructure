#include "ListA.h"

Lista_Ordenada::Lista_Ordenada()
{
    node = head = end = NULL;
}
Lista_Ordenada::~Lista_Ordenada(){}

Node* Lista_Ordenada::get(int position)
{
    node = head;
    for (int i = 0; i < position; i++)
        node = node->next;
    return node;
}

void Lista_Ordenada::Push(int value)
{
    cont++;
    Node *newNode = new Node(); 
    newNode->data = value; 
    if (head == NULL)
    {
        newNode->next=NULL; 
        newNode->next = head; 
        head = newNode;
        if(end == NULL)
            end = node;
        return;
    }
    for (int i = 0; i < cont; i++)
    {
        prev = get(i);
        if(prev->data<node->data)
        {
            node = new Node;
            node->data = value;
            node->next = prev->next;
            prev->next = node;
        }
        else
            break;
    }

    return;
    prev = prev->next;
}