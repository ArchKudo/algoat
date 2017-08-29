#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

int main(int argc, const char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s [Array Elements]\n", argv[0]);
    return 1;
  }

  int size = (argc - 1) - 1;
  int array[size];
  int pin;
  int index;

  for (int i = 0; i < size; i++) {
    array[i] = atoi(argv[i + 2]);
  }

  printf("Enter element to search for: ");
  scanf("%d", &pin);

  index = binary_search(array, size, pin);
  if (index != -1) {
    printf("Found %d at %d\n", pin, index);
  } else {
    printf("Not found %d in array\n", pin);
  }
  return 0;
}
