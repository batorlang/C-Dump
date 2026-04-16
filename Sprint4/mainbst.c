#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"
#include "bst.h"


int main() {
    BST *tree = createTree();
    int choice;
    char buffer[22];
    char filename[100];
    char startChar;
    do {
    
        printf("1. Insert a node\n2. Filter by initial letter\n3. Search word\n4. Delete word\n5. Load file\n6. Store file\n7. Free the space and exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            choice = 0; 
        }
        int character;
        while ((character = getchar()) != '\n' && character != EOF);
        switch(choice) {
            case 1:
                TNode *newNode = createTNode(NULL);
                if (newNode != NULL) {
                    bstInsert(tree, newNode);
                }
                break;
            case 2:
                printf("Enter the initial letter to filter by: ");
                if (scanf("%c", &startChar) == 1) {
                    while (getchar() != '\n');
                    printAlphabetical(tree, startChar);
                }
                break;
            case 3:
                printf("Enter word to search: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                    buffer[strcspn(buffer, "\n")] = 0;
                    
                    TNode *foundNode = Tsearch(tree, buffer);
                    if (foundNode != NULL) {
                        printf("The address is: %p\n", (void*)foundNode);
                    } else {
                        printf("Value not found\n");
                    }
                }
                break;
            case 4:
                printf("Enter word to delete: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                TRemove(tree, buffer);
                break;
            case 5:
                printf("Enter filename to load: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                
                TloadTextFile(tree, filename);
                printf("File loading successful.\n");
                break;
            case 6:
                printf("Enter filename to store: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                TstoreTextFile(tree, filename); 
                printf("Tree stored to %s successfully.\n", filename);
                break;
            case 7:
                freeTree(tree);
                printf("Space freed. Exiting program...\n");
                return 0;
            default:
                printf("Invalid Input try again!");
                break;
        }
        printf("\n");

    } while (choice != 7);

    
    return 0;

}