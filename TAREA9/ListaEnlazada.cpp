#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada()
{
    node = head = end = previous = NULL;
    n_nodes = 0;
}

ListaEnlazada::~ListaEnlazada(){}

void ListaEnlazada::InsertFront(int value)
{
    n_nodes++;
    node = new Node;
    node->val = value;
    node->next = NULL; //
    head = node;

    if(end==NULL)
        end = node;
    
}
void ListaEnlazada::InsertEnd(int value)
{
    if(head == NULL){   
        InsertFront(value);
        return;     
    }
    n_nodes++;
    node = new Node;
    node->val = value;
    node->next = NULL;
    end->next = node;
    end = node;
}
int ListaEnlazada::DeleteBeginning()
{
    int extracted;
    if(head == NULL)
        return 0;
    n_nodes--;
    node = head;
    extracted = node->val;
    head->next = node->next;
    delete node;
    return extracted;
}
int ListaEnlazada::DeleteEnd()
{
    int extracted;
    if (end==NULL)
        return 0;
    if (head == end)
    {
        extracted = DeleteBeginning();
        return extracted;
        
    }
    node = head;
    while(node!=end)
    {
        previous = node;
        node = node->next;
    }
    extracted = node->val;
    previous->next = NULL;
    end = previous;
    delete node;
    n_nodes--;
    return extracted;
}
int ListaEnlazada::DeleteMiddle(int val)
{
    int extracted;
    bool found = false;
    if (head == NULL)
        return 0;
    previous = NULL;
    node = head;
    while(node!=NULL)
    {
        if(node->val== val)
        {
            found = true;
            break;
        }
        previous = node;
        node = node->next;
    }
    if(found == false)
        return 0;
    extracted = node->val;
    previous->next = node->next;
    if(node == head) 
        head = node->next;
    if (node == end)
        end = previous; 
    delete node;
    n_nodes--;
    return extracted;
}
void ListaEnlazada::InsertMiddle(int val)
{
    if (!head)
    {
        //cout<<"Lista VACIA. Se inserta al inicio"<<endl;
        InsertFront(val);
        return;
    }
    previous = head;
    int pos = Order(val);
    while(previous != NULL)
    {
        if(previous->val == pos)
        {
            node = new Node;
            node->val = val;
            node->next = previous->next;
            previous->next = node;
            if (previous == end)
                end = node;
            return;
        }
        previous = previous->next;
    }
    //cout<<"\n No existe "<< pos << " se inserta al final"<<endl;
    InsertEnd(pos);
}
void ListaEnlazada::Display()
{
    cout<<endl;
    if (head == NULL)
    {
        cout<<"\n\tLista Vacia"<<endl;
        return;
    }
    node = head;
    while(node != NULL)
    {
        cout<<"\t"<<node->val;
        if(node == head) cout << "\t<-- INICIO";
        if(node == end) cout << "\t<-- FINAL";
        cout<<endl;
        node = node->next;
    }
}
int ListaEnlazada::Order(int value)
{
    int pos = 0;
    previous = head;
    while(previous != NULL)
    {
        if(previous->val >= value)
        {
            pos = previous->val;
        }
        else
        { 
            previous = previous->next;
            pos = previous->val;
        }
    }
    return pos;
}