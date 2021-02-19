#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
dlist *head[SIZE];
int num = 0;

int init(){
    head[num] = (dlist*)malloc(sizeof(dlist));
    if(head[num] == NULL){
        printf("Memory allocation error in initialization\n");
		exit(1);
    }
    head[num]->next = NULL;
    head[num]->prev = NULL; 
    num++;
    return num - 1;
}

int add_node(int number, int new_val){
    dlist *new_node = (dlist*)malloc(sizeof(dlist));
    if(new_node == NULL){
        printf("Memory allocation error in initialization\n");
		return 1;
    }
    new_node->data = new_val;
    new_node->next = head[number]->next;
    new_node->prev = head[number];
    if(new_node->next == NULL){
        new_node->prev->next = new_node;
        return 0;
    }
    new_node->next->prev = new_node;
    new_node->prev->next = new_node;
    

    return 0;
}

int remove_node(int number, int val){

    dlist *current;
    for(current = head[number]->next; current != NULL; current = current->next){
        if(current->data == val){
            current->next->prev = current->prev;
	        current->prev->next = current->next;
            free(current);
            return 0;
        }
    }
    return 1;
}

dlist *find_node(int number, int val){

    dlist *current;
    for(current = head[number]->next; current->next != NULL ; current = current->next){
        if(current->data == val){
            return  current;
        }
    }
    if(current->data == val){
        return current;
    }
    return NULL;
}

dlist *get_first_node(int number){
    dlist *current;
    for(current = head[number]->next; current->next != NULL; current = current->next);
    return current;
}

dlist *get_last_node(int number){
    return head[number]->next;
}

void delete_list(int number){
    dlist *curr = head[number];
    dlist *next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    num--;
}

dlist *return_head(int number){
    return head[number];
}

void delete_list_2(int number){
    dlist *curr = head[number];
    dlist *next;
    while(curr != NULL){
        next = curr->next;
        //printf("%d\n", curr->data);
        //printf("%d\n", next->data);
        free(curr);
        curr = next;
    }
    num--;
}

void print_list(int number){ 
    dlist *current;
    printf("%d ", get_first_node(number)->data);
    for(current = get_first_node(number)->prev; current != get_last_node(number); current = current->prev){
        printf("%d ", current->data);
    }
    printf("%d ", get_last_node(number)->data);
    printf("\n");
}

void print_part_list(int number, int start, int end){

    dlist *curr = get_ith_node(start, number);
    //dlist *last = get_ith_node(end, number);
    //printf("here\n");
    int i;
    for(i = start; i <= end; i++){
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

dlist *get_ith_node(int ith_data, int number){
    dlist *curr = get_first_node(number);
    int i;
    //printf("ith data: %d\n", ith_data);
    for(i = 0; i < ith_data ; i++){
        curr = curr->prev;
    }
    return curr;
}

void swap(int first, int second, int number){

    int temp = first;
    //printf("first: %d, second: %d\n", first, second);
    dlist *first_node = find_node(number, first);
    dlist *second_node = find_node(number, second);

    first_node->data = second;
    second_node->data = temp;
}

int length(int number){
    dlist *curr = head[number]->next;
    int i = 0;
    for(; curr != NULL; curr = curr->next){
        i++;
    }
    return i - 1;
}

