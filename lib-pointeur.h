#include <stdio.h>

void swap(int *a, int *b) {
    printf("---swap---\n");
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}