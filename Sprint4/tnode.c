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

void inOrderFiltered(TNode *node, char startChar) {
    if (node == NULL) { //If the node is NULL, no need for recursion for this branch of the tree(end). 
        return;
    }

    inOrderFiltered(node->left, startChar); //1. Recursively visit the current node's left node.
    if (node->data[0] == startChar){
        printTNode(node); //2. print the node
    }
    inOrderFiltered(node->right, startChar); //3. Recursively visit the current node's right node.
}
void writePreOrder(TNode *node, FILE *fp) {
    if (node == NULL) {
        return;
    }
    fprintf(fp, "%s\n", node->data); //CUrrent node is processed at first
    writePreOrder(node->left, fp);//Then we proceed to the left because of pre-order
    writePreOrder(node->right, fp);//Then we process all the right nodes.
}



void freeNodes(TNode *node) {
    if (node == NULL) {
        return;
    }
    freeNodes(node->left);
    freeNodes(node->right);
    free(node);
}