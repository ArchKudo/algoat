#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int size, int query) {
  int max = size - 1;
  int min = 0;

  while (min <= max) {
    int mid = (int)((max + min) / 2);
    int val = arr[mid];
    if (val == query) {
      return mid;
    } else if (val < query) {
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }
  return -1;
}
