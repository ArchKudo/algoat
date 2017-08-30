#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

/**
 * Binary search implementation, searches for `query` in `arr`
 * @param  arr  The array in which the `query` is searched for
 * @param  size The size of the array `arr`
 * @param  query  The element to search for in the array `arr`
 * @return      Returns index of `arr` at which `query` if exists is found else -1
 */
int binary_search(int *arr, int size, int query);

#endif
