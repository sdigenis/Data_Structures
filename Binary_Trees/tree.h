#ifndef __TREE_H_
#define __TREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "stack.h"
typedef struct tree  
{ 
    int data; 
    struct tree *left; 
    struct tree *right; 
}tree;

tree *addNode(int data);
void printGivenLevel(tree *root, int level);
void printLevelOrder(tree *root);
int height(tree *node);
void deallocate (tree *node);
int isBST(tree *node, int min, int max);
//tree *constructTree_post_order(int post[], int size);
tree *construct_tree_level_order(int arr[], tree *root, int i, int n);
//tree *constructTreeUtil_post_order(int post[], int* postIndex, int key, int min, int max, int size);
tree *search(tree *root, int key);
tree *constructTree_post_order(int post[], int size);
tree *constructTreeUtil_post_order(int post[], int* postIndex, int key, int min, int max, int size);
tree* constructTreeUtil_pre_order(int pre[], int* preIndex, int key, int min, int max, int size);
tree *construct_tree_pre_order(int pre[], int size);
bool getPath(tree *root, lifo *arr, int x);
void printPathBetweenNodes(tree *root, int n1, int n2, int size);
int distanceFromRoot(tree *root, int x);
int distanceBetween2(tree *root, int a, int b);
int findDistWrapper(tree *root, int a, int b);
#endif