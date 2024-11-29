#pragma once

typedef struct Node Node;
typedef struct Head Head;

enum Options {
  ADD = 1,
  REMOVE,
  DONE,
};

struct Node {
  Node* next;
  int value;
  int exponent;
  char sign;
};

struct Head {
  Node* first;
};

Node* CreateNode();
Head* CreateList();
void ShowNode(Node*);
void ShowPoly(Head*);
void Push(Head*, int, int, char);
void Pop(Head*);
void AddPart(Head*);
void CreatePolynomial(Head*);
