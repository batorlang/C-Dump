#include <stddef.h>
#include <stdlib.h>

void FindTranspose(long double* pldbl, const size_t nRows, const size_t nCols) {
    if (pldbl == NULL || nRows == 0 || nCols == 0) return;

    size_t totalElements = nRows * nCols;
    long double* temp = (long double*)malloc(totalElements * sizeof(long double));
    
    if (temp == NULL) return;

    for (size_t i = 0; i < totalElements; i++) {
        temp[i] = pldbl[i];
    }

    for (size_t i = 0; i < nRows; i++) {
        for (size_t j = 0; j < nCols; j++) {
            size_t old_idx = i * nCols + j;
            size_t new_idx = j * nRows + i;
            pldbl[new_idx] = temp[old_idx];
        }
    }
    free(temp);
}