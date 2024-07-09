#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEPARATOR " -> "

typedef struct Stack Stack;
typedef struct StackNode StackNode;

enum Options {
  ADD = 1,
  REMOVE,
  QUIT,
};

void Realloc(int* stack, int* size) {
  int* tmp = (int*)calloc((*size) * 2, sizeof *tmp);
  memcpy(tmp, stack, (*size) * sizeof *tmp);
  stack = tmp;
  (*size) *= 2;
}

void Push(int* stack, int* size, int* position, int value) {
  if (*position == *size) Realloc(stack, size);

  stack[*position] = value;
  *position += 1;
}

void Show(int* stack, int *position) {
  printf("HEAD");
  if (*position <= 0) {
    *position = 0;
    printf("%sNULL\n", SEPARATOR);
    return;
  }
  for(int i = *position - 1; i >= 0; i--){
    printf(SEPARATOR);
    printf("[%d]", stack[i]);
  }
  printf("\n");
}

int main() {
  int size = 1, option = 0, position = 0;
  int* stack = calloc(size, sizeof(int));

  system("clear");
  while ((enum Options)option != QUIT) {
    printf("--- STACK ---\n");
    Show(stack, &position);
    printf("--- MENU ---\n");
    printf("1: ADD\n2: REMOVE\n");
    printf("3: QUIT\nOpcao: ");
    scanf("%d[^\n]", &option);
    scanf("%*c");

    switch((enum Options)option) {
      case ADD:
        printf("--- What number? ---\n");
        printf("input: ");
        int value = 0;
        scanf("%d[^\n]", &value);
        scanf("%*c");
        Push(stack, &size, &position, value);
        system("clear");
        break;
      case REMOVE:
        system("clear");
        position -= 1;
        if (position == -1){
          printf("--- WARNING! ---\n");
          printf("Stack is empty!\n");
        }
        break;
      case QUIT:
        break;
      default:
        continue;
    }
  }
  return 0;
}
