#include <iostream>
#include <string>
#include <cmath>

struct poligonos
{
	int largo;

	double Area(int largo, int lados)
	{
		double area;
		double apotema = largo / (2 * tan(3.14 / lados));
		area = 0.5 * lados * largo * apotema;
		return area;
	}
	double perimetro(int lados, int largo)
	{
		double perimetro = lados * largo;
		return perimetro;
	}
};

using namespace::std;

int main()
{
	poligonos figura;
	int numero;

	cout << "�Que figura desea sacar per�metro y �rea? \n" << endl;
	cout << "1. Triangulo (3 lados)" << endl;
	cout << "2. Cuadricula (4 lados)" << endl;
	cout << "3. Pentagono (5 lados)" << endl;
	cout << "4. Hexagono (6 lados)" << endl;
	cout << "5. Heptagono (7 lados)" << endl;
	cout << "6. Octagono (8 lados)" << endl;
	cout << "7. Eneagono (9 lados)" << endl;
	cout << "8. Decagono (10 lados)" << endl;

	cin >> numero;
	if (numero >= 10 || numero <= 1)
	{
		int lado = numero + 2;
		cout << "�Cuando medira el lado?" << endl;
		cin >> figura.largo;
		cout << "El �rea es: " << figura.Area(figura.largo, lado) << "\n";
		cout << "El perimetro es: " << figura.perimetro(figura.largo, lado);
	}
	else
	{
		cout << "Este n�mero no esta dentro del rango de la lista";
	}
	
}