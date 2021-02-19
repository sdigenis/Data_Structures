#include "dlist.h"
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
    while(curr != NULL){
        dlist* next = curr->next;
        free(curr);
        curr = next;
    }
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