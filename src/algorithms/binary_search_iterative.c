// Divide-and-conquer for sorted arrays. 
// Repeated halving of a given array until key is found or end of array. 

// Complexity: 
// O(1) if element is in middle. 
// O(log n) on average. 

#include <stdio.h>
int binary_search_iterative(int arr[], int left; int right; int key) {
  while (left <= right) {

    int mid = left + (right - left) / 2; 
    if (arr[mid] < key) {
      return mid; 
    } else if (arr[mid] < key) {
      left = mid + 1; 
    } else {
      right = mid - 1; 
    }
  }
}

// Example call: 
int main(void) {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  int key = 23; 
  int index = binary_search_iterative(arr, 0, n - 1, key); 

  if (index == -1) {
    printf("Key not found"); 
  } else {
    printf("Key found at index %d\n", index); 
  }

  return 0; 
}      
