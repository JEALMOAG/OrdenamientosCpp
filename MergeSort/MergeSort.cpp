/*
Jesus Alejandro Montes Aguila
28/05/2024
"Merge sort"

Este c�digo define un algoritmo de ordenamiento por fusi�n en C++.
La funci�n merge fusiona dos subarreglos ordenados, y la funci�n
mergeSort llama recursivamente a s� misma para ordenar los subarreglos.
La funci�n main demuestra el uso del algoritmo de ordenamiento por
fusi�n con un arreglo de ejemplo.
*/
#include <iostream>
using namespace std;

// Funci�n que fusiona dos subarreglos de array[].
// El primer subarreglo es arr[left..mid]
// El segundo subarreglo es arr[mid+1..right]
void merge(int array[], int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Crear arreglos temporales
    int L[subArrayOne], R[subArrayTwo];

    // Copiar datos a arreglos temporales L[] y R[]
    for (int i = 0; i < subArrayOne; i++)
        L[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Fusionar los arreglos temporales de vuelta en array[left..right]
    while (i < subArrayOne && j < subArrayTwo) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < subArrayOne) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < subArrayTwo) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// begin es para el �ndice izquierdo y end es para el �ndice derecho
// del subarreglo de arr que se va a ordenar
void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    // Ordenar las primeras y segundas mitades
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);

    // Fusionar las mitades ordenadas
    merge(array, begin, mid, end);
}

// Funci�n para imprimir un arreglo
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

// C�digo principal
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original es \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nArreglo ordenado es \n";
    printArray(arr, arr_size);

    return 0;
}
