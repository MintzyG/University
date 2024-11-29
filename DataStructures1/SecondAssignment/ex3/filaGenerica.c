#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEPARATOR " -> "

typedef struct Head Head;
typedef struct Node Node;

enum Options {
  ADDINT = 1,
  ADDCHAR,
  REMOVE,
  QUIT,
};

enum Type {
  INT = 1,
  CHAR,
};

struct Node {
  Node* next;
  void* data;
  enum Type type;
};

struct Head {
  Node* first;
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

void ShowNodeInt(Node* node) {
  int* numero = node->data;
  printf("I[%d]%s", *numero, SEPARATOR);
}

void ShowNodeChar(Node* node) {
  char* letra = node->data;
  printf("C[%c]%s", *letra, SEPARATOR);
}

void Show(Head* list) {
  Node* first = list->first;
  printf("HEAD%s", SEPARATOR);
  while(first) {
    if (first->type == INT) {
      ShowNodeInt(first);
    } else {
      ShowNodeChar(first);
    }
    first = first->next;
  }
  printf("NULL\n");
}

void Push(Head* head, void* value, enum Type type) {
  Node* new = CreateNode();
  new->next = head->first;
  new->data = value;
  new->type = type;
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
    printf("--- INT LIST ---\n");
    Show(list);
    printf("--- MENU ---\n");
    printf("1: ADD INT\n2: ADD CHAR\n");
    printf("3: REMOVE\n4: QUIT\nOpcao: ");
    scanf("%d[^\n]", &option);
    scanf("%*c");

    switch((enum Options)option) {
      case ADDINT:
        printf("--- What number? ---\n");
        printf("input: ");
        int* value = calloc(1, sizeof *value);
        scanf("%d[^\n]", value);
        scanf("%*c");
        Push(list, value, INT);
        system("clear");
        break;
      case ADDCHAR:
        printf("--- What character? ---\n");
        printf("input: ");
        char* cvalue = calloc(1, sizeof *cvalue);
        scanf("%c[^\n]", cvalue);
        scanf("%*c");
        Push(list, cvalue, CHAR);
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
