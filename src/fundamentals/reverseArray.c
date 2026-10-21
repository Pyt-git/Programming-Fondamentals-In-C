#include <stdio.h>

int reverseArray(int[] numbers, int size) {

  int temp; 
  for (int i = 0; i < size / 2; i++) {
    temp = numbers[i]; 
    numbers[i] = numbers[size - 1 - i]; 
    numbers[size - 1 - i] = temp; 
  }

  return temp; 
}
