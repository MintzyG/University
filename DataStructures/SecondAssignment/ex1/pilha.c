#include <stdio.h>
#include <stdlib.h>

#define SEPARATOR " -> "

typedef struct Stack Stack;
typedef struct StackNode StackNode;

enum Options {
  ADD = 1,
  REMOVE,
  QUIT,
};

struct StackNode {
  StackNode* next;
  int data;
};

struct Stack {
  StackNode* first;
  int size;
};

StackNode* CreateStackNode() {
  StackNode* node = calloc(1, sizeof *node);
  *node = (StackNode) {
    .next = NULL,
    .data = 0,
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

void Push(Stack* stack, int value) {
  stack->size += 1;
  StackNode* new = CreateStackNode();
  new->data = value;
  new->next = stack->first;
  stack->first = new;
}

void Pop(Stack* stack) {
  if (stack->size == 0) {
    printf("---WARNING!---\n");
    printf("Stack is empty!\n");
    return;
  }

  stack->size -= 1;
  StackNode* first = stack->first->next;
  free(stack->first);
  stack->first = first;
}

void PrintNode(StackNode* node) {
  int data = node->data;
  printf("[%d]", data);
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
    PrintNode(node);
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
        Push(stack, value);
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
