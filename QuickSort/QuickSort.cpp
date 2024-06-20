/*
Jesus Alejandro Montes Aguila
27/05/2024
"Quick Sort"

Este código implementa el algoritmo de quicksort,
un enfoque de divide y conquista para ordenar arrays.
La función partition reordena los elementos del array
alrededor de un elemento pivote, y la función quickSort
llama a sí misma recursivamente para ordenar los subarrays.
La función main demuestra el uso del algoritmo de quicksort
con un array de ejemplo.
*/
#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    // Intercambia los valores de dos variables utilizando una variable temporal
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to find the partition position
int partition(int array[], int low, int high) {
    // Selecciona el elemento derecho como pivote
    int pivot = array[high];
    // Inicializa un puntero para elementos mayores que el pivote
    int i = low - 1;

    // Itera sobre el array desde low hasta high-1
    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual que el pivote
        if (array[j] <= pivot) {
            // Incrementa el puntero i y swaptea los elementos en i y j
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // Swaptea el elemento en i+1 con el pivote (elemento en high)
    swap(&array[i + 1], &array[high]);
    // Regresa la posición del pivote en el array ordenado
    return i + 1;
}

// Function to perform quicksort
void quickSort(int array[], int low, int high) {
    // Si el rango de elementos es válido (low < high)
    if (low < high) {
        // Encuentra la posición del pivote en el array ordenado
        int pi = partition(array, low, high);

        // Llama a quickSort recursivamente para los subarrays
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    // Array de ejemplo a ordenar
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    // Tamaño del array
    int size = sizeof(data) / sizeof(data[0]);

    // Imprime el array original
    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Llama a quickSort para ordenar el array
    quickSort(data, 0, size - 1);

    // Imprime el array ordenado
    cout << "Sorted Array in Ascending Order: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
