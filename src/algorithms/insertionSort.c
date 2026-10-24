// Insertion sort compares current element (key) with all elements before. 
// Larger elements shift one position to the right. 
// Key inserted into correct position. 

// Complexity analysis: 
// Best case (i.e., sorted array): O(n). 
// Average runtime: O(n^2). 
// Worst case (i.e., reverse-sorted array): O(n^2). 
// Worst case: each element is compared with all elements before it. 

#include <stdio.h>

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i]; 
    int j = i - 1; 

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j]; 
    }
    arr[j + 1] = key; 
  }
}

// Example call:
int main() {
  int arr[] = {12, 11, 13, 5, 6}; 
  int n = sizeof(arr) / sizeof(arr[0]); 

  insertionSort(arr, n); 
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]); 
  }
  return 0; 
}
