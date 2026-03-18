#ifndef DLL_H
#define DLL_H


#include "node.h"
typedef struct {
    Node *head;
} DLL;

//Functions
DLL * createList();
int listEmpty(DLL *list);
void insert(DLL *list, Node *newNode);
void displayList(DLL *list);

#endif