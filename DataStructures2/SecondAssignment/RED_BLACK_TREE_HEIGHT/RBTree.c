#include <stdlib.h>
#include <stdio.h>

#include "./include.h"

RBTNode* createRBTNode(int value) {
  RBTNode* node = malloc(sizeof(RBTNode));
  node->data = value;
  node->left = node->right = NULL;
  node->color = RED;
  return node;
}

int isRed(RBTNode* node) {
  return node != NULL && node->color == RED;
}

RBTNode* rotateRBTLeft(RBTNode* h) {
  if (h == NULL || h->right == NULL) return h;
  RBTNode* x = h->right;
  h->right = x->left;
  x->left = h;
  x->color = h->color;
  h->color = RED;
  return x;
}

RBTNode* rotateRBTRight(RBTNode* h) {
  if (h == NULL || h->left == NULL) return h;
  RBTNode* x = h->left;
  h->left = x->right;
  x->right = h;
  x->color = h->color;
  h->color = RED;
  return x;
}

void flipRBTColors(RBTNode* h) {
  h->color = !h->color;
  h->left->color = !h->left->color;
  h->right->color = !h->right->color;
}

int getRBTHeight(RBTNode* node) {
  if (node == NULL) return 0;
  int left_height = getRBTHeight(node->left);
  int right_height = getRBTHeight(node->right);
  return 1 + (left_height > right_height ? left_height : right_height);
}

RBTNode* insertRBT(RBTNode* h, int value) {
  if (h == NULL) return createRBTNode(value);

  // printf("dentro do insert recursivo \n");
  if (value < h->data)
    h->left = insertRBT(h->left, value);
  else if (value > h->data)
    h->right = insertRBT(h->right, value);
  else
    return h;

  if (isRed(h->right) && !isRed(h->left))
    h = rotateRBTLeft(h);

  if (isRed(h->left) && isRed(h->left->left))
    h = rotateRBTRight(h);

  if (isRed(h->left) && isRed(h->right))
    flipRBTColors(h);

  return h;
}

void printTreeRBT(RBTNode *node, int level) {
  if (node == NULL) return;
  printTreeRBT(node->right, level + 1);
  for (int i = 0; i < level; i++) { printf("│   "); }
  printf("├── ");
  if (isRed(node)) { printf("\033[1;31m%d\033[0m\n", node->data); }
  else { printf("\033[1;90m%d\033[0m\n", node->data); }
  printTreeRBT(node->left, level + 1);
}
