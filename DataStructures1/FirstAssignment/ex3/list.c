#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void GetInput(char* name) {
    fgets(name, 40, stdin);
    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
        name[strlen (name) - 1] = '\0';
}

void CreateNode(Head* H) {
  char* name = calloc(40, 1);
  int n;
  float f;

  printf("What is the student name: ");
  GetInput(name);

  printf("What is the student ID: ");
  scanf("%d[^\n]", &n);
  scanf("%*c");

  printf("What is the student CR: ");
  scanf("%f[^\n]", &f);
  scanf("%*c");

  List* L = calloc(1, sizeof *L);
  L->next = H->first;
  H->first = L;
  H->first->ID = n;
  H->first->CR = f;
  H->first->Name = name;
  H->amount += 1;
  // printf("H: ID %d, CR %f, Name %s\n", H->first->ID, H->first->CR, H->first->Name);
  return;
}

void PrintNode(List* L) {
  if (L == NULL) { puts("No student"); return; }
  printf("(%s) ID: %d, CR: %f\n",L->Name, L->ID, L->CR);
}

void PrintAll(Head* H) {
  List* L = H->first;
  while(L) {
    PrintNode(L);
    puts("");
    L = L->next;
  }
}

void FindUser(Head* H) {
  int ID = 0;
  printf("What is the student ID: ");
  scanf("%d[^\n]", &ID);
  scanf("%*c");

  List* L = H->first;

  while(L) {
    if (L->ID == ID) break;
    L = L->next;
  }

  if (L != NULL) PrintNode(L);
  else puts("Couldn't find user");
}

//FIXME: Se nao tiver estudantes na lista o progama da SIGSEGV
void DeleteNode(Head* H) {

  PrintAll(H);

  int ID = 0;
  printf("What is the student ID: ");
  scanf("%d[^\n]", &ID);
  scanf("%*c");

  List* Current = H->first;
  List* Last = NULL;

  while(Current->next) {
    if (Current->ID == ID) {
      printf("BROKE AT %d\n--------------------\n", Current->ID);
      break;
    }
    Last = Current;
    puts("LAST IS CURRENT");
    Current = Current->next;
  }

  if (Current == H->first) {
    H->first = Current->next;
    free(Current);
    return;
  } else if (Current != NULL && Current->next != NULL) {
    Last->next = Current->next;
    free(Current);
    return;
  } else {
    Last->next = NULL;
    free(Current);
    return;
  }
  puts("Couldn't find user");
}

int CompareNode(Head* H) {
  int IDA = -1, IDB = -1;
  printf("What is the first student ID: ");
  scanf("%d[^\n]", &IDA);
  scanf("%*c");
  printf("What is the second student ID: ");
  scanf("%d[^\n]", &IDB);
  scanf("%*c");

  List* StA = H->first;
  List* StB = H->first;

  printf("IDA:%d\nIDB:%d\n", IDA, IDB);

  puts("Searching A");
  while(StA) {
    if (StA->ID != IDA) {
      StA = StA->next;
    } else {
      //IDA = StA->ID;
      break;
    }
  }
  puts("Searching B");
  while(StB) {
    if (StB->ID != IDB) {
      StB = StB->next;
    } else {
      IDB = StB->ID;
      break;
    }
  }

  PrintNode(StA);
  PrintNode(StB);

  if (StA->CR > StB->CR) {
    printf("%s is better than %s by %f\n", StA->Name, StB->Name, StA->CR - StB->CR);
    return 1;
  } else if (StA->CR < StB->CR) {
    printf("%s is better than %s by %f\n", StB->Name, StA->Name, StB->CR - StA->CR);
    return -1;
  } else {
    printf("%s and %s are just as good\n", StA->Name, StB->Name);
    return 0;
  }
}

Head* CreateHead() {
  Head* H = calloc(1, sizeof *H);
  *H = (Head) {
    .first = NULL,
    .amount = 0,
    .CreateNode = CreateNode,
    .DeleteNode = DeleteNode,
    .PrintNode = PrintNode,
    .PrintAll = PrintAll,
    .FindUser = FindUser,
    .CompareNode = CompareNode,
  };
  return H;
}
