#include "bin_search.h"
#include <assert.h>
#include <stdio.h>

int bin_search(int* arr, int size, int val) {
  int min_index = 0;
  int max_index = size;
  int guess = 0;
  while (max_index >= min_index) {
    guess = (int)(min_index + max_index) / 2;

    if (arr[guess] == val) {
      return guess;
    } else if (arr[guess] < val) {
      min_index = guess + 1;
    } else {
      max_index = guess - 1;
    }
  }
  return -1;
}

int main() {
  int prime_numbers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  size_t size = sizeof(prime_numbers) / sizeof(size);
  for (int i = 0; i < (int)size; i++) {
    assert(bin_search(prime_numbers, size, prime_numbers[i]) == i);
    printf("Found %d at %d\n", prime_numbers[i],
           bin_search(prime_numbers, size, prime_numbers[i]));
  }
  return 0;
}
