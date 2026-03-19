#ifndef BST_H
#define BST_H
#include "tnode.h"

typedef struct {
    TNode *root;
} BST;

BST * createTree();
int treeEmpty(BST *tree);
void bstInsert(BST *tree, TNode *newNode);
void printAlphabetical(BST *tree);

#endif