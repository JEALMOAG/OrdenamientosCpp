/*
Jesus Alejandro Montes Aguila
29/05/2024
"Radix Sort"

Este código utiliza el algoritmo de Radix Sort para ordenar un arreglo de enteros.
La función countDigits cuenta el número de dígitos del número más grande en el
arreglo, y la función getDigit obtiene el dígito en una posición específica de un número.

La función radixSort realiza el ordenamiento utilizando buckets para cada dígito
(de 0 a 9). En cada iteración, se distribuyen los elementos del arreglo en los
buckets según el dígito actual, y luego se recopilan los elementos de los buckets
en el orden correcto.

Finalmente, la función printArray imprime el arreglo original y el arreglo ordenado.
*/
#include <iostream>   // Biblioteca para la entrada y salida estándar
#include <vector>     // Biblioteca para el uso de vectores
#include <cmath>      // Biblioteca para funciones matemáticas como pow()
#include <algorithm>  // Biblioteca para algoritmos estándar como max_element

using namespace std;  // Para evitar el uso del prefijo std::

// Función para contar el número de dígitos de un número
int countDigits(int num) {
    int count = 0;
    if (num == 0) return 1; // Caso especial para el número 0
    while (num != 0) {  // Mientras el número no sea cero
        num /= 10;      // Dividir el número por 10
        count++;        // Incrementar el contador de dígitos
    }
    return count;       // Retornar el número de dígitos
}

// Función para obtener el dígito en una posición específica
int getDigit(int num, int pos) {
    return (num / static_cast<int>(pow(10, pos - 1))) % 10;  // Obtener el dígito en la posición deseada
}

// Función para realizar el Radix Sort
void radixSort(vector<int>& arr) {
    int maxNum = *max_element(arr.begin(), arr.end());  // Obtener el número máximo en el arreglo
    int maxDigits = countDigits(maxNum);  // Contar el número de dígitos del número máximo

    for (int i = 1; i <= maxDigits; i++) {  // Iterar a través de cada posición de dígito
        vector<int> buckets[10];  // Crear 10 cubetas para los dígitos del 0 al 9

        for (int j = 0; j < arr.size(); j++) {  // Colocar los números en las cubetas según el dígito actual
            int digit = getDigit(arr[j], i);
            buckets[digit].push_back(arr[j]);
        }

        int index = 0;  // Reconstruir el arreglo a partir de las cubetas
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < buckets[j].size(); k++) {
                arr[index++] = buckets[j][k];
            }
        }
    }
}

// Función para imprimir el arreglo
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Imprimir cada elemento del arreglo seguido de un espacio
    }
    cout << endl;  // Nueva línea al final
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};  // Inicializar un arreglo con elementos desordenados
    cout << "Arreglo original: ";
    printArray(arr);  // Imprimir el arreglo original

    radixSort(arr);  // Ordenar el arreglo usando Radix Sort

    cout << "Arreglo ordenado: ";
    printArray(arr);  // Imprimir el arreglo ordenado

    return 0;  // Indicar que el programa finalizó correctamente
}

