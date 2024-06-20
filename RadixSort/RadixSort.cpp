/*
Jesus Alejandro Montes Aguila
29/05/2024
"Radix Sort"

Este c�digo utiliza el algoritmo de Radix Sort para ordenar un arreglo de enteros.
La funci�n countDigits cuenta el n�mero de d�gitos del n�mero m�s grande en el
arreglo, y la funci�n getDigit obtiene el d�gito en una posici�n espec�fica de un n�mero.

La funci�n radixSort realiza el ordenamiento utilizando buckets para cada d�gito
(de 0 a 9). En cada iteraci�n, se distribuyen los elementos del arreglo en los
buckets seg�n el d�gito actual, y luego se recopilan los elementos de los buckets
en el orden correcto.

Finalmente, la funci�n printArray imprime el arreglo original y el arreglo ordenado.
*/
#include <iostream>   // Biblioteca para la entrada y salida est�ndar
#include <vector>     // Biblioteca para el uso de vectores
#include <cmath>      // Biblioteca para funciones matem�ticas como pow()
#include <algorithm>  // Biblioteca para algoritmos est�ndar como max_element

using namespace std;  // Para evitar el uso del prefijo std::

// Funci�n para contar el n�mero de d�gitos de un n�mero
int countDigits(int num) {
    int count = 0;
    if (num == 0) return 1; // Caso especial para el n�mero 0
    while (num != 0) {  // Mientras el n�mero no sea cero
        num /= 10;      // Dividir el n�mero por 10
        count++;        // Incrementar el contador de d�gitos
    }
    return count;       // Retornar el n�mero de d�gitos
}

// Funci�n para obtener el d�gito en una posici�n espec�fica
int getDigit(int num, int pos) {
    return (num / static_cast<int>(pow(10, pos - 1))) % 10;  // Obtener el d�gito en la posici�n deseada
}

// Funci�n para realizar el Radix Sort
void radixSort(vector<int>& arr) {
    int maxNum = *max_element(arr.begin(), arr.end());  // Obtener el n�mero m�ximo en el arreglo
    int maxDigits = countDigits(maxNum);  // Contar el n�mero de d�gitos del n�mero m�ximo

    for (int i = 1; i <= maxDigits; i++) {  // Iterar a trav�s de cada posici�n de d�gito
        vector<int> buckets[10];  // Crear 10 cubetas para los d�gitos del 0 al 9

        for (int j = 0; j < arr.size(); j++) {  // Colocar los n�meros en las cubetas seg�n el d�gito actual
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

// Funci�n para imprimir el arreglo
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Imprimir cada elemento del arreglo seguido de un espacio
    }
    cout << endl;  // Nueva l�nea al final
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};  // Inicializar un arreglo con elementos desordenados
    cout << "Arreglo original: ";
    printArray(arr);  // Imprimir el arreglo original

    radixSort(arr);  // Ordenar el arreglo usando Radix Sort

    cout << "Arreglo ordenado: ";
    printArray(arr);  // Imprimir el arreglo ordenado

    return 0;  // Indicar que el programa finaliz� correctamente
}

