/*
Jesus Alejandro Montes Aguila
25/05/2024
"Intercambio Sort"

Este algoritmo de ordenamiento de intercambio (tambi�n conocido como Bubble Sort)
funciona iterando sobre el arreglo varias veces, comparando cada par de elementos
adyacentes y swaps them if they are in the wrong order. El proceso se repite hasta
que no se produzcan m�s swaps, lo que indica que el arreglo est� ordenado.
*/
// Incluimos la biblioteca iostream para entrada y salida de datos
#include <iostream>
// Incluimos la biblioteca vector para trabajar con arreglos din�micos
#include <vector>

// Usamos el espacio de nombres std para evitar tener que escribir std:: antes de cada funci�n o clase
using namespace std;

// Funci�n bubbleSort que ordena un arreglo de enteros
void bubbleSort(vector<int>& vec) {
    // Obtenemos el tama�o del arreglo
    int n = vec.size();

    // Iteramos sobre el arreglo varias veces
    for (int i = 0; i < n-1; i++) {
        // Iteramos sobre cada par de elementos adyacentes
        for (int j = 0; j < n-i-1; j++) {
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (vec[j] > vec[j+1]) {
                // Usamos la funci�n swap para intercambiar los elementos
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

// Funci�n main, punto de entrada del programa
int main() {
    // Creamos un arreglo din�mico de enteros
    vector<int> vec = {5, 3, 8, 2, 1, 6, 4};

    // Llamamos a la funci�n bubbleSort para ordenar el arreglo
    bubbleSort(vec);

    // Imprimimos el arreglo ordenado
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // Regresamos 0 para indicar que el programa se ejecut� correctamente
    return 0;
}
