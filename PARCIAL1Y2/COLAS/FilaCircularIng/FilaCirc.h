#pragma once
#include <iostream>
using namespace std;

class ColaCircular
{
public:
    ColaCircular(int);
    ~ColaCircular();  
    int Push(string);
    string Pull();
    void Mostrar();
private:
    int min, max, front, end;
    string* words;
};