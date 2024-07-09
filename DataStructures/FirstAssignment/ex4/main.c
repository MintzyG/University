#include "sub.h"
#include <stdlib.h>

int main() {
  char* texto = calloc(MAX_TEXT, 1);
  char* substring = calloc(MAX_SUB, 1);
  int* counter = calloc(1, sizeof *counter);

  GetInput(texto, MAX_TEXT);
  GetInput(substring, MAX_SUB);
 
  int* positions = substrings(texto, substring, counter);
  PrintArray(counter, positions);

  return 0;
}
