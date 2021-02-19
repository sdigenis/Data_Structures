#ifndef __SORT_H_
#define __SORT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"
#include <math.h>

void insertion_sort(int list_num);
void selection_sort(int list_num);
void quick_sort(int start, int end, int list_num, int times);
void merge_sort(int list_num, int r, int l, int times, int prev);
void radix_sort_lsd(int bits, int list_num, int length);
void radix_sort_msd(int bits, int list_num, int len, int times, int fores);
dlist *return_head(int number);
void decimal_to_binary(int list_num);

#endif