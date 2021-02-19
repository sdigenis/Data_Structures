#include "tree.h"
#include "stack.h"
#include "fifo.h"
#include "dlist.h"

int main(int argc, char * argv[]){

    int i, number, size;
    char *input = (char*)malloc(sizeof(char));
    int post_order[1000];
    tree *tree;

    scanf(" %s", input);
    for(i = 0; input != NULL; i++){
        number = atoi(input);
        if(number < 0){
            break;
        }
        post_order[i] = number;
        //printf("%d ", number);
        scanf(" %s", input);
    }
    //printf("\n");
    size = i;
    tree = constructTree_post_order(post_order, size);
    printLevelOrder(tree);
    printf("\n");

    free(input);
    deallocate(tree);

    return 0;
}