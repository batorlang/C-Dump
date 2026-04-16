#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

BST* createTree() {
    BST *newTree = (BST*)malloc(sizeof(BST));
    if (newTree != NULL) { //Safety check
        newTree->root = NULL; //Set the tree empty
    }
    return newTree;
}

int treeEmpty(BST *tree) {
    if (tree == NULL || tree->root == NULL) {
        return 1; //Output for tree being empty
    }
    return 0; //Output for tree being not empty
}

void bstInsert(BST *tree, TNode *newNode) {
    if (tree == NULL || newNode == NULL) { //Safety check
        return;
    }
    if (tree->root == NULL) { //If the tree is empty, then the new Node will be the root
        tree->root = newNode;
        return;
    }

    TNode *current = tree->root; //current tracker
    TNode *parent = NULL; // parent tracker
    while (current != NULL) {
        parent = current;
        int comparison = strcmp(newNode->data, current->data);//comparing the newnode with current
        if (comparison == 0) {
            free(newNode);//alrdy there, just delete
            return;
        } else if (comparison < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (strcmp(newNode->data, parent->data) < 0) {//We dont know exacly if we arrived at the right place, so compare again
        parent->left = newNode;//if the new data is alphabetically less than the parent, its going to the left, otherwise, right
    } else {
        parent->right = newNode;
    }
}

void printAlphabetical(BST *tree, char startChar) {
    if (tree->root == NULL) {
        printf("The tree is empty.\n");
        return;
    }
    printf("Tree: ");
    inOrderFiltered(tree->root, startChar);
    printf("\n");
}

TNode * Tsearch(BST *tree, char * key) {//returns a pointer to a node
    if (tree == NULL ||tree->root == NULL||key == NULL) {
        return NULL;//safety check
    }
    TNode *current = tree->root;
    while (current != NULL) {
        int cmp = strcmp(key, current->data);
        if (cmp == 0) {
            return current;
        }else if (cmp < 0) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
    return NULL;//didnt fint the node so return null
}

void TRemove(BST *tree, char * key) {
    if (tree == NULL || tree->root == NULL || key == NULL) {
        printf("Value not found\n"); //safety check
        return;
    }
    TNode *current = tree->root;//trackers for current and parent
    TNode *parent = NULL;

    while (current != NULL && strcmp(current->data, key) != 0) {
        parent = current;
        if (strcmp(key, current->data) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == NULL) {
        printf("Value not found\n");
        return;
    }


    if (current->left == NULL || current->right == NULL) {
        TNode *newChild;
        if (current->left == NULL) {
            newChild = current->right;
        } else {
            newChild = current->left;
        }
        if (parent == NULL) {//case of deleting the root
            tree->root = newChild;
        } else if (current == parent->left) {
            parent->left = newChild;
        } else {
            parent->right = newChild;
        }
        printf("The node at address %p is deleted\n", (void*)current);
        free(current);
    }
    //Case of two children
    else {
        TNode *successorParent = current;
        TNode *successor = current->right;
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        strcpy(current->data, successor->data);
        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        printf("The node at address %p is deleted\n", (void*)successor);
        free(successor);
    }
}
void TloadTextFile(BST *tree, char * filename) {
    if (tree == NULL || filename == NULL) {
        return;
    }
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR while opening the file.");
        return;
    }
    char buffer[22];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; //replace the new line char with a null terminator
        if (strlen(buffer) > 0) {
            TNode *newNode = createTNode(buffer);
            if (newNode != NULL) {
                bstInsert(tree, newNode);
            }
        }
    }
    fclose(fp);
}

void TstoreTextFile(BST *tree, char *filename) {
    if (tree == NULL || filename == NULL) {
        return;
    }
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    if (tree->root != NULL) {
        writePreOrder(tree->root, fp);
    }
    fclose(fp);
}
void freeTree(BST *tree) {
    if (tree == NULL) {
        return;
    }
    freeNodes(tree->root);

    free(tree);
}