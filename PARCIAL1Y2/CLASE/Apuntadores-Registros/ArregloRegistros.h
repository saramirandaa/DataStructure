#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Empleado
{
	int anti;
	string nom;
	int* piezas;
};

class ArregloRegistros
{
public:
	ArregloRegistros(int tam);
	~ArregloRegistros();

	void Agregar();
	void Mostrar();
	void Ordenar();
private:
	Empleado* lista;
	int tamano;
	int ocupados;
};

