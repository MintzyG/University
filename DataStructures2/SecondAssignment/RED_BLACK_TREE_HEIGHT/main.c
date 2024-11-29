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
    for (int i = 0; i < 12; i++)
        rootRBT = insertRBT(rootRBT, rand() % 100);

    int height = getRBTHeight(rootRBT);
    printf("Altura da arvore Rubro-Negra: %d\n\n", height);
    printTreeRBT(rootRBT, 1);
    #endif
    
    return 0;
}