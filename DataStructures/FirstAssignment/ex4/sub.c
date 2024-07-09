#include "sub.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Sub* CreateSub() {
  Sub* S = calloc(1, sizeof *S);
  *S = (Sub) {
    .ocurrences = calloc(1, 4),
    .size = 1,
    .capacity = 1,
  };
  return S;
}

void ReallocSub(Sub* self) {
  int* tmp = (int*)calloc(self->size * 2, sizeof *tmp);
  memcpy(tmp, self->ocurrences, self->size * sizeof *tmp);
  self->ocurrences = tmp;
  self->size *= 2;
  self->capacity = self->size / 2;
}

int* getSub(char* t, char* r, char* s, Sub* S, int* counter) {
    r = strstr(r, s);
    if (!r) { return S->ocurrences; }

    if (S->capacity == 0) { ReallocSub(S); }
    S->ocurrences[S->size - S->capacity] = r - t;
    S->capacity -= 1;
    (*counter)++;

    r += strlen(s);
    getSub(t, r, s, S, counter);
    return S->ocurrences;
}

int* substrings(char* texto, char* substring, int* counter) {
  Sub* S = CreateSub();
  char* finds = texto;
  int* pos = getSub(texto, finds, substring, S, counter);
  return pos;
}

void GetInput(char* name, int MAX_NAME_SZ) {
    fgets(name, MAX_NAME_SZ, stdin);
    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
        name[strlen (name) - 1] = '\0';
}

void PrintArray(int* counter, int* positions) {
  for (int i = 0; i < *counter; i++) {
    printf("%d ", i[positions]);
  }
}
