#pragma once

#include "polynomial.h"

typedef struct Polynomials Polynomials;
typedef struct PolyNode PolyNode;

enum Menu {
  CREATE = 1,
  LIST_ADD,
  LIST_RM,
  SUM,
  QUIT,
};

struct PolyNode {
  PolyNode* next;
  Head* polynomial;
};

struct Polynomials {
  PolyNode* first;
  int size;
};

PolyNode* CreatePolyNode();
Polynomials* CreatePoly();
void ShowList(Polynomials*);
void PushPoly(Polynomials*, Head*);
void PopList(Polynomials*, int);
void PopPoly(Polynomials*);
Head* FetchPoly(Polynomials*, int);
Head* SumPoly(Polynomials*);
