#pragma once

/* Genereal Definitions */

#define NUM_ELEMENTS 10000
#define ELEMENT_RANGE 100000
#define ELEMENT_RANGE_PRINT 100
#define RED 1
#define BLACK 0

/* AVL Definitions */

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

int max(int, int);
int getAVLHeight(AVLNode*);
int getBalanceFactor(AVLNode*);

AVLNode* createAVLNode(int);
AVLNode* rightRotate(AVLNode*);
AVLNode* leftRotate(AVLNode*);
AVLNode* insertAVL(AVLNode*, int);

void inorderAVL(AVLNode*);
void preorderAVL(AVLNode*);
void postorderAVL(AVLNode*);

void printTreeAVL(AVLNode *node, int level);

/* BST Definitions */

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* createBSTNode(int);
BSTNode* insertBST(BSTNode*, int);
int getBSTHeight(BSTNode*);

void inorderBST(BSTNode*);
void preorderBST(BSTNode*);
void postorderBST(BSTNode*);

void printTreeBST(BSTNode *node, int level);

/* RBT Definitions */

typedef struct RBTNode {
    int data;
    struct RBTNode *left, *right;
    int color;
} RBTNode;

RBTNode* createRBTNode(int value);
RBTNode* insertRBT(RBTNode* h, int value);
int getRBTHeight(RBTNode* node);

RBTNode* rotateRBTLeft(RBTNode* h);
RBTNode* rotateRBTRight(RBTNode* h);

int isRed(RBTNode* node);
void flipRBTColors(RBTNode* h);

void printTreeRBT(RBTNode *node, int level);