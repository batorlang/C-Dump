#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *first; //Starting pointer of the list
    Node *last; //End pointer of the list
} List;

List * create() {
    List * L = (List*)malloc(sizeof(List));
    if (L == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }
    L->first = NULL;
    L->last = NULL;
    return L;
}

void add(List *L, int value) {
    Node* pNew = (Node*)malloc(sizeof(Node));
    pNew->data = value;
    pNew->next = NULL;
    if (L->first == NULL) {
        L->first = pNew;
        L->last = pNew;
    } else {
        L->last->next = pNew;
        L->last = pNew;
    }
}

int find_max(List *L) {
    Node *current = L->first;
    int max_value = current->data;
    int position = 1;
    while (current != NULL) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        position++;
        current = current->next;
    }
    return max_value;
}

int main() {
    int elements, temp_value;
    List *L = create();
    printf("Enter the number of integers: ");
    scanf("%d", &elements);
    printf("Enter %d integers:\n", elements);
    for (int i = 0; i < elements; i++) {
        scanf("%d", &temp_value);
        add(L, temp_value);
        
    }
    int max_val = find_max(L);
    printf("\nThe maximum value is: %d\n", max_val);

    Node *current = L->first;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(L);

    return 0;
    
}