#include <stdio.h>
#include <stdlib.h>

#include "list.h"

PolyNode* CreatePolyNode() {
  PolyNode* head = calloc(1, sizeof *head);
  *head = (PolyNode) {
    .next = NULL,
    .polynomial = NULL,
  };
  return head;
}

Polynomials* CreatePoly() {
  Polynomials* head = calloc(1, sizeof *head);
  *head = (Polynomials) {
    .first = NULL,
    .size = 0,
  };
  return head;
}

void ShowList(Polynomials* list) {
  PolyNode* node = CreatePolyNode();
  node = list->first;
  int counter = 0;
  while (node) {
    counter += 1;
    printf("%d: ", counter);
    ShowPoly(node->polynomial);
    node = node->next;
  }
}

void PushPoly(Polynomials* list, Head* poly) {
  if (!poly || !poly->first) {
    return;
  }

  PolyNode* node = CreatePolyNode();
  if (!list->first) {
    node->polynomial = poly;
    list->first = node;
    list->size += 1;
    return;
  }

  node->polynomial = poly;
  node->next = list->first;
  list->first = node;
  list->size += 1;
}

void PopList(Polynomials* list, int pos) {
  PolyNode* node = CreatePolyNode();
  PolyNode* last;
  node = list->first;

  if (pos >= list->size) {
    printf("--- WARNING! ---\n");
    printf("Tried removing outside bounds of list!\n");
    return;
  }

  if (pos == 0) {
    list->first = node->next;
    free(node);
    list->size -= 1;
    return;
  }

  for (int i = pos; i > 0; i--) {
    last = node;
    node = node->next;
  }

  if(!node->next) {
    last->next = NULL;
    free(node);
    list->size -= 1;
    return;
  }

  last->next = node->next;
  free(node);
  list->size -= 1;
}

void PopPoly(Polynomials* list) {
  printf("--- List ---\n");
  ShowList(list);
  printf("--- What poly to remove? ---\n");
  printf("input: ");
  int value = 0;
  scanf("%d[^\n]", &value);
  scanf("%*c");
  if (value <= 0) {
    printf("--- WARNING! ---\n");
    printf("Invalid Polynomial\n");
    return;
  }
  PopList(list, value - 1);
}

Head* FetchPoly(Polynomials* list, int pos) {
  PolyNode* node = CreatePolyNode();
  node = list->first;

  for (int i = pos; i > 0; i--) {
    node = node->next;
  }

  return node->polynomial;
}


Head* SumPoly(Polynomials* list) {
  if (!list->first) {
    return NULL;
  }

  int first = 0, second = 0;
  while (first <=0 || first > list->size) {
    printf("--- Choose the first polynomial ---\n");
    printf("input: ");
    scanf("%d[^\n]", &first);
    scanf("%*c");
  }
  while (second <=0 || second > list->size) {
    printf("--- Choose the second polynomial ---\n");
    printf("input: ");
    scanf("%d[^\n]", &second);
    scanf("%*c");
  }

  Head* firstPoly = FetchPoly(list, first - 1);
  Head* secondPoly = FetchPoly(list, second - 1);
  Head* result = CreateList();
  Node* firstNode = firstPoly->first;
  Node* secondNode = secondPoly->first;
  int resValue;

  while(firstNode && secondNode) {
    if (firstNode->exponent == secondNode->exponent && firstNode && secondNode) {
      resValue = firstNode->value + secondNode->value;
      if (resValue < 0) {
        Push(result, resValue, firstNode->exponent, '-');
      } else {
        Push(result, resValue, firstNode->exponent, '+');
      }
      firstNode = firstNode->next;
      secondNode = secondNode->next;
    } else if (firstNode->exponent > secondNode->exponent) {
      Push(result, firstNode->value, firstNode->exponent, firstNode->sign);
      firstNode = firstNode->next;
    } else {
      Push(result, secondNode->value, secondNode->exponent, secondNode->sign);
      secondNode = secondNode->next;
    }
  }

  if (firstNode == NULL) {
    while (secondNode) {
      Push(result, secondNode->value, secondNode->exponent, secondNode->sign);
      secondNode = secondNode->next;
    }
  } else if (secondNode == NULL) {
    while (firstNode) {
      Push(result, firstNode->value, firstNode->exponent, firstNode->sign);
      firstNode = firstNode->next;
    }
  }
  return result;
}
