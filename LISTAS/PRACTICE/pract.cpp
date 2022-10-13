#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

Node * head;
Node *get(int pos){
    Node* current = head; //creamos un nodo que tiene los datos de head
    for(int i=0; i<pos; i++) //ciclo que nos lleva a la direcion de memoria en la que estamos
        current = current->next;
    return current;
} //nos regresa la posicion en memoria en la que se encuentra

void insert(int pos, int value)
{
    Node *newNode = new Node(); //crea un nuevo nodo
    newNode->value = value; //le asignamos el dato que queremos asignar
    newNode->next=NULL; //la memoria es cero
    if(pos==0) //si lo queremos al principio
    {
        newNode->next = head; //apunta a la cabeza
        head = newNode;
    }
    else{
        Node *prev = get(pos-1); //nos da la posicion del nodo anterior
        Node *curr = prev->next; //le damos la direccion del nodo anterior
        newNode->next = curr;
        prev->next = newNode;
    }
}

void erase(int pos)
{
    Node *toDelete;
    if (pos == 0)
    {
        toDelete = head; //se posiciona en la cabeza
        head = toDelete->next; //le da la posicion de memoria siguiente
        delete toDelete; //libera la memoria de este nodo
    }
    else
    {
        Node *prev = get(pos-1);
        toDelete = prev->next;
        delete toDelete;
    }
    
}
void destroy()
{
    Node *current = head;
    Node *prev;
    while (!current)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
    
}
void display()
{
    Node *current = head;
    while (current != NULL)
    {
        cout<<"Address: "<<current<<", Value: "<<current->value<<", Value next: "<<current->next<<endl;
        current = current->next;
    }
    
}

int main()
{
    head = 0;
    insert(0,1);
    insert(1,2);
    insert(2,3);
    insert(3,4);
    insert(4,5);
    display();
    cout<<endl;

    erase(0);
    erase(1);
    erase(2);
    display(); 
    destroy();
    
}