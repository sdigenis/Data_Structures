#include "tree.h"

tree *addNode(int data){ 
    tree *node = (tree*)malloc(sizeof(tree));  
    node->data = data;
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
}

void printGivenLevel(tree *root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
void deallocate (tree *node){
    //do nothing if passed a non-existent node
    if (node == NULL)
        return ;

    //now onto the recursion
    deallocate(node->left);
    deallocate(node->right);

    free(node);
}
void printLevelOrder(tree *root){
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
int height(tree *node){
    if (node==NULL)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight+1);
        else 
            return(rheight+1);
    }
}

int isBST(tree *node, int min, int max){
  if (node==NULL)  
     return 1; 
        
  if (node->data < min || node->data > max)  
     return 0;  
  
  return isBST(node->left, min, node->data-1) && isBST(node->right, node->data+1, max); 
}

tree *constructTree_post_order(int post[], int size){ 
    int postIndex = size-1; 
    return constructTreeUtil_post_order(post, &postIndex, post[postIndex], INT_MIN, INT_MAX, size); 
}

tree *constructTreeUtil_post_order(int post[], int* postIndex, int key, int min, int max, int size){  
    if (*postIndex < 0)
        return NULL;
    tree *root = NULL; 
    if (key > min && key < max){
        root = addNode(key); 
        *postIndex = *postIndex - 1; 
        if (*postIndex >= 0){
          root->right = constructTreeUtil_post_order(post, postIndex, post[*postIndex], key, max, size ); 
          root->left = constructTreeUtil_post_order(post, postIndex, post[*postIndex], min, key, size ); 
        }
    }
    return root; 
}
tree *construct_tree_level_order(int arr[], tree *root, int i, int n){ 
    if (i < n){ 
        tree *temp = addNode(arr[i]); 
        root = temp; 
        root->left = construct_tree_level_order(arr, root->left, 2 * i + 1, n); 
        root->right = construct_tree_level_order(arr, root->right, 2 * i + 2, n); 
    } 
    return root; 
}
tree *search(tree *root, int key){ 
    if (root == NULL || root->data == key) 
       return root; 
    
    if (root->data < key) 
       return search(root->right, key);
    
    return search(root->left, key); 
}
tree* getNode(int data) {
    tree *newNode = addNode(data); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}
tree* constructTreeUtil_pre_order(int pre[], int* preIndex, int key, int min, int max, int size){
    if (*preIndex >= size)
        return NULL;
 
    tree* root = NULL;
    if (key > min && key < max){
        root = addNode(key);
        *preIndex = *preIndex + 1;
 
        if (*preIndex < size) {
            root->left = constructTreeUtil_pre_order(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size){
            root->right = constructTreeUtil_pre_order(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }
 
    return root;
}
tree *construct_tree_pre_order(int pre[], int size){
    int preIndex = 0;
    return constructTreeUtil_pre_order(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

bool getPath(tree *root, lifo *arr, int x){ 
    if (!root) 
        return false; 
    push(arr, root->data);
    if (root->data == x) 
        return true;
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) 
        return true; 
    pop(arr); 
    return false; 
} 

void printPathBetweenNodes(tree *root, int n1, int n2, int size){ 
    lifo *path1 = createStack(size); 
    lifo *path2 = createStack(size);
  
    int intersection = -1; 

    getPath(root, path1, n1);
    getPath(root, path2, n2);
  
    int i = 0, j = 0; 
    while (i != path1->top || j != path2->top) { 

        if (i == j && path1->array[i] == path2->array[j]) { 
            i++; 
            j++; 
        } 
        else { 
            intersection = j - 1; 
            break; 
        } 
    }
    for (i = path1->top - 1; i > intersection; i--) 
        printf("%d ", path1->array[i]); 
  
    for (i = intersection; i < path2->top; i++) 
        printf("%d ", path2->array[i]); 

    free(path1->array);
    free(path2->array);
    free(path1);
    free(path2);
}
int distanceFromRoot(tree *root, int x){ 
    if (root->data == x) 
        return 0; 
    else if (root->data > x) 
        return 1 + distanceFromRoot(root->left, x); 
    return 1 + distanceFromRoot(root->right, x); 
}
int distanceBetween2(tree *root, int a, int b){ 
    if (!root) 
        return 0; 
  
    if (root->data > a && root->data > b) 
        return distanceBetween2(root->left, a, b); 
    if (root->data < a && root->data < b)
        return distanceBetween2(root->right, a, b);  
    if (root->data >= a && root->data <= b) 
        return distanceFromRoot(root, a) + distanceFromRoot(root, b); 
    return 0;
}  
int findDistWrapper(tree *root, int a, int b){ 
    int temp;
    if (a > b){
        temp = a;
        a = b;
        b = temp;
    } 
   return distanceBetween2(root, a, b);    
} 