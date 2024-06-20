/*
Jesus Alejandro Montes Aguila
24/05/2024
"Insertion Sort"

Este algoritmo ordena un arreglo de enteros mediante la selecci�n
 repetida del elemento m�nimo en la parte no ordenada del arreglo
  y su intercambio con el elemento en la parte ordenada en la misma
  posici�n. El proceso se repite hasta que todo el arreglo est� ordenado.
*/
#include <iostream>   // Biblioteca para la entrada y salida est�ndar
#include <vector>     // Biblioteca para el uso de vectores

using namespace std;  // Para evitar el uso del prefijo std::

// Funci�n para realizar el ordenamiento por selecci�n
void selectionSort(vector<int>& vec) {
    int n = vec.size();  // Obtener el tama�o del vector
    for (int i = 0; i < n - 1; i++) {  // Iterar sobre cada elemento del vector excepto el �ltimo
        int min_idx = i;  // Asumir que el primer elemento no ordenado es el m�nimo
        for (int j = i + 1; j < n; j++) {  // Iterar sobre los elementos no ordenados
            if (vec[j] < vec[min_idx]) {  // Encontrar el �ndice del valor m�nimo en la porci�n no ordenada
                min_idx = j;  // Actualizar el �ndice del m�nimo
            }
        }
        swap(vec[min_idx], vec[i]);  // Intercambiar el m�nimo encontrado con el primer elemento no ordenado
    }
}

int main() {
    vector<int> vec = {12, 11, 13, 5, 6};  // Inicializar un vector con elementos desordenados
    selectionSort(vec);  // Ordenar el vector usando el algoritmo de selecci�n
    for (int i = 0; i < vec.size(); i++) {  // Iterar sobre el vector ordenado
        cout << vec[i] << " ";  // Imprimir cada elemento del vector ordenado seguido de un espacio
    }
    return 0;  // Indicar que el programa finaliz� correctamente
}
