#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *first; //Pointer to the start of the list
    Node *last; //Pointer to the end of the list
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
//Same add function as C7T2
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


void reverse(List *L) {
    Node *previous = NULL;
    Node *current = L->first;
    Node *next = NULL;

    Node *temp_first = L->first;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    L->last = temp_first;
    L->first = previous;



}


int main() {
    List *L = create();
    int elements;
    printf("Enter the number of integers: ");
    scanf("%d", &elements);
    int numbers[elements];
    printf("Enter %d integers: ", elements);
    for ( int i = 0; i < elements; i++) {
        scanf("%d", &numbers[i]);
    }
    //adding elements with for loop
    for (int i = 0; i < elements; i++) {
        add(L, numbers[i]);
    }
    
    Node *current = L->first;
    printf("Original list: ");
    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
    reverse(L);
    current = L->first;
        printf("Reversed list: ");
        while (current != NULL) {
            printf("%d", current->data);

            if (current->next != NULL) {
                printf(" -> ");
            }
            current = current->next;
        }
    printf("\n");
        current = L->first;
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }

    free(L);

    return 0;

}