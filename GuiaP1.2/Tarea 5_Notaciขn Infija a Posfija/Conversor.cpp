#include "Conversor.h"



Conversor::Conversor()
{
	(opera + 0)->operador = '+'; (opera + 1)->operador = '-'; (opera + 2)->operador = '*';
	(opera + 3)->operador = '/'; (opera + 4)->operador = '^'; (opera + 5)->operador = '(';
	(opera + 0)->preced = 1;     (opera + 1)->preced = 1;     (opera + 2)->preced = 2;
	(opera + 3)->preced = 2;     (opera + 4)->preced = 3;     (opera + 5)->preced = 0;

	min = 0;
	max = 39;
	tope = -1;
}

string Conversor::Convertir(string infija)
{
	string posfija;
	int i = -1, p = -1;
	char* inf, * pos;
	inf = new char[infija.length() + 1];
	pos = new char[infija.length() + 1];
	char sig, extraido;
	int precedEntra, precedPila;

	for (int i = 0; i < infija.length(); i++)
		inf[i] = infija[i];

	do
	{
		i++;
		sig = *(inf + i);
		if (sig == '+' || sig == '-' || sig == '*' || sig == '/' || sig == '^' || sig == '(' || sig == ')')
			sig = '_';

		switch (sig)
		{
		case ' ':
			break;
		case '_':
			if (Vacia())			// Regla 3.1 Si pila vacia, insertar
			{
				Insertar(*(inf + i));
				break;
			}
			if (*(inf + i) == '(')	// Regla 1. Si (, Insertar
			{
				Insertar(*(inf + i));
				break;
			}
			if (*(inf + i) == ')')  // Regla 2. Extraer hasta encontrar (
			{
				do
				{
					extraido = Extraer();
					if (extraido != '(')
					{
						p++;
						*(pos + p) = extraido;
					}
				} while (extraido != '(');
				break;
			}

			do         // Ciclo para extraer mayor precedencia de la pila
			{
				for (int k = 0; k < 6; k++)
				{
					if ((opera + k)->operador == *(inf + i))
						precedEntra = (opera + k)->preced;
					if ((opera + k)->operador == *(pila + tope))
						precedPila = (opera + k)->preced;
				}
				if (precedEntra > precedPila)  // Regla 3.2 Si preced Entra > preced Pila, inserta
				{
					break;	// cierra el ciclo Do e INSERTA en la pila
				}
				else            // Regla 3.3 Si preced Entra < preced Pila, extrae y luego inserta
				{
					extraido = Extraer();
					p++;
					*(pos + p) = extraido;
				}
			} while (precedEntra <= precedPila && !Vacia());

			Insertar(*(inf + i));	// INSERTA en la pila, cuando es de mayor precedencia
			break;
		default:
			p++;
			*(pos + p) = *(inf + i);
			break;
		}

	} while (i < (infija.length() - 1));

	while (!Vacia())
	{
		extraido = Extraer();
		p++;
		*(pos + p) = extraido;
	}
	p++;
	*(pos + p) = '\0';
	posfija = pos;
	return posfija;
}
int Conversor::Insertar(char op)
{
	if (Llena())
	{
		cout << "**Pila llena. Conversion inconclusa" << endl;
		return -1;
	}
	tope++;
	*(pila + tope) = op;
	return 0;
}
char Conversor::Extraer()
{
	char extraido;
	if (Vacia())
	{
		cout << "**Pila vacia. Conversion inconclusa" << endl;
		return '#';
	}
	extraido = *(pila + tope);
	tope--;
	return extraido;
}
bool Conversor::Llena()
{
	if (tope == max)
		return true;
	return false;
}
bool Conversor::Vacia()
{
	if (tope < min)
		return true;
	return false;
}
