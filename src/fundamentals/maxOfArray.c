#include <stdio.h>
int maxOfArray(int numbers[], int size) {
  int max = numbers[0]; 

  for (int i = 1; i < size; i++) {
    if (numbers[i] > max) {
      max = numbers[i]; 
    }
  }

  return max; 

  printf("Maximum value = %d\n", max); 
  return 0; 
}

