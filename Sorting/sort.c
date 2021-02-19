#include "sort.h"
#include "dlist.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void insertion_sort(int list_num)
{

    int i, key, j;
    dlist *curr = get_first_node(list_num);
    dlist *head = return_head(list_num);
    for (i = 1; curr->prev != head; curr = curr->prev, i++)
    {
        key = get_ith_node(i, list_num)->data;
        j = i - 1;
        while (j >= 0 && get_ith_node(j, list_num)->data > key)
        {
            swap(get_ith_node(j + 1, list_num)->data, get_ith_node(j, list_num)->data, list_num);
            j = j - 1;
        }
        get_ith_node(j + 1, list_num)->data = key;
        printf(" [%d]: ", i);
        print_list(list_num);
    }
}

void selection_sort(int list_num)
{

    int i, j, min_idx, len;
    dlist *curr = get_first_node(list_num);
    dlist *head = return_head(list_num);
    for (i = 0; curr->prev != head; curr = curr->prev, i++)
    {
        len = length(list_num);
        min_idx = i;
        for (j = i + 1; j < len; j++)
        {
            if (get_ith_node(j, list_num)->data < get_ith_node(min_idx, list_num)->data)
            {
                min_idx = j;
            }
        }
        swap(get_ith_node(min_idx, list_num)->data, get_ith_node(i, list_num)->data, list_num);
        printf(" [%d]: ", i + 1);
        print_list(list_num);
    }
}

int partition(int list_num, int low, int high)
{

    //printf("%d\n", high);
    int pivot = get_ith_node(high, list_num)->data; // pivot
    int finish = 0, change = 0;
    int i = low, j;
    //printf("high: %d, low: %d\n", high-1, low);
    //printf("%d\n", pivot);
    for (j = high - 1; j >= low; j--)
    {
        if (j == i)
        {
            break;
        }
        if (get_ith_node(j, list_num)->data < pivot)
        {
            change++;
            while (get_ith_node(i, list_num)->data < pivot)
            {
                i++;
                if (j == i)
                {
                    finish++;
                    break;
                }
            }
            if (finish == 1)
            {
                break;
            }
            swap(get_ith_node(i, list_num)->data, get_ith_node(j, list_num)->data, list_num);
            //printf("i : %d, j: %d\n", i, j);
        }
    }
    if (j == i && (change == 0) && pivot < get_ith_node(i, list_num)->data)
    {
        //printf("i\n");
        swap(get_ith_node(i, list_num)->data, pivot, list_num);
        return i;
    }
    else
    {
        //printf("i+1\n");
        swap(get_ith_node(i + 1, list_num)->data, pivot, list_num);
        return i + 1;
    }
    return (i + 1);
}

void quick_sort(int start, int end, int list_num, int times)
{
    int i;
    if (start < end)
    {
        for (i = 0; i < times; i++)
        {
            printf("== ");
        }
        printf("[%d >] ", times);
        //printf("here\n");
        print_part_list(list_num, start, end);

        int pi = partition(list_num, start, end);
        if (start + 1 != end)
        {
            for (i = 0; i < times; i++)
            {
                printf("== ");
            }
            printf("[%d -] ", times);
            print_part_list(list_num, start, end);
        }

        quick_sort(start, pi - 1, list_num, times + 1);

        quick_sort(pi + 1, end, list_num, times + 1);
        for (i = 0; i < times; i++)
        {
            printf("== ");
        }
        printf("[%d <] ", times);
        print_part_list(list_num, start, end);
    }
}

void merge(int list_num, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L = init();
    int R = init();
    for (i = 0; i < n1; i++)
        add_node(L, get_ith_node(l + i, list_num)->data);
    for (j = 0; j < n2; j++)
        add_node(R, get_ith_node(m + 1 + j, list_num)->data);
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (get_ith_node(i, L)->data <= get_ith_node(j, R)->data)
        {
            get_ith_node(k, list_num)->data = get_ith_node(i, L)->data;
            i++;
        }
        else
        {
            get_ith_node(k, list_num)->data = get_ith_node(j, R)->data;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        get_ith_node(k, list_num)->data = get_ith_node(i, L)->data;
        ;
        i++;
        k++;
    }
    while (j < n2)
    {
        get_ith_node(k, list_num)->data = get_ith_node(j, R)->data;
        j++;
        k++;
    }
    delete_list(L);
    delete_list(R);
}

void merge_sort(int list_num, int start, int end, int times, int prev)
{
    int i;
    if (start < end)
    {
        int m = start + (end - start) / 2;
        if ((start + end) % 2 == 0)
        {
            m--;
        }
        prev = end - start;
        for (i = 0; i < times; i++)
        {
            printf("== ");
        }
        printf("[%d >] ", times);
        print_part_list(list_num, start, end);
        merge_sort(list_num, start, m, times + 1, prev);
        merge_sort(list_num, m + 1, end, times + 1, prev);

        merge(list_num, start, m, end);
        for (i = 0; i < times; i++)
        {
            printf("== ");
        }
        printf("[%d <] ", times);
        print_part_list(list_num, start, end);
    }
    else if (prev != 1 && start == end)
    {
        for (i = 0; i < times; i++)
        {
            printf("== ");
        }
        printf("[%d >] ", times);
        print_part_list(list_num, start, end);
        for (i = 0; i < times; i++)
        {
            printf("== ");
        }
        printf("[%d <] ", times);
        print_part_list(list_num, start, end);
    }
}

void decimal_to_binary(int list_num){
    dlist *curr;
    dlist *head = return_head(list_num);
    int data;
    for(curr = get_first_node(list_num); curr != head; curr = curr->prev){
        int i, j;
        data = curr->data;
        memset(curr->binary, '0', sizeof(char) * 32);
        for(j = 0; j < 32; j++){
            curr->binary[j] = '0';
        }
        curr->binary[j] = '\0';
        i = 32;
        //printf("data: %d\n", data);
        //sleep(1);
        while (data > 0) { 
            //printf("i: %d\n", i);
            // storing remainder in binary array 
            if(data % 2 == 0){
                curr->binary[i - 1] = '0';
            }
            else {
                curr->binary[i - 1] = '1';
            }
            //printf("%d\n", data);
            
            data = data / 2;
            i--; 
        }
    }
}

int get_max(int list_num, int n)
{
    int max = get_first_node(list_num)->data;
    for (int i = 1; i < n; i++)
        if (get_ith_node(i, list_num)->data > max)
            max = get_ith_node(i, list_num)->data;
    return max;
}

int get_decimal(int list_num, int bits, int time, int i){

    int j, num, rem, decimal = 0, base = 1, k;
    int max = 31;
    char bit_to_int[bits], number[bits];
    
    j = 0;
    
    for(j = 0, k = 0; j > - bits; j--, k++){
        //printf("%c", get_ith_node(i, list_num)->binary[max - time + j]);
        bit_to_int[k] = get_ith_node(i, list_num)->binary[max - time + j];
    }
    //printf("\n");
    //printf("%s", bit_to_int);
    for(j = 0, k = bits - 1; j < bits; j++, k--){
        number[j] = bit_to_int[k];
    }
    number[j] = '\0';
    //printf("bits: %s\n", number);
    num = atoi(number);
    //printf("%d\n", num);
    while(num  > 0){
        rem = num % 10;
        decimal = decimal + rem * base;
        num /= 10;
        base *= 2;
    }
    //printf("decimal: %d\n", decimal);
    return decimal;
}

int get_binary(int decimal){
    int binary, i = 1, rem = 0;;
    while(decimal > 0){
        rem = decimal % 2;
        binary += rem * i;
        decimal /= 2;
        i *= 10;
    }
    return binary;
}
void countSort(int list_num, int length, int time, int bits) { 

    int output[length];
    int num = pow(2, bits);
    int i, count[num], decimal;

    memset(count, 0, num * sizeof(int));

    for(i = 0; i < length; i++){
        decimal = get_decimal(list_num, bits, time, i);
        count[decimal]++;
    }
    for(i = 1; i < num; i++){
        count[i] += count[i - 1];
    }
    
    for (i = length - 1; i >= 0; i--){ 
        decimal = get_decimal(list_num, bits, time, i);
        output[count[decimal] - 1] = get_ith_node(i, list_num)->data;
        count[decimal]--; 
    }

    for(i = 0; i < length; i++){
        get_ith_node(i, list_num)->data = output[i];
    }
    decimal_to_binary(list_num);
    for(i = 0; i < length; i++){
        printf("%d", get_ith_node(i, list_num)->data);

        char bit_to_int[bits], number[bits];
        int j, k;
        for(j = 0, k = 0; j > - bits; j--, k++){
            bit_to_int[k] = get_ith_node(i, list_num)->binary[31 - time + j];
        }
        for(j = 0, k = bits - 1; j < bits; j++, k--){
            number[j] = bit_to_int[k];
        }
        number[j] = '\0';
        printf("(%s) ", number);
    }
    printf("\n");
} 

void radix_sort_lsd(int bits, int list_num, int length){
    int i, max = 32 / bits;
    for(i = 0; i < max; i++){
        printf(" [%d] ", i);
        countSort(list_num, length, i * bits, bits);
    }
}

int get_number(int list_num, int time, int bits, int i){

    int j, num, rem, decimal = 0, base = 1, k;
    int max = 31;
    char bit_to_int[bits], number[bits];
    
    j = 0;
    
    for(j = 0, k = 0; j < bits; j++, k++){
        //printf("%c", get_ith_node(i, list_num)->binary[max - time + j]);
        bit_to_int[k] = get_ith_node(i, list_num)->binary[time + j];
    }
    //printf("\n");
    //printf("%s", bit_to_int);
    /* for(j = 0, k = bits - 1; j < bits; j++, k--){
        number[j] = bit_to_int[k];
    } */
    //number[j] = '\0';
    //printf("bits: %s\n", number);
    num = atoi(bit_to_int);
    //printf("%d\n", num);
    while(num  > 0){
        rem = num % 10;
        decimal = decimal + rem * base;
        num /= 10;
        base *= 2;
    }

    return decimal;
}

void radix_sort_msd(int bits, int list_num, int time, int times, int fores){
    int i, max = 32 / bits, idx, j;
    dlist *buckets;
    int p = pow(2, bits);
    int listes[p];
    if(fores == p - 1){
        return;
    }
    if(length(list_num) - 1 == 0){
        return;
    }

    for(j = 0, i = time * p + time; j < p; i++, j++){
        listes[i] = init();
    }
    printf("list_num: %d, length: %d\n", list_num, length(list_num));
    for(j = 0, i = time * p + time; j < length(list_num) ; i++, j++){
        //printf("here\n");
        idx = get_number(list_num, times, bits, j);
        add_node(idx, get_ith_node(j, list_num)->data);
    }

    if(time == 0 && fores == 0){
        for(i = 0; i < p; i++){
            radix_sort_msd(bits, i, time + 1, times + bits, i);
        }
        for(i = 0; i < p; i++){
            delete_list(i);
        }
        return ;
    }
    
    for(i = 0; i < time; i++){
        printf("== ");
    }
    
    //for(i = 0; i < length(list_num); i++){
        /* if(length(j) == 0){
            continue;
        } */
        int num, rem, base, decimal;
        char bit_to_int[bits];
        for(int j = 0, k = 0; j < bits; j++, k++){
            
            bit_to_int[k] = get_ith_node(0, list_num)->binary[times - bits + j];
        }
        num = atoi(bit_to_int);
        while(num  > 0){
            rem = num % 10;
            decimal = decimal + rem * base;
            num /= 10;
            base *= 2;
        }
        printf("[%d, %d] (%s) ", time, decimal, bit_to_int);
        print_list(list_num);
    //}
    printf("\n");
    
    
    for(i = 0; i < p; i++){
        radix_sort_msd(bits, time * p + i, time + 1, times + bits, i);
    }
    for(j = 0, i = time * p; j < p; i++, j++){
        delete_list(i);
    }
        //return;
    
    return;
}

/* void radix_sort_msd_mine(int bits, int list_num, int time, int lista){

    if(bits * time == 32 || length(lista) == 0){
        return;
    }

    int radix = 32 / bits;
    int i, j;
    int listes[radix];
    char data[bits];

    for(i = 0,j = time; i < bits * time; j++, i++){
        listes[j] = init();
    }
    int len = length(lista);
    i = 0;
    while(!len){
        for(j = 0; j < bits; j++){
            data[j] = get_ith_node(len - 1, lista)->binary[];
        }
 
        len--;
    }


} */