#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "dll.h"

int main() {
    DLL *list1 = createList();
    int choice;


    do {
        printf("1. Insert a string\n2. Display the list\n3. Check if empty\n4. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); //This line clears the buffer from letters.
            choice = 0; //Sets the choice to an invalid one. 
        }

        switch (choice) {
            case 1:
                Node *newNode = createNode(NULL);
                if (newNode != NULL) {
                    insert(list1, newNode);
                    printf("Node inserted.\n");
                }
                break;
            case 2:
                displayList(list1);
                break;
            case 3:
                if (listEmpty(list1)) {
                    printf("The list is empty.\n");
                } else {
                    printf("The list is Not empty.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, Try again!\n");
                break;
        }

    } while (choice != 4);
//Free allocated memory.
    Node *current = list1->head;
        while (current != NULL) {
            Node *temporary = current;
            current = current->next;
            free(temporary);
        }
        free(list1);

    return 0;
}