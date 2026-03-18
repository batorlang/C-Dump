#include <stddef.h>

void BubbleSort(int ai[], const size_t n) {
    if (n < 2) {
        return;
    }

    for (size_t i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (size_t j = 0; j < n - i - 1; j++) {
            if (ai[j] > ai[j + 1]) {
                int temp = ai[j];
                ai[j] = ai[j + 1];
                ai[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}