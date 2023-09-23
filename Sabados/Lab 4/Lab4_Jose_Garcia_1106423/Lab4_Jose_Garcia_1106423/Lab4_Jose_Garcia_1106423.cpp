#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// Función para generar un número aleatorio entre 1 y 10
int generarNumeroAleatorio() {
    return rand() % 10 + 1;
}

// Función para imprimir la carrera en una línea de 70 posiciones
void imprimirCarrera(const vector<int>& posicionestortuga, const vector<int> posicionesconejo) {
    for (int i = 1; i <= 70; i++) {
        bool tortugaPresente = false;
        bool liebrePresente = false;
        if (posicionestortuga[0] == i && posicionesconejo[0] == i)
        {
            cout << "(TH)";
            tortugaPresente = true;
            liebrePresente = true;
        }
        else
        {
            if (posicionestortuga[0] == i) {

                cout << 'T';  // Tortuga
                tortugaPresente = true;

            }
            if (posicionesconejo[0] == i) {
                cout << 'H';  // Liebre
                liebrePresente = true;
            }
        }

        if (!tortugaPresente && !liebrePresente) {
            cout << ' ';
        }
        else if (tortugaPresente && liebrePresente) {
            cout << "OUCH!";
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Inicializar la semilla del generador de números aleatorios

    vector<int> posicionTortuga(1, 1);  // Inicialmente, la tortuga está en la posición 1
    vector<int> posicionLiebre(1, 1);   // Inicialmente, la liebre está en la posición 1

    cout << "¡BANG!" << endl;
    cout << "¡Y ARRANCAN!" << endl;

    while (true) {
        int pasoTortuga = generarNumeroAleatorio();
        int pasoLiebre = generarNumeroAleatorio();

        // Movimiento de la tortuga
        if (pasoTortuga >= 1 && pasoTortuga <= 5) {
            posicionTortuga[0] += 3;  // Paso veloz
        }
        else if (pasoTortuga >= 6 && pasoTortuga <= 7) {
            posicionTortuga[0] -= 6;  // Resbalón
        }
        else {
            posicionTortuga[0] += 1;  // Paso lento
        }

        // Movimiento de la liebre
        if (pasoLiebre >= 1 && pasoLiebre <= 2) {
            posicionLiebre[0] += 0;  // Duerme (no se mueve)
        }
        else if (pasoLiebre >= 3 && pasoLiebre <= 4) {
            posicionLiebre[0] += 9;  // Salto grande
        }
        else if (pasoLiebre == 5) {
            posicionLiebre[0] -= 12;  // Resbalón grande
        }
        else {
            posicionLiebre[0] += 1;  // Salto pequeño
        }

        // Asegurar que las posiciones no sean menores que 1
        if (posicionTortuga[0] < 1) {
            posicionTortuga[0] = 1;
        }
        if (posicionLiebre[0] < 1) {
            posicionLiebre[0] = 1;
        }

        //Cuando la posicion de la liebre o el de la tortuga sea > 70 se guardara como 70
        if (posicionLiebre[0] > 70)
        {
            posicionLiebre[0] = 70;
        }
        if (posicionTortuga[0] > 70)
        {
            posicionTortuga[0] = 70;
        }


        imprimirCarrera(posicionTortuga,posicionLiebre);

        if (posicionTortuga[0] >= 70) {
            cout << "¡LA TORTUGA GANA! ¡BRAVO!" << endl;
            break;
        }
        else if (posicionLiebre[0] >= 70) {
            cout << "La liebre gana. Ni hablar." << endl;
            break;
        }
    }
}