/*
Jesus Alejandro Montes Aguila
02/06/2024
"Polyphase sort"

Este algoritmo de Polyphase Merge Sort utiliza la técnica de fusión
 de varias "runs" en un solo arreglo ordenado. La función findRunEnd
  se utiliza para encontrar el final de cada "run" en el arreglo, y
  la función multiwayMerge se utiliza para fusionar las "runs" en un
  solo arreglo ordenado.
 El algoritmo de Polyphase Merge Sort es un algoritmo de ordenamiento
 externo que utiliza la técnica de fusión de varias "runs" en un solo
 arreglo ordenado. Este algoritmo es útil cuando se necesita ordenar
 grandes cantidades de datos que no caben en memoria.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para encontrar el final de una "run" en un arreglo ordenado
int findRunEnd(int arr[], int left, int right) {
    // Iterar desde el índice `left` hasta que encontramos un elemento que es mayor que el elemento anterior
    while (left < right && arr[left] <= arr[left + 1])
        left++;

    return left;
}

// Función para realizar la fusión de varias "runs" en un solo arreglo ordenado
void multiwayMerge(int arr[], int n, int k) {
    // Crear un vector para almacenar los índices actuales de cada "run"
    vector<int> indices(k, 0);

    // Crear un vector para almacenar los valores mínimos actuales de cada "run"
    vector<int> minValues(k);

    // Inicializar los valores mínimos y índices
    for (int i = 0; i < k; i++) {
        minValues[i] = arr[indices[i]];
    }

    // Realizar la fusión de las "runs"
    for (int i = 0; i < n; i++) {
        // Encontrar el valor mínimo entre los valores mínimos actuales de cada "run"
        int minIndex = 0;
        for (int j = 1; j < k; j++) {
            if (minValues[j] < minValues[minIndex]) {
                minIndex = j;
            }
        }

        // Imprimir el valor mínimo
        cout << minValues[minIndex] << " ";

        // Avanzar al siguiente elemento en la "run" correspondiente
        indices[minIndex]++;

        // Si hemos llegado al final de una "run", encontrar el inicio de la próxima "run"
        if (indices[minIndex] >= findRunEnd(arr, indices[minIndex], n)) {
            indices[minIndex] = findRunEnd(arr, indices[minIndex], n) + 1;
        }

        // Actualizar los valores mínimos
        minValues[minIndex] = arr[indices[minIndex]];
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Número de "runs"

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Arreglo ordenado: ";
    multiwayMerge(arr, n, k);
    cout << endl;

    return 0;
}
