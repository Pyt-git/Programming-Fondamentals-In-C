// Number of elements in an array = total size of array (in bytes) / size of one element (in bytes). 
// Linear search scans the array. 
// O(1) if element is at the beginning. 
// O(n) if necessary to scan entire array or on average. 

#include <stdio.h>
int linear_search(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {

    if (arr[i] == key) {
      return i; 
    }
  }
  return -1; 
}

// Example call:
int main(void) {
  int arr[] = {10, 50, 30, 70, 90}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  int key = 30; 
  int index = linear_search(arr, n, key); 

  if (index == -1) {
    printf("Key not found"); 
  } else {
    printf("Key found at index %d\n", index); 
  }
}
