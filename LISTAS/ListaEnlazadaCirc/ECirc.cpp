#include "ECirc.h"

ECirc::ECirc()
{
    setlocale(LC_ALL, "");
	head = end = checked = previous = NULL;
	node = NULL;
}

ECirc::~ECirc(){}

void ECirc::InsertB(string value)
{
    node = new Node;
    node->data = value; //creo un nuevo nod y le asigno unu valor
    if (head == NULL) //si esta vacia le asigno el valor de mi nuevo nodo a head y a end
    {
        head = node;
        end = node;
        checked = node;
    }
    
    node->next = head; //pointers 
    end = node->next;
    head = node;
    checked = node;
}


void ECirc::InsertE(string value)
{
    if(end == NULL)
    {   
        InsertB(value);
        return;
    }
    node = new Node;
    node->data = value;
    end->next = node;
    node->next = head;
    end = node;
}

bool ECirc::InsertM(string after, string value)
{
    bool found;
    if(end == NULL)
    {
        InsertB(value);
        return true;
    }
    found = Search(after);
    if(found == false)
    {
        InsertE(value);
        return false;
    }
    node = new Node;
    node->data = value;
    node->next = checked->next;
    checked->next = node;

    if(checked == end)
        end = node;
    return true;
}

string ECirc::ExtractI()
{
    string extracted = "";
	if (head == NULL)
		return "";
	node = head;
	extracted = node->data;
	if (checked == head)
		checked = head->next;
	if (end == head)
		head = end = NULL;
	else
	{
		head = node->next;
		end->next = node->next;
	}

	delete node;
	return extracted;   
}
string ECirc::ExtractE()
{
   string extracted = "";
    if(head == NULL)
        return "";
    node = checked;

    while (node->next != end)
		node = node->next;
    if (checked == end)
		checked = head;
	end = node;
	node = node->next;
	extracted = node->data;
	end->next = head;
	delete node;
	return extracted;
}
string ECirc::ExtractM(string toExtract)
{
    bool found;
	string extracted;

	if (!head)
		return "";

	found = Search(toExtract);

	if (!found)
		return "";
	if (node == head)
	{
		extracted = ExtractI();
		return extracted;
	}
	if (checked == node)
		checked = head;
	if (end == node)
		end = previous;

	extracted = node->data;

	previous->next = node->next;
	checked = previous->next;
	delete node;
	return extracted;
}
bool ECirc::Search(string find)
{
    if (!head)
		return false;
	if (checked == NULL)
	{
		checked = head;
		previous = end;
	}
	node = checked;
	do
	{
		if (node->data == find)
		{
			checked = node;
			return true;
		}
		else
		{
			previous = node;
			node = node->next;
		}
	} while (node != checked);
	return false;
}


void ECirc::Show()
{
    int n_node = 0;
    if (!head)
	{
		cout << "\n\t *** Lista VACÍA ***" << endl;
		return;
	}
	node = head;
	cout << "\nLISTA:" << endl;
	do
	{
        n_node++;
		cout << "\t" << n_node <<". " << node->data;
		if (node == head)
			cout << "\t<-- Cabecera";
		if (node == end)
			cout << "\t<-- Final";
		cout << endl;
		node = node->next;
	} while (node != head);
}

void ECirc::Odds()
{
    int n_node = 0, var;
    if (!head)
	{
		cout << "\n\t *** Lista VACÍA ***" << endl;
		return;
	}
	node = head;
	do
	{
        n_node++;
		var = n_node%2; 
        if(var!=0)
            ExtractM(node->data);
		node = node->next;
	} while (node != head);
}