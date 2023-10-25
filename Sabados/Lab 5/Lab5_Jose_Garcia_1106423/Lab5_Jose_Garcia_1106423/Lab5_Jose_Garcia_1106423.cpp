// Lab5_Jose_Garcia_1106423.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

int main()
{
    string h = "hoñlaasdasd";
    int num = 4;
    int* ptr;	/* puntero a enteros */
    int* ptr2;	/* otro puntero */

        /* reserva hueco para 300 enteros */
    ptr = (int*)malloc(300 * sizeof(int));
    ptr[33] = 15;		/* trabaja con el área de memoria */


    ptr2 = ptr + 15;		/* asignación a otro puntero */

    /* finalmente, libera la zona de memoria */
    free(ptr);


}
