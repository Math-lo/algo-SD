#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    int min;
    for(int i=0;i<n;i++){
        min=i;
        for (int j=i;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        swap_int(arr[i], arr[min]);
    }
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
    for (int i=1;i<n;i++){
        for (int j=i;j>0;j--){
            if (arr[j]<arr[j-1])
                swap_int(arr[j],arr[j-1]);
        }
    }
    
}

void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
    for (int i=0;i<n;i++){
        int max=0;
        for (int j=0;j<n-i;j++){
            if (arr[j]>arr[max])
                max=j;
        }
        for (int k=max;k<n-i;k++)
            swap_int(arr[k],arr[k+1]);
    }
}

int *merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    for (int j=0; j<r-l; j++){
        for(int i=1; i<r-l; i++){
            if (arr[i-1]>arr[i])
                swap_int(arr[i-1],arr[i]);
        }
    }
    return arr;
}

int* mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
    if (r-l<=1)
        return arr;
    int mid=(r-l)/2;
    int *L=mergesort_rec(arr,tmp,0,mid);
    int *R=mergesort_rec(arr,tmp,mid,r);
    return merge(L&&R,tmp,l,mid,r);
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r)
{
    // partition function
}

void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
    int pivot=0;
    for (int i=l;i<r;i++){
        if (arr[i]<arr[pivot]){
            
            pivot++;
        }
    }
    quick_sort_rec(arr,l,pivot);
    quick_sort_rec(arr,pivot+1,r);
    
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}