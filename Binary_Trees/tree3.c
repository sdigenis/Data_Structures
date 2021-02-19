#include "tree.h"
#include "stack.h"
#include "fifo.h"
#include "dlist.h"

int main(int argc, char * argv[]){

    int i, number, size, search1, search2, hght;
    char *input = (char*)malloc(sizeof(char));
    int pre_order[1000];
    tree *tree = NULL, *srch = NULL;

    scanf(" %s", input);
    for(i = 0; input != NULL; i++){
        number = atoi(input);
        if(number < 0){
            break;
        }
        pre_order[i] = number;
        //printf("%d ", number);
        scanf(" %s", input);
    }
    //printf("\n");
    size = i;
    tree = construct_tree_pre_order(pre_order, size);

    printf("Enter 2 integers: \n");
    scanf(" %d", &search1);
    scanf(" %d", &search2);
    //printf("%d, %d\n", search1, search2);
    srch = search(tree, search1);

    if(srch->data != search1){
        printf("%d not found!\n", search1);
        return -1;
    }
    srch = search(tree, search2);
    if(srch->data != search2){
        printf("%d not found!\n", search1);
        return -1;
    }
    size = findDistWrapper(tree, search1, search2);
    hght = height(tree);
    if(size > hght){
        hght = size;
    }
    //printf("%d\n", size);
    printf("Path is: %d ", search1);
    printPathBetweenNodes(tree, search1, search2, hght);
    printf("%d\n", search2);

    free(input);
    deallocate(tree);
    
    return 0;
}