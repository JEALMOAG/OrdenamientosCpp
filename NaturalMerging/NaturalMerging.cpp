/*
Jesus Alejandro Montes Aguila
31/05/2024
"Natural Mergnig"

Este c�digo utiliza el algoritmo de Natural Merging para ordenar un
arreglo de enteros. La funci�n merge fusiona dos subarreglos, y la
funci�n naturalMerging llama a merge repetidamente para fusionar subarreglos
 de tama�os cada vez m�s grandes hasta que el arreglo est� ordenado.

La funci�n findRunEnd encuentra el final de una secuencia ordenada,
y la funci�n naturalMerging utiliza esta funci�n para fusionar secuencias ordenadas adyacentes.

La funci�n printArray imprime el arreglo original y el arreglo ordenado.
*/
#include <iostream>
using namespace std;

// Prototipos de funciones
void merge(int arr[], int left, int mid, int right);
void naturalMerging(int arr[], int n);
int findRunEnd(int arr[], int left, int right);
void printArray(int arr[], int n);

// Funci�n para fusionar dos subarreglos
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funci�n para realizar el Natural Merging
void naturalMerging(int arr[], int n) {
    int width = 1;

    while (width < n) {
        int left = 0;

        while (left < n) {
            int mid = findRunEnd(arr, left, min(left + width, n - 1));
            int right = findRunEnd(arr, mid + 1, min(mid + 1 + width, n - 1));

            merge(arr, left, mid, right);

            left = right + 1;
        }

        width *= 2;
    }
}

// Funci�n para encontrar el final de una secuencia ordenada
int findRunEnd(int arr[], int left, int right) {
    while (left < right && arr[left] <= arr[left + 1])
        left++;

    return left;
}

// Funci�n para imprimir el arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: ";
    printArray(arr, n);

    naturalMerging(arr, n);

    cout << "Arreglo ordenado: ";
    printArray(arr, n);

    return 0;
}

