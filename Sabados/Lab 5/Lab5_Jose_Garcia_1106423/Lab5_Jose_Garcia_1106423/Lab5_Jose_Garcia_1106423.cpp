// Lab5_Jose_Garcia_1106423.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

int main()
{
    int* ptr;	/* puntero a enteros */
    int* ptr2;	/* otro puntero */

        /* reserva hueco para 300 enteros */
    ptr = (int*)malloc(300 * sizeof(int));
    ptr[33] = 15;		/* trabaja con el área de memoria */


    ptr2 = ptr + 15;		/* asignación a otro puntero */

    /* finalmente, libera la zona de memoria */
    free(ptr);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
