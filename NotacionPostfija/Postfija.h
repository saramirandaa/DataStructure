#include <iostream>
using namespace std;

#pragma once
#include <iostream>
using namespace std;
#define TAM 10

class Postfija
{
public:
    Postfija();
    ~Postfija();
    int Push(string);
    string Pop();
    string Pull();
    int Top();
    void Show();


private:
    int top, max, min;
    string* pila;
};