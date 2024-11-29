#pragma once

#define MAX_TEXT 256
#define MAX_SUB 20

typedef struct Sub Sub;

struct Sub {
  int* ocurrences;
  int size, capacity;
};

void PrintArray(int*, int*);
int* substrings(char*, char*, int*);
int* getSub(char*, char*, char*, Sub*, int*);
void ReallocSub(Sub*);
Sub* CreateSub();
void GetInput(char*, int);
