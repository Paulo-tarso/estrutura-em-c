#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Estrutura da fila para armazenar os valores na ordem de inserção
struct Queue {
    int data;
    struct Queue* next;
};

// Função para inicializar a árvore (retorna NULL, pois a árvore começa vazia)
struct Node* init() {
    return NULL;
}

// Função para criar um novo nó
struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) { printf("Erro ao alocar memória.\n"); return NULL; }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return create(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// Função para enfileirar um valor
void enqueue(struct Queue** queue, int value) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = value;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        struct Queue* temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para imprimir a fila na ordem de inserção
void printQueue(struct Queue* queue) {
    while (queue != NULL) {
        printf("%d ", queue->data);
        queue = queue->next;
    }
}

// Função para inverter a fila
void reverseQueue(struct Queue** queue) {
    struct Queue* prev = NULL;
    struct Queue* current = *queue;
    struct Queue* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *queue = prev;
}

// Função para imprimir a árvore em ordem de inserção (usando fila)
void printInInsertionOrder(struct Node* root, struct Queue** queue) {
    if (root == NULL) return;

    // Enfileira o valor do nó conforme é inserido
    enqueue(queue, root->data);

    // Continue a travessia em pré-ordem (primeiro o nó, depois a esquerda, depois a direita)
    printInInsertionOrder(root->left, queue);
    printInInsertionOrder(root->right, queue);
}

// Função principal para teste
int main() {
    struct Node* root = init();
    struct Queue* queue = NULL;

    // Inserindo nós
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Valores na ordem de inserção: ");
    printInInsertionOrder(root, &queue);

    // Imprime os valores na fila (na ordem em que foram inseridos)
    printQueue(queue);
    printf("\n");

    // Inverte a fila
    reverseQueue(&queue);

    printf("Valores na ordem inversa de inserção: ");
    printQueue(queue);
    printf("\n");

    return 0;
}
