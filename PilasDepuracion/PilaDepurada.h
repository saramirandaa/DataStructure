#pragma once
#include <iostream>
using namespace std;
#define TAM 10

class PilaDepurada
{
public:
    PilaDepurada();
    ~PilaDepurada();
    int Push(int);
    int Pop();
    int Pull();
    int Depuration(int);
    int Top();
    void Show();


private:
    int top, max, min;
    int* pila;
};