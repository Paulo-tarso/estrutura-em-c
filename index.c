#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
struct Node {
    int data;
    struct Node* next;
};

// Inicializa a pilha (topo aponta para NULL)
void initialize(struct Node** top_ref) {
    *top_ref = NULL;
}

// Função para inserir um nó no topo da pilha
void push(struct Node** top_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (!new_node) {
        printf("Erro: Memória insuficiente.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *top_ref;

    *top_ref = new_node;
}

// Função para remover o nó do topo da pilha
int pop(struct Node** top_ref) {
    if (*top_ref == NULL) {
        printf("Erro: Pilha vazia.\n");
        return -1;  // Valor de erro
    }

    struct Node* temp = *top_ref;
    int popped_data = temp->data;

    *top_ref = temp->next;

    free(temp);

    return popped_data;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Função para exibir os elementos da pilha
void printStack(struct Node* top) {
    if (top == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }

    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para reinicializar a pilha
void reinitialize(struct Node** top_ref) {
    struct Node* current = *top_ref;
    struct Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *top_ref = NULL;  // Pilha reinicializada
}

// Função principal
int main() {
    struct Node* top = NULL;
    initialize(&top);

    // Inserir elementos na pilha
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    // Exibir a pilha
    printStack(top);

    // Remover o elemento do topo
    int poppedElement = pop(&top);
    printf("Elemento removido: %d\n", poppedElement);

    // Exibir a pilha novamente
    printStack(top);

    // Reinicializar a pilha
    reinitialize(&top);
    printStack(top);

    return 0;
}
