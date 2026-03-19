#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"

TNode* createTNode(const char *key) {
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    //Set the child pointers
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (key == NULL) {
        char buffer[22];
        printf("Enter a string for the newly created node: ");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = 0; //0 is the null terminator, we replace the \n with \0 to properly terminate the string.
            strcpy(newNode->data, buffer);
        }
    } else {
        strcpy(newNode->data, key);
    }
    return newNode;
}

void printTNode(TNode *nodePtr) {
    if (nodePtr == NULL) {
        printf("The node is NULL.");
    }
    else {
        printf("(%s)", nodePtr->data);
    }
}

void inOrder(TNode *node) {
    if (node == NULL) { //If the node is NULL, no need for recursion for this branch of the tree(end). 
        return;
    }

    inOrder(node->left); //1. Recursively visit the current node's left node.
    printTNode(node); //2. print the node
    inOrder(node->right); //3. Recursively visit the current node's right node.
}