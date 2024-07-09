#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

Node* CreateNode() {
  Node* node = calloc(1, sizeof *node);
  *node = (Node) {
    .next = NULL,
    .value = 0,
    .exponent = 0,
    .sign = 'N',
  };
  return node;
}

Head* CreateList() {
  Head* head = calloc(1, sizeof *head);
  *head = (Head) {
    .first = NULL,
  };
  return head;
}

void ShowNode(Node* node) {
  if (node->value == 1 || node->value == -1) {
    if (node->exponent == 0) {
      printf("%c %d ", node->sign, abs(node->value));
    } else if (node->exponent == 1) {
      printf("%c x ", node->sign);
    } else {
      printf("%c x^%d ", node->sign, node->exponent);
    }
    return;
  }

  if (node->exponent == 0) {
    printf("%c %d ", node->sign, abs(node->value));
  } else if (node->exponent == 1) {
    printf("%c %dx ", node->sign, abs(node->value));
  } else {
    printf("%c %dx^%d ", node->sign, abs(node->value), node->exponent);
  }
}

void ShowPoly(Head* list) {
  if (!list) {
    return;
  }
  Node* first = list->first;
  while(first) {
    ShowNode(first);
    first = first->next;
  }
  Node* node = list->first;
  if (node) {
    printf("= 0\n");
  } else {
    printf("\n");
  }
}

void Push(Head* head, int value, int exponent, char sign) {
  Node* new = CreateNode();
  new->value = value;
  new->exponent = exponent;
  new->sign = sign;
  if (head->first == NULL) {
    head->first = new;
    return;
  }

  Node* node = head->first;
  Node* last = head->first;
  while (new->exponent < node->exponent && node) {
    last = node;
    if (node->next == NULL) {
      node = NULL;
      break;
    }
    node = node->next;
  }

  if (!node) {
    last->next = new;
    return;
  }

  if (new->exponent == node->exponent) {
    node->value = new->value;
    node->sign = new->sign;
    return;
  }

  if (node == last) {
    new->next = head->first;
    head->first = new;
    return;
  }

  new->next = node;
  last->next = new;
}

void Pop(Head* head) {
  if (head->first == NULL) {
    printf("--- WARNING! ---\n");
    printf("List is empty!\n");
    return;
  }

  Node* node = head->first;
  while(node->next->next) {
    node = node->next;
  }
  node->next = NULL;
}

void AddPart(Head* list) {
  printf("--- What number? ---\n");
  printf("input: ");
  int value = 0;
  char sign;
  scanf("%d[^\n]", &value);
  scanf("%*c");
  if (value == 0) return;
  if (value < 0) {
    sign = '-';
  } else {
    sign = '+';
  }
  printf("--- What exponent? ---\n");
  printf("input: ");
  int exponent = 0;
  scanf("%d[^\n]", &exponent);
  scanf("%*c");
  Push(list, value, exponent, sign);
}

void CreatePolynomial(Head* polynomial) {
  system("clear");
  int option = 0;
  while ((enum Options)option != DONE) {
    printf("--- POLYNOMIAL ---\n");
    ShowPoly(polynomial);
    printf("--- MENU ---\n");
    printf("1: ADD\n2: REMOVE\n");
    printf("3: DONE\nOpcao: ");
    scanf("%d[^\n]", &option);
    scanf("%*c");

    switch((enum Options)option) {
      case ADD:
        AddPart(polynomial);
        system("clear");
        break;
      case REMOVE:
        system("clear");
        Pop(polynomial);
        break;
      case DONE:
        break;
      default:
        continue;
    }
  }
}
