#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./include.h"

int main() {
    srand(time(NULL));
    AVLNode* avlRoot = NULL;
    BSTNode* bstRoot = NULL;

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int randomNum = rand() % ELEMENT_RANGE + 1;
        avlRoot = insertAVL(avlRoot, randomNum);
        bstRoot = insertBST(bstRoot, randomNum);
    }

    printf("AVL Tree Height: %d\n", avlRoot->height);
    printf("Binary Search Tree Height: %d\n", getBSTHeight(bstRoot));

    return 0;
}