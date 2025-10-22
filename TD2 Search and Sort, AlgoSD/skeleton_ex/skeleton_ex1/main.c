#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    // implement main here
    // create array example using malloc
    // use searching algorithms and compare runtime
    int*arr=malloc(4*10);
    arr[0]=1;
    arr[1]=5;
    arr[2]=9;
    arr[3]=12;
    arr[4]=13;
    arr[5]=16;
    arr[6]=22;
    arr[7]=28;
    arr[8]=60;
    arr[9]=67;
    time_t begin=time(NULL);
    linear_search(arr,10,28);
    time_t end=time(NULL);
    int secondes_l=difftime(end,begin);
    printf("temps de linear search : %i",secondes_l);

    time_t begin=time(NULL);
    jump_search(arr,10,28);
    time_t end=time(NULL);
    int secondes_j=difftime(end,begin);
    printf("temps de jump search : %i",secondes_j);

    time_t begin=time(NULL);
    binary_search(arr,10,28);
    time_t end=time(NULL);
    int secondes_b=difftime(end,begin);
    printf("temps de binary search : %i",secondes_b);

    
    free(arr);
    return 0;
}