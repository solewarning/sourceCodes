#include<stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int s, int e){
    int piv = arr[e];
    int i=s, j;
    for (j = s; j < e; j++)
    {
        if(piv>arr[j]){
            swap(&arr[j], &arr[i++]);
        }
    }
    swap(&arr[e],&arr[i]);
    return i;
}

void quicksort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int piv_pos = partition(arr, s, e);
    quicksort(arr, s, piv_pos-1);
    quicksort(arr, piv_pos+1, e);
    return;
}

int main(){
    int arr[] = {8,5,4,6,2,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}