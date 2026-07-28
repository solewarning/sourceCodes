#include<stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = i-1; j >= 0 ; j--)
        {
            if(arr[j]<arr[j+1]){
                break;
            }
            swap(&arr[j], &arr[j+1]);
        }    
    }   
}

int main(){
    int arr[] = {8,5,4,6,2,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}