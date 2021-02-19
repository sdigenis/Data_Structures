#include "tree.h"
#include <math.h>

int getBalance(tree *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

tree *rightRotate(tree *y) 
{ 
    tree *x;
    x = y->left; 
    tree *T2;
    T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 

tree *leftRotate(tree *x) 
{ 
    tree *y;
    y = x->right; 
    tree *T2;
    T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 

tree *insert(tree *node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(addNode(key)); 
  
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->data) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->data) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->data) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->data) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

int main(int argc, char *argv[]){

    int i, number, size;
    char *input = (char*)malloc(sizeof(char));
    int diff_order[1000];
    tree *tree = NULL;

    scanf(" %s", input);
    for(i = 0; input != NULL; i++){
        number = atoi(input);
        if(number < 0){
            break;
        }
        diff_order[i] = number;
        //printf("%d ", number);
        scanf(" %s", input);
    }
    size = i;
    for(i = 0; i < size; i++){
        tree = insert(tree, diff_order[i]);
    }
    printPreorder(tree);
    printf("\n");

    return 0;
}