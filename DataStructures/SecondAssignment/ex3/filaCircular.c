#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define SEPARATOR " -> "

enum Options {
  ADD = 1,
  REMOVE,
  QUIT,
};

void ShowVector(int* fila, int amount) {
  printf("LOOP%s", SEPARATOR);
  for (int i = 0; i < SIZE; i++) {
    printf("[%d]%s", fila[i], SEPARATOR);
  }
  printf("LOOP\n");
}

void Show(int* fila, int amount, int start) {
  if(amount == 0) {
    printf("OLDEST%sYOUNGEST\n", SEPARATOR);
    return;
  }
  printf("OLDEST%s", SEPARATOR);
  for (int i = start; i < start + amount; i++) {
    printf("[%d]%s", fila[i % SIZE], SEPARATOR);
  }
  printf("YOUNGEST\n");
}

void Push(int* fila, int* amount, int* start, int value) {
  if (*amount == 5) {
    printf("--- WARNING! ---\n");
    printf("A fila esta cheia!\n");
    return;
  }
  fila[(*start + *amount) % SIZE] = value;
  *amount += 1;
}

int Pop(int* fila, int* amount, int* start) {
  if (*amount == 0) {
    printf("--- WARNING! ---\n");
    printf("A fila esta vazia!\n");
    return INT32_MAX;
  }
  *amount -= 1;
  int number = fila[*start];
  *start = (*start + 1) % SIZE;
  return number;
}

int main() {
  int fila[SIZE] = {0};
  int amount = 0, start = 0;
  int option = 0;

  system("clear");
  while ((enum Options)option != QUIT) {
    printf("--- VECTOR ---\n");
    ShowVector(fila, amount);
    printf("--- LIST ---\n");
    Show(fila, amount, start);
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
        system("clear");
        Push(fila, &amount, &start, value);
        break;
      case REMOVE:
        system("clear");
        int number = Pop(fila, &amount, &start);
        if (number != INT32_MAX) {
          printf("--- Popped ---\n");
          printf("POP%s[%d]\n", SEPARATOR, number);
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
