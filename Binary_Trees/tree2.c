#include "tree.h"
#include "stack.h"
#include "fifo.h"
#include "dlist.h"

int main(int argc, char * argv[]){

    int i, number, size, res;
    char *input = (char*)malloc(sizeof(char));
    int level_order[1000];
    tree *tree = NULL;

    scanf(" %s", input);
    for(i = 0; input != NULL; i++){
        number = atoi(input);
        if(number < 0){
            break;
        }
        level_order[i] = number;
        //printf("%d ", number);
        scanf(" %s", input);
    }
    //printf("\n");
    size = i;
    tree = construct_tree_level_order(level_order, tree, 0,size);

    res = isBST(tree, INT_MIN, INT_MAX);
    if(res == 1){
        printf("Binary Search Tree\n");
    }
    else{
        printf("Binary Tree\n");
    }

    free(input);
    deallocate(tree);
    return 0;
}