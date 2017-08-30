#include "binary_search.h"
#include <stdint.h>
#include <stdlib.h>

int16_t binary_search(int_fast64_t *arr, uint8_t size, int_fast64_t query) {
  uint8_t max = size - 1;
  uint8_t min = 0;

  while (min <= max) {
    uint8_t mid = (uint8_t)(min + (max - min) / 2);
    int_fast64_t val = arr[mid];
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
