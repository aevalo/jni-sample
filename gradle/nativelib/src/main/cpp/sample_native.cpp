#include <ctype.h>
#include <string.h>

// Mutate array to uppercase
void uppercase(char* str) {
  size_t n = strlen(str);
  for (size_t i = 0; i < n; i++) {
    str[i] = toupper(str[i]);
  }
}

int square(int num) {
  return num * num;
}

bool invert(bool boolean) {
  return !boolean;
}

int array_sum(int array[], int len) {
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += array[i];
  }
  return sum;
}