#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;
//Creating an empty queue
 Queue *createQueue() {
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    if (Q == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
 }
//Function that checks if Queue is empty
int QueueEmpty(Queue *Q) {
    if (Q->front == NULL) {
        return 1; //Condition is true, return 1 (true == empty)
    } else {
        return 0; //Contion is false, return 0 (false != empty)
    }
}
//Enqueue function (adding elements to the queue at the rear)
void Enqueue(Queue *Q, int key) {
    Node *pNew = (Node*)malloc(sizeof(Node));
    pNew->data = key;
    pNew->next = NULL;
    if (QueueEmpty(Q) == 1) {
        Q->front = pNew;
        Q->rear = pNew;
    } else {
        Q->rear->next = pNew;
        Q->rear = pNew;
    }
}
//Dequeue function (removing elements from the front)
int Dequeue(Queue *Q) {
    if (QueueEmpty(Q) == 1) { //This prevents crashes if the queue is already empty
        printf("Queue is already empty!\n");
        return -1;
    }
    int temp_value = Q->front->data;
    Node *current = Q->front;
    Q->front = Q->front->next;
    free(current);
    if (QueueEmpty(Q) == 1) {
        Q->front = NULL;
        Q->rear = NULL;
    }
    return temp_value;
}

int main() {
    Queue *Q = createQueue();
    int choice;
    int add_value;
    do {
        printf("Menu:\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Quit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &add_value);
                Enqueue(Q, add_value);
                printf("Enqueued: %d\n", add_value);
                break;
            case 2:
                int removed_value = Dequeue(Q);
                printf("Dequeued: %d\n", removed_value);
                break;
            case 3:
                Node *current = Q->front;
                printf("Queue: ");
                    while (current != NULL) {
                        printf("%d", current->data);
                        if (current->next != NULL) {
                            printf(" ");
                        }
                        current = current->next;
                    }
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        } 
    } while (choice != 4);

    Node *temp_ptr = Q->front;
    while (temp_ptr != NULL) {
        Node *next_node = temp_ptr->next;
        free(temp_ptr);
        temp_ptr = next_node;
    }
    
    free(Q);
    
    return 0;
}
    
