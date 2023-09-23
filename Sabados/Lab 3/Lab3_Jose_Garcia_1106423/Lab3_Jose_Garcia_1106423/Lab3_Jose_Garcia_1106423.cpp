#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
void fib() {
    int n;
    cout << "ingrese el numero N" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
}

int factorial(int n) {
    if (n < 2) {
        return 1;
    }

    return factorial(n - 1) * n;
}

void fac() {
    int n;
    cout << "ingrese el numero N" << endl;
    cin >> n;
    cout << factorial(n);
}

int main()
{
    cout << "----------Ejercicio-----------" << endl;
    cout << "1. Ejercicio 1" << endl;
    cout << "2. Ejercicio 2" << endl;
    cout << "3. Ejercicio 3" << endl;
    int numero;
    cin >> numero;
    switch (numero)
    {
        case 1:
            fib();
        break;
        case 2:
            fac();
        break;
        default:
            cout << "No hay numero dentro de este rango";
        break;
    }

    

}

