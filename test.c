#include <criterion/criterion.h>
#include "binary_search.h"

Test(test_binary_search, test_search_returns_index_if_item_exists) {
  int_fast64_t prime_numbers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                  29, 31, 37, 41, 43, 47, 53, 59, 61,
                                  67, 71, 73, 79, 83, 89, 97};
  size_t size = sizeof(prime_numbers) / sizeof(prime_numbers[0]);
  for (uint8_t i = 0; i < (uint8_t)size; i++) {
    cr_assert(binary_search(prime_numbers, (uint8_t)size, prime_numbers[i]) ==
              (int16_t)i);
  }
}

Test(test_binary_search, test_search_returns_negative_one_if_not_item) {
  int_fast64_t prime_numbers[] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                  29, 31, 37, 41, 43, 47, 53, 59, 61,
                                  67, 71, 73, 79, 83, 89, 97};
  size_t size = sizeof(prime_numbers) / sizeof(prime_numbers[0]);
  cr_assert(binary_search(prime_numbers, (uint8_t)size, (int_fast64_t)4) ==
            (int16_t)-1);
}

Test(test_binary_search, test_array_can_have_negative_numbers) {
  int_fast64_t negative_numbers[] = {-12, -10, -8, -6, -4, -2, 0};
  size_t size = sizeof(negative_numbers) / sizeof(negative_numbers[0]);
  cr_assert(binary_search(negative_numbers, (uint8_t)size, -6) == 3);
}

Test(test_binary_search, test_array_can_have_mixed_values) {
  int_fast64_t negative_numbers[] = {-6, -4, -2, 0, 2, 4, 6};
  size_t size = sizeof(negative_numbers) / sizeof(negative_numbers[0]);
  cr_assert(binary_search(negative_numbers, (uint8_t)size, 2) == 4);
}

Test(test_binary_search, test_binary_search_prevents_overflow) {
  int_fast64_t big_arr[UINT8_MAX];
  for (int i = 0; i < UINT8_MAX; i++) {
    big_arr[i] = i;
  }
  cr_assert(binary_search(big_arr, UINT8_MAX, UINT8_MAX - 1) == UINT8_MAX - 1);
}
