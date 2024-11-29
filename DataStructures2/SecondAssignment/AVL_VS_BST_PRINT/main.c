#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./include.h"

int main() {
    srand(time(NULL));
    AVLNode *rootAVL = NULL;
    BSTNode *rootBST = NULL;
    
    #ifdef PREDEFINED
        rootAVL = insertAVL(rootAVL, 70); rootBST = insertBST(rootBST, 70);
        rootAVL = insertAVL(rootAVL, 60); rootBST = insertBST(rootBST, 60);
        rootAVL = insertAVL(rootAVL, 80); rootBST = insertBST(rootBST, 80);
        rootAVL = insertAVL(rootAVL, 50); rootBST = insertBST(rootBST, 50);
        rootAVL = insertAVL(rootAVL, 65); rootBST = insertBST(rootBST, 65);
        rootAVL = insertAVL(rootAVL, 75); rootBST = insertBST(rootBST, 75);
        rootAVL = insertAVL(rootAVL, 35); rootBST = insertBST(rootBST, 35);
        rootAVL = insertAVL(rootAVL, 145); rootBST = insertBST(rootBST, 145);
        rootAVL = insertAVL(rootAVL, 245); rootBST = insertBST(rootBST, 245);
        rootAVL = insertAVL(rootAVL, 55); rootBST = insertBST(rootBST, 55);
        rootAVL = insertAVL(rootAVL, 25); rootBST = insertBST(rootBST, 25);
        rootAVL = insertAVL(rootAVL, 44); rootBST = insertBST(rootBST, 44);
    #else
        for (int i = 0; i < 12; i++) {
            int rand_num = rand() % ELEMENT_RANGE_PRINT;
            rootAVL = insertAVL(rootAVL, rand_num);
            rootBST = insertBST(rootBST, rand_num);
        }
    #endif

    printf("AVL:\n");
    printTreeAVL(rootAVL, 1);

    printf("\n\n\n");
    
    printf("BST:\n");
    printTreeBST(rootBST, 1);

    return 0;
}