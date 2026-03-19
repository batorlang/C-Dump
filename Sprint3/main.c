#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "tnode.h"

int main() {
    BST *tree = createTree();
    int choice;
    char buffer[22];
    do {
    
        printf("1. Insert a node\n2. Test if tree is empty\n3. Print tree\n4. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            choice = 0; 
        }
        switch(choice) {
            case 1:
                TNode *newNode = createTNode(NULL);
                if (newNode != NULL) {
                    bstInsert(tree, newNode);
                }
                break;
            case 2:
                if (treeEmpty(tree) == 1) {
                    printf("The tree is empty.\n");
                } else {
                    printf("The tree is not empty,\n");
                }
                break;
            case 3:
                printAlphabetical(tree);
                break;
            case 4:
                printf("Exiting the program!");
                return 0;
            default:
                printf("Invalid Input try again!");
                break;
        }
        printf("\n");

    } while (choice != 4);

    // Free the tree memory
    if (tree != NULL) {
                TNode *current = tree->root;
                
                while (current != NULL) {
                    if (current->left != NULL) {
                        TNode *temp = current->left;
                        while (temp->right != NULL) {
                            temp = temp->right;
                        }
                        temp->right = current->right;
                        TNode *toDelete = current;
                        current = current->left;
                        free(toDelete); 
                    } else {
                        TNode *toDelete = current;
                        current = current->right;
                        free(toDelete);
                    }
                }
                free(tree);
            }
    return 0;

}