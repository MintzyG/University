#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR " -> "

typedef struct Stack Stack;
typedef struct StackNode StackNode;

enum Options {
  ADDN = 1,
  ADDC,
  REMOVE,
  QUIT,
};

enum Type {
  INT = 1,
  CHAR,
};

struct StackNode {
  StackNode* next;
  void* data;
  enum Type type;
};

struct Stack {
  StackNode* first;
  int size;
};

StackNode* CreateStackNode() {
  StackNode* node = calloc(1, sizeof *node);
  *node = (StackNode) {
    .next = NULL,
    .data = NULL,
  };
  return node;
}

Stack* CreateStack() {
  Stack* stack = calloc(1, sizeof *stack);
  *stack = (Stack) {
    .first = NULL,
    .size = 0,
  };
  return stack;
}

void Push(Stack* stack, void* value, enum Type type) {
  stack->size += 1;
  StackNode* new = CreateStackNode();
  new->data = value;
  new->next = stack->first;
  new->type = type;
  stack->first = new;
}

void* Pop(Stack* stack) {
  if (stack->size == 0) {
    printf("---WARNING!---\n");
    printf("Stack is empty!\n");
    return 0;
  }

  stack->size -= 1;
  StackNode* first = stack->first->next;
  void* ret = stack->first->data;
  free(stack->first);
  stack->first = first;
  return ret;
}

void PrintNodeInt(StackNode* node) {
  int* data = (int*)node->data;
  printf("I[%d]", *data);
}

void PrintNodeChar(StackNode* node) {
  char* data = (char*)node->data;
  printf("C[%c]", *data);
}

void Show(Stack* stack) {
  StackNode* node = stack->first;
  printf("HEAD");
  if (stack->size == 0) {
    printf("%sNULL\n", SEPARATOR);
    return;
  }
  while (node) {
    printf(SEPARATOR);
    if (node->type == INT){
      PrintNodeInt(node);
    } else {
      PrintNodeChar(node);
    }
    node = node->next;
  }
  printf("\n");
}

int main() {
  int size = 1, option = 0;
  Stack* stack = CreateStack();

  system("clear");
  while ((enum Options)option != QUIT) {
    printf("--- STACK ---\n");
    Show(stack);
    printf("--- MENU ---\n");
    printf("1: ADD NUMBER\n2: ADD CHAR\n");
    printf("3: REMOVE\n4: QUIT\nOpcao: ");
    scanf("%d[^\n]", &option);
    scanf("%*c");

    switch((enum Options)option) {
      case ADDN:
        printf("--- What number? ---\n");
        printf("input: ");
        int* value = calloc(1, sizeof *value);
        scanf("%d[^\n]", value);
        scanf("%*c");
        Push(stack, value, INT);
        system("clear");
        break;
      case ADDC:
        printf("--- What character? ---\n");
        printf("input: ");
        char* cvalue = calloc(1, sizeof * cvalue);
        scanf("%c[^\n]", cvalue);
        scanf("%*c");
        Push(stack, cvalue, CHAR);
        system("clear");
        break;
      case REMOVE:
        system("clear");
        Pop(stack);
        break;
      case QUIT:
        break;
      default:
        continue;
    }
  }
  return 0;
}
