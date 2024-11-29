#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./include.h"

int max(int a, int b) { return (a > b) ? a : b; }
int height(AVLNode* node) { return node ? node->height : 0; }
int getBalanceFactor(AVLNode* node) { return node ? height(node->left) - height(node->right) : 0; }

AVLNode* createAVLNode(int value) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

AVLNode* rightRotate(AVLNode* unbalancedNode) {
    AVLNode* leftChild = unbalancedNode->left;
    AVLNode* subtreeToReattach = leftChild->right;

    leftChild->right = unbalancedNode;
    unbalancedNode->left = subtreeToReattach;

    unbalancedNode->height = 1 + max(height(unbalancedNode->left), height(unbalancedNode->right));
    leftChild->height = 1 + max(height(leftChild->left), height(leftChild->right));

    return leftChild;
}

AVLNode* leftRotate(AVLNode* unbalancedNode) {
    AVLNode* rightChild = unbalancedNode->right;
    AVLNode* subtreeToReattach = rightChild->left;

    rightChild->left = unbalancedNode;
    unbalancedNode->right = subtreeToReattach;

    unbalancedNode->height = 1 + max(height(unbalancedNode->left), height(unbalancedNode->right));
    rightChild->height = 1 + max(height(rightChild->left), height(rightChild->right));

    return rightChild;
}

AVLNode* insertAVL(AVLNode* node, int value) {
    if (node == NULL) return createAVLNode(value);

    if (value < node->data)
        node->left = insertAVL(node->left, value);
    else if (value > node->data)
        node->right = insertAVL(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorderAVL(AVLNode* root) {
    if (root != NULL) {
        inorderAVL(root->left);
        printf("%d ", root->data);
        inorderAVL(root->right);
    }
}

void preorderAVL(AVLNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderAVL(root->left);
        preorderAVL(root->right);
    }
}

void postorderAVL(AVLNode* root) {
    if (root != NULL) {
        postorderAVL(root->left);
        postorderAVL(root->right);
        printf("%d ", root->data);
    }
}
