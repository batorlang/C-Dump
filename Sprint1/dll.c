#include "dll.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

DLL * createList() {
    DLL *list = (DLL*)malloc(sizeof(DLL));
    if (list != NULL) {
        list->head = NULL; //Indicated an empty list
    }
    return list;
}

int listEmpty(DLL *list) {
    if (list == NULL || list->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insert(DLL *list, Node *newNode) {
    if (list == NULL || newNode == NULL) return;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;


    while (current != NULL && strcmp(current->data, newNode->data) < 0) { //this condition keeps the alphabetical order in the ddl.
        previous = current;
        current = current->next;
    }
    //new head (head insertion)
    if (previous == NULL) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else { //middle insertion
        newNode->next = current;
        newNode->prev = previous;
        previous->next = newNode;
        if (current != NULL) {
            current->prev = newNode;
        }
    }
}

void displayList(DLL *list) {
    if (listEmpty(list)) {
        printf("This list is empty.\n");
        return;
    }
    printf("List: ");
    Node *current = list->head;

    while (current != NULL) {
        printNode(current);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}
