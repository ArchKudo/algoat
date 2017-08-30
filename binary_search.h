#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

#include <stdint.h>

/**
 * Binary search implementation, searches for `query` in `arr`
 * @param  arr  The array in which the `query` is searched for
 * @param  size The size of the array `arr`
 * @param  query  The element to search for in the array `arr`
 * @return      Returns index of `arr` at which `query` is found
 *              if exists, else -1
 */
int16_t binary_search(int_fast64_t *arr, uint8_t size, int_fast64_t query);

#endif
