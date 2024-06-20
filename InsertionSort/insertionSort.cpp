/*
Jesus Alejandro Montes Aguila
23/05/2024
"Insertion Sort"

El c�digo implementa el algoritmo de ordenamiento por inserci�n (Insertion Sort)
en C++. La funci�n `insertionSort()` itera sobre cada elemento del vector, comenzando
desde el segundo elemento, y lo compara con los elementos anteriores. Si el elemento
actual es menor que alguno de los elementos anteriores, lo desplaza hacia la derecha
hasta encontrar su posici�n correcta. La funci�n `main()` crea un vector de enteros
desordenados, imprime su contenido original, llama a la funci�n `insertionSort()`
para ordenar el vector y luego imprime el contenido del vector ordenado. El algoritmo
de ordenamiento por inserci�n tiene una complejidad temporal de O(n^2) en el peor caso,
 lo que lo hace ineficiente para grandes conjuntos de datos. La funci�n `insertionSort()`
  modifica el vector original, lo que puede ser un problema si se necesita mantener el
  vector original intacto. El c�digo utiliza la biblioteca `vector` para trabajar con
  vectores de enteros.
*/

#include <iostream>   // Biblioteca para la entrada y salida est�ndar
#include <vector>     // Biblioteca para el uso de vectores

using namespace std;  // Para evitar el uso del prefijo std::

// Funci�n para imprimir el vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {  // Iterar sobre cada elemento en el vector
        cout << num << " ";  // Imprimir el elemento seguido de un espacio
    }
    cout << endl;  // Imprimir una nueva l�nea al final del vector
}

// Funci�n para realizar el ordenamiento por inserci�n
void insertionSort(vector<int>& vec) {
    int n = vec.size();  // Obtener el tama�o del vector
    for (int i = 1; i < n; ++i) {  // Comenzar desde el segundo elemento
        int key = vec[i];  // Guardar el elemento actual en key
        int j = i - 1;  // Inicializar j con el �ndice del elemento anterior

        // Mover los elementos del vector que son mayores que key
        // una posici�n adelante de su posici�n actual
        while (j >= 0 && vec[j] > key) {  // Mientras j sea v�lido y el elemento vec[j] sea mayor que key
            vec[j + 1] = vec[j];  // Desplazar el elemento hacia la derecha
            j = j - 1;  // Decrementar j para seguir comparando con los elementos anteriores
        }
        vec[j + 1] = key;  // Insertar el key en la posici�n correcta
    }
}

int main() {
    vector<int> vec = {12, 11, 13, 5, 6};  // Inicializar un vector con elementos desordenados

    cout << "Vector original: ";  // Mensaje de salida
    printVector(vec);  // Imprimir el vector original

    insertionSort(vec);  // Ordenar el vector usando el algoritmo de inserci�n

    cout << "Vector ordenado: ";  // Mensaje de salida
    printVector(vec);  // Imprimir el vector ordenado

    return 0;  // Indicar que el programa finaliz� correctamente
}

