#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *hay, int size, int pin) {
  int max = size - 1;
  int min = 0;
  int guess = 0;
  while (max >= min) {
    guess = (int)((max + min) / 2);
    if (hay[guess] == pin) {
      return guess;
    } else if (hay[guess] < pin) {
      min = guess + 1;
    } else {
      max = guess - 1;
    }
  }
  return -1;
}
