// Divide-and-Conquer:
// Merge sort splits array into halves.
// Recursively sort each half. 
// Merge two sorted halves into one sorted array. 

// Limitation: heavy use of memory due to temporary arrays. 

// Complexity analysis: 
// Stable at O(nlogn) for all cases. 
// Space complexity: O(n) - temporary arrays. 

#include <stdio.h>

void merge(int arr[], int left, int middle, int right) {
  int size1 = middle - left + 1; 
  int size2 = right - middle; 
  int L[n1], R[n2]; // temporary arrays

  for (int i = 0; i < size1; i++) {
    L[i] = arr[left + i]; 
  }
  
  for (int j = 0; j < size2; j++) {
    R[j] = arr[m + 1 + j]; 
  }
  
  int i = 0, j = 0, k = left; 
  while (i < size1 && j < size2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i]; 
      i++;
    } else {
      arr[k] = R[j]; 
      j++; 
    }
    k++;
  }

  while (i < size1) {
    arr[k] = L[i]; 
    i++; 
    k++; 
  }

  while (j < size2) {
    arr[k] = R[j]; 
    j++; 
    k++; 
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2; 

    mergeSort(arr, left, middle); 
    mergeSort(arr, middle + 1, right); 

    merge(arr, left, middle, right); 
  }
}

// example call:
int main() {
  int arr[] = {12, 11, 13, 5, 6, 7}; 
  int n = sizeof(arr) / sizeof(arr[0]); 

  mergeSort(arr, 0, n - 1); 

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]); 
  }

  return 0; 
}    
