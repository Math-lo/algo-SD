#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    // return -1 if not found
    for (int i=0;i<n;i++){
        if (arr[i]==target){
            return i;
        }
    }

    return -1;
}

int jump_search(int *arr, int n, int target)
{
    // jump search on sorted array, return index
    // of target, return -1 if not found
    if (is_sorted_nondecreasing(arr,n)==false){
        return -1;
    }
    int jump=sqrt(n);
    for (int i=0;i<n;i+=jump){
        if (arr[i]>target){
            for (int j=i-jump;j<i;j++){
                if (arr[j]==target){
                    return j;
                }
            }
        }
    }
    return -1;
}

int binary_search(int *arr, int n, int target)
{
    // binary search on sorted array, return index
    // of target, return -1 if not found
    if (is_sorted_nondecreasing(arr,n)==false){
        return -1;
    }
    int a=0;
    int b=n;
    for (int i=0;i<n/2;i++){
        if (arr[(a+b)/2]<target){
            a=(a+b)/2;
        }
        else if (arr[(a+b)/2]>target){
            b=(a+b)/2;
        }
        else {
            return (a+b)/2;
        }
    }
    return -1;
}