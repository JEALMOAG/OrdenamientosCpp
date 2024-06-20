/*
Jesus Alejandro Montes Aguila
25/05/2024
"Ordenamiento de Arbol"

Este código implementa un árbol de búsqueda binario (BST) en C++.
La estructura del árbol se almacena en memoria dinámica, y se
utiliza una función insert para insertar nuevos nodos en el árbol.
La función inorder se utiliza para imprimir el árbol en orden,
lo que significa que los nodos se imprimen en orden ascendente.
En el main, creamos un árbol vacío, insertamos varios nodos con
valores específicos y finalmente imprimimos el árbol en orden
ascendente.
*/
#include <iostream>

using namespace std;

// Nodo del árbol
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Función para crear un nuevo nodo
Node* newNode(int data) {
    Node* node = new Node();
    if (!node) {
        cout << "Memory error\n";
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Función para insertar un nuevo nodo en el árbol
Node* insert(Node* root, int data) {
    // Si el árbol está vacío, creamos un nuevo nodo y lo regresamos
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Si el valor a insertar es menor que el del nodo actual, insertamos a la izquierda
    if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    // Si el valor a insertar es mayor que el del nodo actual, insertamos a la derecha
    else {
        root->right = insert(root->right, data);
    }

    // Regresamos el nodo actual
    return root;
}

// Función para imprimir el árbol en orden
void inorder(Node* temp) {
    if (temp == NULL) {
        return;
    }

    // Primero imprimimos el subárbol izquierdo
    inorder(temp->left);

    // Luego imprimimos el nodo actual
    cout << temp->data << " ";

    // Por último, imprimimos el subárbol derecho
    inorder(temp->right);
}

int main() {
    Node* root = NULL;

    // Insertamos nodos en el árbol
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Imprimimos el árbol en orden
    cout << "Árbol en orden: ";
    inorder(root);
    cout << endl;

    return 0;
}
