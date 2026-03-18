#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node creation
Node* createNode(const char *key) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL; //Memory allocation fails
    }

    newNode->prev = NULL;
    newNode->next = NULL;
    //Node not attached to the list

    if (key == NULL) {
        printf("Enter a string: ");
        scanf("%s", newNode->data);
    } else {
        strcpy(newNode->data, key);
    }

    return newNode;
}
//Printing Node
void printNode(Node *nodePtr) {
    if (nodePtr != NULL) {
       printf("[%s]", nodePtr->data);
    } else {
        printf("The node is NULL.");
    }
}