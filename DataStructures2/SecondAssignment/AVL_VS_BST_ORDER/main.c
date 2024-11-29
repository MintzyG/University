#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "./include.h"

int main() {
    srand(time(NULL));

    const int ELEMENTS = 10;
    const int NUM_RANGE = 1000;
    BSTNode* bstRoot = NULL;
    AVLNode* avlRoot = NULL;

    int usedNumbers[ELEMENTS];
    memset(usedNumbers, 0, sizeof(usedNumbers));
    int count = 0;

    printf("Original Sequence of %d Unique Numbers:\n", ELEMENTS);

    while (count < ELEMENTS) {
        int randomNum = rand() % NUM_RANGE;
        
        int duplicate = 0;
        for (int i = 0; i < count; i++) {
            if (usedNumbers[i] == randomNum) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            printf("%d ", randomNum);
            bstRoot = insertBST(bstRoot, randomNum);
            avlRoot = insertAVL(avlRoot, randomNum);
            usedNumbers[count] = randomNum;
            count++;
        }
    }

    printf("\n\nBinary Search Tree Traversals:\n");
    printf("Inorder: "); inorderBST(bstRoot);
    printf("\nPreorder: "); preorderBST(bstRoot);
    printf("\nPostorder: "); postorderBST(bstRoot);

    printf("\n\nAVL Tree Traversals:\n");
    printf("Inorder: "); inorderAVL(avlRoot);
    printf("\nPreorder: "); preorderAVL(avlRoot);
    printf("\nPostorder: "); postorderAVL(avlRoot);

    return 0;
}