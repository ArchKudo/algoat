#include <criterion/criterion.h>
#include <stdio.h>
#include "binary_search.h"

Test(test_binary_search, test_search_returns_index_if_item_exists) {
  int prime_numbers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  size_t size = sizeof(prime_numbers) / sizeof(prime_numbers[0]);
  for (int i = 0; i < (int)size; i++) {
    cr_assert(binary_search(prime_numbers, (int)size, prime_numbers[i]) == i);
  }
}

Test(test_binary_search, test_search_returns_negative_one_if_not_item) {
  int prime_numbers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  size_t size = sizeof(prime_numbers) / sizeof(prime_numbers[0]);
  cr_assert(binary_search(prime_numbers, (int)size, 4) == -1);
}
