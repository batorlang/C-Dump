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
        int comparison = strcmp(newNode->data, current->data);
        if (comparison == 0) {
            free(newNode);
            return;
        } else if (comparison < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (strcmp(newNode->data, parent->data) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void printAlphabetical(BST *tree) {
    if (treeEmpty(tree) == 1) {
        printf("The terr is empty.\n");
        return;
    }
    printf("Tree: ");
    inOrder(tree->root);
    printf("\n");
}