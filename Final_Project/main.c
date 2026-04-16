#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tnode.h"
#include "bst.h"
#include "node.h"
#include "dll.h"

int main() {
    DLL *list = createList();
    BST *tree = createTree();
    int choice;
    char buffer[22];

    char startChar;
    int character; //Inline clearing
    Node *newNode;
    Node *foundNode;
    TNode *newTNode;
    TNode *foundTNode;

    do {
        printf("\n--- DLL operations ---\n");
        printf("11. Insert a string into the list\n");
        printf("12. Filter by initial letter in the list\n");
        printf("13. Search for a word in the list\n");
        printf("14. Delete a word from the list\n");
        printf("15. Load a file into the list\n");
        printf("16. Store the list to a file\n\n");
        printf("--- BST operations ---\n");
        printf("21. Insert a string into the tree\n");
        printf("22. Filter by initial letter in the tree\n");
        printf("23. Search for a word in the tree\n");
        printf("24. Delete a word from the tree\n");
        printf("25. Load a file into the tree\n");
        printf("26. Store the tree to a file\n\n");
        printf("0. Free memory and exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            choice = -1; //-1 is an Invalid choice
        }
        while ((character = getchar()) != '\n' && character != EOF);
        switch (choice) {
            case 11:
                newNode = createNode(NULL);
                if (newNode != NULL) {
                    insert(list, newNode);
                    printf("The Node has been inserted.\n");
                }
                break;
            case 12:
                printf("Give the initial letter: ");
                scanf("%c", &startChar);
                while ((character = getchar()) != '\n' && character != EOF);
                displayList(list, startChar);
                break;
            case 13:
                printf("Enter the word to search: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                foundNode = search(list, buffer);
                if (foundNode != NULL) {
                    printf("String has been found at the address: %p\n", (void*)foundNode);
                } else {
                    printf("String was not found.\n");
                }
                break;
            case 14:
                printf("Enter a string to be deleted: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                foundNode = search(list, buffer);
                if (foundNode != NULL) {
                    Remove(list, foundNode);
                    printf("The Node has been deleted.\n");
                } else {
                    printf("String was not found.\n");
                }
                break;
            case 15:
                printf("Enter a filename to load the list from: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                loadTextFile(list, buffer);
                break;
            case 16:
                printf("Enter a filename to save the list to: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                storeTextFile(list, buffer);
                break;
            case 21:
                newTNode = createTNode(NULL);
                if (newTNode != NULL) {
                    bstInsert(tree, newTNode);
                    printf("The TNode has been inserted.\n");
                }
                break;
            case 22:
                printf("Enter the initial letter to filter by: ");
                scanf(" %c", &startChar);
                while ((character = getchar()) != '\n' && character != EOF);
                printAlphabetical(tree, startChar);
                break;
            case 23:
                printf("Enter word to search: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                foundTNode = Tsearch(tree, buffer);
                if (foundTNode != NULL) {
                    printf("The TNode has been found in the tree on the following address: %p\n", (void*)foundTNode);
                } else {
                    printf("TNode has not been found.\n");
                }
                break;
            case 24:
                printf("Enter a word to delete: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                TRemove(tree, buffer);
                break;
            case 25:
                printf("Enter a filename to load the tree from: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                TloadTextFile(tree, buffer);
                printf("Loading was successful.\n");
                break;
            case 26:
                printf("Enter a filename to save the tree to: ");
                scanf("%s", buffer);
                while ((character = getchar()) != '\n' && character != EOF);
                TstoreTextFile(tree, buffer);
                printf("Tree stored successfully.\n");
                break;
            case 0:
                printf("Freeing and exiting...");
                freeList(list);
                freeTree(tree);
                break;
            default:
                printf("Invalid choice. Try again!\n");
                break;
        }

    } while (choice != 0);
    return 0;
}