#include "sort.h"
#include "dlist.h"
#include <stdlib.h>


int main(int argc, char *argv[]){

    int res, list_num, option;
    int bits = 0;
    list_num = init() ;
    int *input = (int*)malloc(sizeof(int));

    list_num = init();

    if(argc > 3){
        printf("Wrong number of arguments!\n");
        return 1;
    }
    option = atoi(argv[1]);
    if(option <= 0 || option > 6){
        printf("Invalid argument​\n");
        return 1;
    }
    if(option == 5 || option == 6){
        bits = atoi(argv[2]);
        if(bits == 1 || bits == 2 || bits == 4 || bits == 8 || bits == 16);
        else{
            printf("Invalid argument​\n");
            return 1;
        }
    }
    scanf(" %d", input);
    while(*input >= 0){
        res = add_node(list_num, *input);
        if(res == 1)
            return 1;
        scanf(" %d", input);
    }
    print_list(list_num);
    printf("\n");

    switch (option)
    {
    case 1:
        insertion_sort(list_num);
        break;
    case 2:
        selection_sort(list_num);
        break;
    case 3:
        quick_sort(0, length(list_num) , list_num, 0);
        break;
    case 4:
        merge_sort(list_num, 0, length(list_num) , 0, 0);
        break;
    case 5:
        decimal_to_binary(list_num);
        //printf("here\n");
        //radix_sort_msd(bits, list_num, 0, 0, 0);
        break;
    case 6:
        decimal_to_binary(list_num);
        radix_sort_lsd(bits, list_num, length(list_num) + 1);
        break;
    default:
        break;
    }

    printf("\n");
    print_list(list_num);
    delete_list(list_num);
    return 0;
}