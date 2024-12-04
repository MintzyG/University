#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./include.h"

int main() {
  srand(time(NULL));
  RBTNode* rootRBT = NULL;

#ifdef RAND
  for (int i = 0; i < NUM_ELEMENTS; i++)
    rootRBT = insertRBT(rootRBT, rand() % ELEMENT_RANGE);

  int height = getRBTHeight(rootRBT);
  printf("Altura da Arvore Rubro-Negra: %d\n\n", height);
#else
  // int values[] = {10, 20, 5, 15, 30, 3, 7, 24, 35, 10, 9, 22};
  for (int i = 0; i < 12; i++) {
    // rootRBT = insertRBT(rootRBT, values[i]);
    rootRBT = insertRBT(rootRBT, rand() % 100);
    rootRBT->color = BLACK;
    // printf("### Inserindo %d ###\n", values[i]);
    // printTreeRBT(rootRBT, 0);
  }
  int height = getRBTHeight(rootRBT);
  printf("Altura da arvore Rubro-Negra: %d\n\n", height);
  printTreeRBT(rootRBT, 0);

#endif

  return 0;
}
