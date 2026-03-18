#include <stdio.h>

void Swap(int* pi1, int* pi2) {

    int temporary = *pi1;
    *pi1 = *pi2;
    *pi2 = temporary;
}
