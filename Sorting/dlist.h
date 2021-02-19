#ifndef __DLIST_H_
#define __DLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 1000

typedef struct dlist{
    int data;
    struct dlist *next;
    struct dlist *prev;
    char binary[32];
}dlist;

int init();
int add_node(int number, int new_val);
int remove_node(int number, int val);
dlist *find_node(int number, int val);
dlist *get_first_node(int number);
dlist *get_last_node(int number);
void delete_list(int number);
void delete_list_2(int number);
void print_list(int number);
dlist *get_ith_node(int ith_data, int number);
void swap(int first, int second, int number);
int length(int number);
void print_part_list(int number, int start, int end);
#endif