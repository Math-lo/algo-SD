#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n)
{
    // return true if array is sorted and false otherwise
    for (int i=1;i<n;i++){
        if (arr[i-1]>arr[i]){
            return false;
        }
    }
    return true;
}

int min_int(int a, int b)
{
    if (a<b) {
        return a;
    }
    return b;
}