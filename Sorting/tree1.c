#include "tree.h"

int main(int argc, char *argv[]){

    int i, number, size;
    char *input = (char*)malloc(sizeof(char));
    int pre_order[1000], option;
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
    size = i;
    tree = construct_tree_pre_order(pre_order, size);
    printf("Enter integer: \n");
    scanf(" %d", &option);

    srch = search(tree, option);
    if(srch->data != option){
        printf("%d not found!\n", option);
        return -1;
    }
    printf("Integers in level %d are: ", node_height(tree, option, 0) );
    print_level(tree,  node_height(tree, option, 0) + 1);
    printf("\n");

    return 0;
}