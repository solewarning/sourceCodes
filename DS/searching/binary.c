#include<stdio.h>
//given_arr-> sorted_arr ->binary search

int binarySearch(int arr[], int s, int e, int key){
    int mid = s + (e-s)/2;
    if(s>=e && (arr[s]!= key || arr[e]!=key)){
        return -1;  //note s>=e not s==e cuz 2 num wale arr ka mid s hoga in case s se bhi chota mid-1 s se bhi chota h
    }
    if (arr[mid]< key)
    {
        return binarySearch(arr, mid+1, e, key);
    }
    else if(arr[mid]> key)
    {
        return binarySearch(arr, s, mid-1, key);
    }
    else{
        return mid;
    }
}

void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = i-1 ; j >= 0 ; j--)
        {
            if(arr[j]<arr[j+1]){
                break;
            }
            swap(&arr[j], &arr[j+1]);
        } 
    }    
}

int main(){

    int key;
    int arr[] = {3,5,6,7,15,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("enter key: ");
    scanf("%d", &key);

    sort(arr, n);

    int index = binarySearch(arr, 0, n-1, key);
    if( index == -1){
        printf("key not found\n");
        return 0;
    }
    printf("key found at %d index", index);

}
