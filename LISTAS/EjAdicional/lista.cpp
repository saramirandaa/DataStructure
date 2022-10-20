#include "lista.h"

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
    node->next = head; 
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
   int extraido = 0;

	if (!head)
	{
		cout << "\n\t**Lista VACIA. NO se extrae" << endl << endl;
		return extraido;
	}

	node = head;	// Paso 1
	extraido = node->val;	// Paso 2
	head = node->next;	// Paso 3
	delete node;	// Paso 4
	return extraido;
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
    bool encontrado = false;
	Node * actual, *anterior;

	node = new Node;
	node->val = val;

	if (!head)
	{
		node->next = NULL;
		head = node;
		end = node;
		return;
	}
	anterior = NULL;
	actual = head;
	while (actual)
	{
		if (val < actual->val)
		{
			encontrado = true;
			break;
		}
		anterior = actual;
		actual = actual->next;
	}
	if (!encontrado)
	{
		node->next = NULL;
		end->next = node;
		end = node;
		return;
	}
	if (!anterior)
	{
		node->next = head;
		head = node;
		cout << "\tOK. Se insert� " << val << " al inicio " << endl;
	}
	else
	{
		node->next = anterior->next;
		anterior->next = node;	 // Paso 5
		cout << "\tOK. Se insert� " << val << " despu�s de " << anterior->val << endl;
	}

	return;
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
