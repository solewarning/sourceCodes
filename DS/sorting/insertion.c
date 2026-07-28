#include<stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int min = i;
        int j;
        for (j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

int main(){
    int arr[] = {8,5,4,6,2,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}