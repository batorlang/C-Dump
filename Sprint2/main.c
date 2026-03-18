#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "dll.h"

int main() {
    DLL *list1 = createList();
    int choice;

    //Variables to be used:
    char startChar, searchString[100], filename[100];
    Node *foundNode;
    Node *newNode;


    do {
        printf("1. Insert a string\n2. Filter by initial letter\n3. Find a string and delete it\n4. Import data from a file\n5. Store list to a file\n6. Free the space and exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) { //If user did not input 1, then its garbage. 
            while (getchar() != '\n'); //This line clears the buffer from letters, bu one by one reading the useless input out of the buffer till the new line character. 
            choice = 0; //Sets the choice to an invalid one. 
        }

        switch (choice) {
            case 1:
                newNode = createNode(NULL);
                insert(list1, newNode);
                printf("Node is inserted.\n");
                break;
            case 2:
                printf("Give the initial letter: ");
                scanf(" %c", &startChar);
                displayList(list1, startChar);
                break;
            case 3:
                printf("Enter the string to delete: ");
                scanf("%s", searchString);
                foundNode = search(list1, searchString);
                if (foundNode != NULL) {
                    Remove(list1, foundNode);
                    printf("Node was successfully removed.\n");
                } else {
                    printf("String was not found in the list.\n");
                }
                break;
            case 4:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadTextFile(list1, filename);
                break;
            
            case 5:
                printf("Enter filename to save to: ");
                scanf("%s", filename);
                storeTextFile(list1, filename);
                break;

            case 6:
                printf("Freeing memory and exiting!\n");
                freeList(list1);
                break;
                
            default:
                printf("Invalid choice, Try again!\n");
                break;
        }

    } while (choice != 6);

    return 0;
}