/*
Jesus Alejandro Montes Aguila
03/06/2024
"Distribution Initial Rusn"
Este código genera la distribución de inicial runs para un arreglo
arr de tamaño n y un número de runs k. La función generateInitialRuns
devuelve un vector de vectores, donde cada vector representa una run.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para generar la distribución de inicial runs
vector<vector<int>> generateInitialRuns(int arr[], int n, int k) {
    vector<vector<int>> runs(k);

    int runSize = n / k;
    int remainder = n % k;

    int index = 0;
    for (int i = 0; i < k; i++) {
        int runLength = runSize + (i < remainder? 1 : 0);
        vector<int> run(runLength);

        for (int j = 0; j < runLength; j++) {
            run[j] = arr[index++];
        }

        runs[i] = run;
    }

    return runs;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Número de runs

    vector<vector<int>> runs = generateInitialRuns(arr, n, k);

    cout << "Distribución de inicial runs:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "Run " << i << ": ";
        for (int j = 0; j < runs[i].size(); j++) {
            cout << runs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
