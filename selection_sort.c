#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selection_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int min_index = i;
    int min_val = arr[min_index];
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < min_val) {
        min_index = j;
        min_val = arr[j];
      }
    }
    swap(&arr[i], &arr[min_index]);
  }
}

void print_int_array(int *s, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", s[i]);
  }
  puts("");
}

int main(int argc, char const *argv[]) {
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  print_int_array(arr, n);
  selection_sort(arr, n);
  print_int_array(arr, n);
  return 0;
};
