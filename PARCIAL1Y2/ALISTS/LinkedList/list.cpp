#include "list.h"

List::List()
{
    front = end = node = NULL;
}
List::~List(){}

void List::addF(int add)
{
    node = new Node;
    node->data = add;
    node->next = front;
    front = node;

    if(end == NULL)
        end = node;
}

void List::addB(int add)
{
    if (!front)
    {
        addF(add);
        return;
    }
    node = new Node;
    node->data = add;
    node->next = NULL;
    end->next = node;
    end = node;
}
void List::addM(int add, int after)
{
    Node * nodoAnter;
    if (!front)
    {
        cout<<"Lista VACIA. Se inserta al inicio"<<endl;
        addF(add);
        return;
    }
    /* Paso 1: Localizar la posición */
    nodoAnter = front;
    
    while(nodoAnter)
    {
        if(nodoAnter->data == after)
        {
            /* Paso 2: Crear nuevo nodo */
            node = new Node;
            /* Paso 3: Llenar campo de datos */
            node->data = add;
            /* Paso 4: Llenar campo de enlace */
            node->next = nodoAnter->next;
            /* Paso 5: Cambiar enlace de nodo anterior */
            nodoAnter->next = node;
            if (nodoAnter == end)
                end = node;
            return;
        }
        nodoAnter = nodoAnter->next;
    }
    cout<<"\n No existe "<< after << " se inserta al final"<<endl;
    addB(add);
}

int List::delF()
{
    int extracted;

    if(front == NULL) //if (!cabecera)
        return -1;
    // Paso 1: Localizar primer nodo 
    node = front;
    // Paso 2: Tomar y devolver la información a extraer
    extracted = node ->data;
    // Paso 3 Apuntar a cabecera al nodo siguiente
    front = node->next;
    // Paso 4: Liberar el nodo extraido
    delete node;

    return extracted;

}

int List::delB()
{
    int extracted;
    Node * prev;
    if(front == NULL)
        return -1;
    if(end == front) //Caso en que solo hay un nodo en la lista
    {
        extracted = delF();
        return extracted;
    }

    prev = NULL;
    node = front;

    while(node != end)
    {
        prev = node;
        node = node->next;
    }

    //Paso 2: Tomar y devolver informacion a extraer
    extracted = node->data;
    //Paso 3: Apunta a NULL el enlace de nodo anterior
    prev->next = NULL;
    //Apuntar Final a nodo anterior
    end = prev;
    //Paso 5: Liberar el nodo extraido
    delete node;

    return extracted;

}

int List::delM(int del)
{
    int extraida;
    Node * nodoAnter;
    bool encontrado = false;
    if(front == NULL)
        return -1;
    nodoAnter = NULL;
    node = front;
    
    while(node!=NULL)
    {
        if(node->data==del)
        {
            encontrado = true;
            break;
        }
        nodoAnter = node;
        node = node->next;

    }
    //Paso 2: Tomar y devolcer la informacion extraida
    if(!encontrado)
        return -1;
    extraida = node->data;
    //Paso 3: Apuntar enlace de nodo anterior al nodo siguiente al extraido
    nodoAnter->next = node->next;

    if(node == front) //Caso en que el nodo extraido es el primero
        front = node->next;
    if (node == end)
        end = nodoAnter; // Caso en el que el nodo extraido es el final
    
    delete node;
    return extraida;
}

void List::print()
{
    cout<<endl;
    if (front == NULL)
    {
        cout<<"\n\tLista Vacia"<<endl;
        return;
    }
    node = front;
    while(node != NULL)
    {
        cout<<"\t"<<node->data;
        if(node == front) cout << "\t<-- INICIO";
        if(node == end) cout << "\t<-- FINAL";
        cout<<endl;
        node = node->next;
    }
}