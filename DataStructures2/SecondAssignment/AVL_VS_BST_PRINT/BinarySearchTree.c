#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./include.h"

BSTNode* createBSTNode(int value) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BSTNode* insertBST(BSTNode* root, int value) {
    if (root == NULL) return createBSTNode(value);
    
    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);
    
    return root;
}

int getBSTHeight(BSTNode* root) {
    if (root == NULL) return 0;
    
    int leftHeight = getBSTHeight(root->left);
    int rightHeight = getBSTHeight(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void inorderBST(BSTNode* root) {
    if (root != NULL) {
        inorderBST(root->left);
        printf("%d ", root->data);
        inorderBST(root->right);
    }
}

void preorderBST(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderBST(root->left);
        preorderBST(root->right);
    }
}

void postorderBST(BSTNode* root) {
    if (root != NULL) {
        postorderBST(root->left);
        postorderBST(root->right);
        printf("%d ", root->data);
    }
}

void printTreeBST(BSTNode *node, int level) {
    if (node == NULL) return;
    printTreeBST(node->right, level + 1);
    for (int i = 0; i < level; i++) { printf("    "); }
    printf("%d (%d)\n", level, node->data);
    printTreeBST(node->left, level + 1);
}