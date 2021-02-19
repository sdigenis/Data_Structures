#include "tree.h"
#include "stack.h"
#include "fifo.h"
#include "dlist.h"

typedef struct list1
{
    dlist list;
    int list_num;
    int length;
    int sum;
}list;

int main(int argc, char *argv[]){

    int i, j = 0;
    int number, res, loops, max_index, max;
    list zero_add[SIZE];
    char *input;
    input = (char*)malloc(sizeof(char));
    list final;

    scanf(" %s", input);
    for(i = 0; input != NULL; i++, scanf(" %s", input)){
        number = atoi(input);
        if(number == 0){
            break;
        }
        zero_add[i].list_num = init();
        zero_add[i].sum = 0;
        zero_add[i].length = 0;
        for(j = 0; j < i + 1; j++){
            res = add_node(zero_add[j].list_num, number);
            if(res == 1){
                return 1;
            }
            zero_add[j].sum += number;
            if(zero_add[j].sum == 0){
                zero_add[j].length = i - zero_add[j].list_num +1;
            }
        }
    }
    loops = i - 1;
    max = zero_add[0].length;
    max_index = 0;
    for(i = 0; i < loops; i++){
        if(max < zero_add[i].length){
            max = zero_add[i].length;
            max_index = i;
        }
    }
    dlist *curr = get_first_node(zero_add[max_index].list_num);
    final.list_num = init();
    for(i = max_index; i < max_index + zero_add[max_index].length; i++){
        res = add_node(final.list_num, curr->data);
        if(res == 1){
            return 1;
        }
        curr = curr->prev;
    }
    printf("start: %d, stop: %d, size: %d\n", max_index, max_index - 1 + zero_add[max_index].length, zero_add[max_index].length);
    print_list(final.list_num);
    //free

    for(i = 0; i < loops + 1; i++){
        delete_list(zero_add[i].list_num);
    }
    delete_list(final.list_num);
    free(input);

    return 0;
}