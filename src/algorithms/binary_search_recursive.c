// Complexity: 
// O(log n) on average / worst case.
// O(1) if key is in the middle; 
// O(log n) space complexity;
// Risk of stack overflow if array size is substential. 

#include <stdio.h>

int binary_search_recursive(int arr[], int left, int right, int key) {
  if (left > right) {
    return -1; 
  }

  int mid = left + (right - left) / 2; 
  if (arr[mid] == key) {
    return mid; 
  } else if (arr[mid] < key) {
    return binary_search_recursive(arr, mid + 1, right, key); 
  } else {
    return binary_search_recursive(arr, left, mid - 1, key); 
  }
}

// Example call: 
int main(void) {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  int key = 72; 
  int index = binary_search_recursive(arr, 0, n - 1, key); 

  if (index == -1) {
    printf("Key not found"); 
  } else {
    printf("Key found at index %d\n", index); 
  }
}
