#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEPARATOR " -> "

typedef struct Head Head;
typedef struct Node Node;

enum Options {
  ADD = 1,
  REMOVE,
  QUIT,
};

struct Node {
  Node* next;
  int data;
};

struct Head {
  Node* first;
  // Node* last;
  int size;
};

Node* CreateNode() {
  Node* node = calloc(1, sizeof *node);
  *node = (Node) {
    .next = NULL,
    .data = 0,
  };
  return node;
}

Head* CreateList() {
  Head* head = calloc(1, sizeof *head);
  *head = (Head) {
    .first = NULL,
    .size = 0,
  };
  return head;
}

void ShowNode(Node* node) {
  printf("[%d]%s", node->data, SEPARATOR);
}

void Show(Head* list) {
  Node* first = list->first;
  printf("HEAD%s", SEPARATOR);
  while(first) {
    ShowNode(first);
    first = first->next;
  }
  printf("NULL\n");
}

void Push(Head* head, int value) {
  Node* new = CreateNode();
  new->next = head->first;
  new->data = value;
  head->first = new;
  head->size += 1;
}

void Pop(Head* head) {
  if (head->size == 0) {
    printf("--- WARNING! ---\n");
    printf("List is empty!\n");
    return;
  } else if (head->size == 1) {
    head->first = NULL;
    head->size -= 1;
    return;
  }
  Node* node = head->first;
  while(node->next->next) {
    node = node->next;
  }
  node->next = NULL;
  head->size -= 1;
}

int main() {
  int option = 0;
  Head* list = CreateList();

  system("clear");
  while ((enum Options)option != QUIT) {
    printf("--- LIST ---\n");
    Show(list);
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
        Push(list, value);
        system("clear");
        break;
      case REMOVE:
        system("clear");
        Pop(list);
        break;
      case QUIT:
        break;
      default:
        continue;
    }
  }
  return 0;
}
