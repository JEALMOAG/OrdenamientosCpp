/*
Jesus Alejandro Montes Aguila
25/05/2024
"Ordenamiento de Arbol"

Este c�digo implementa un �rbol de b�squeda binario (BST) en C++.
La estructura del �rbol se almacena en memoria din�mica, y se
utiliza una funci�n insert para insertar nuevos nodos en el �rbol.
La funci�n inorder se utiliza para imprimir el �rbol en orden,
lo que significa que los nodos se imprimen en orden ascendente.
En el main, creamos un �rbol vac�o, insertamos varios nodos con
valores espec�ficos y finalmente imprimimos el �rbol en orden
ascendente.
*/
#include <iostream>

using namespace std;

// Nodo del �rbol
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Funci�n para crear un nuevo nodo
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

// Funci�n para insertar un nuevo nodo en el �rbol
Node* insert(Node* root, int data) {
    // Si el �rbol est� vac�o, creamos un nuevo nodo y lo regresamos
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

// Funci�n para imprimir el �rbol en orden
void inorder(Node* temp) {
    if (temp == NULL) {
        return;
    }

    // Primero imprimimos el sub�rbol izquierdo
    inorder(temp->left);

    // Luego imprimimos el nodo actual
    cout << temp->data << " ";

    // Por �ltimo, imprimimos el sub�rbol derecho
    inorder(temp->right);
}

int main() {
    Node* root = NULL;

    // Insertamos nodos en el �rbol
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Imprimimos el �rbol en orden
    cout << "�rbol en orden: ";
    inorder(root);
    cout << endl;

    return 0;
}
