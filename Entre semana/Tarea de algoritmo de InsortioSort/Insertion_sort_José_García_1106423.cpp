#include <iostream>

using namespace std;

string insertionSort( string letras, int n) {
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		char aux = letras[i];

		while (j >= 0 && letras[j] > aux)
		{
			letras[j + 1] = letras[j];
			--j;
		}

		letras[j + 1] = aux;
	}
	return letras;
}

int main()
{
	//José Andrés García Elías 1106423
	string letras = "anbgbajs";

	cout << insertionSort(letras, letras.length());
}
