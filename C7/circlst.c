#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int iData;
    struct Node* pNext;
} Node;

typedef struct {
    Node* pHead;
    size_t n;
} CircularList;

void InitList( CircularList* pList ) {
    pList->pHead = NULL;
    pList->n = 0;
}

void FreeList( CircularList* pList ) {
    if (pList == NULL || pList->pHead == NULL) {
        if (pList != NULL) {
            pList->n = 0;
        }
        return;
    }

    Node* pCurrent = pList->pHead;
    Node* pNextNode;
    for (size_t i = 0; i < pList->n; i++) {
        pNextNode = pCurrent->pNext;
        free(pCurrent);
        pCurrent = pNextNode;
    }

    pList->pHead = NULL;
    pList->n = 0;
}

void InsertEnd( CircularList* pList, const int iValue ) {
    if (pList == NULL) return;
    Node* pNew = (Node*)malloc(sizeof(Node));

    if (pNew == NULL) return;
    pNew->iData = iValue;

    if (pList->pHead == NULL) {

        pList->pHead = pNew;
        pNew->pNext = pNew;
    } else {
        Node* pLast = pList->pHead;
        while (pLast->pNext != pList->pHead) {
            pLast = pLast->pNext;
        }

        pLast->pNext = pNew;
        pNew->pNext = pList->pHead;
    }
    pList->n++;
}

float ComputeAverage(const CircularList* pList) {
    int sum = 0;
    Node* pCurrent = pList->pHead;
    for (size_t i = 0; i < pList->n; i++) {
        sum += pCurrent->iData;
        pCurrent = pCurrent->pNext;
    }
    return (float)sum / (float)pList->n;
}

size_t DeleteLt(CircularList* pList, const int iValue) {
    size_t deletedCount = 0;
    size_t originalSize = pList->n;
    Node* pCurr = pList->pHead;
    Node* pPrev = NULL;

    Node* pLast = pList->pHead;
    while (pLast->pNext != pList->pHead) {
        pLast = pLast->pNext;
    }

    for (size_t i = 0; i < originalSize; i++) {
        if (pCurr->iData < iValue) {
            Node* pToDelete = pCurr;
            
            if (pToDelete == pList->pHead) {
                if (pList->n == 1) {
                    pList->pHead = NULL;
                    pCurr = NULL;
                } else {
                    pList->pHead = pCurr->pNext;
                    pLast->pNext = pList->pHead;
                    pCurr = pList->pHead;
                }
            } else {
                pPrev->pNext = pCurr->pNext;
                pCurr = pPrev->pNext;
            }

            free(pToDelete);
            pList->n--;
            deletedCount++;
        } else {
            pPrev = pCurr;
            pCurr = pCurr->pNext;
        }
        
        if (pList->pHead == NULL) break;
    }

    return deletedCount;
}