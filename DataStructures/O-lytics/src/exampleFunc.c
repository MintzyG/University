#include "exampleFunc.h"
#include<stdio.h>
#include "string.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void* bubble(void* ptr, int size, int* cmp, int* swp, int* ops) {
  // printf("%s: Started sorting\n", __func__);
  int* arr = (int*)ptr;
  int i, j, swapped;

  for (i = 0; i < size - 1; i++) {
    (*ops)++;
    swapped = 0;

    for (j = 0; j < size - i - 1; j++) {
      (*cmp)++;

      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapped = 1;
        (*ops)++;
        (*swp) += 3;
      }

    }

    (*cmp)++;
    if (swapped == 0)
      break;
  }

  return (void*)arr;
}
