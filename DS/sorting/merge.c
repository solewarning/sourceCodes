#include<stdio.h>

void merge(int arr[], int s, int m, int e){
    if(s==e){
        return;
    }
    int leftcpy[m-s+1], rightcpy[e-m];
    int l=0, r=0;
    for (int i = s; i < e+1; i++)
    {
        if(i<m+1){
            leftcpy[l++] = arr[i];
        }
        else{
            rightcpy[r++] = arr[i];
        }
    }
    int j = s-1;
    l=0, r=0;
    while(l<(m-s+1)||r<(e-m)){
        if(leftcpy[l]<rightcpy[r]){
            arr[++j] = leftcpy[l++];
        }
        else{
            arr[++j] = rightcpy[r++];
        }
    }
    while(l<(m-s+1)){
        arr[++j] = leftcpy[l++];
    }
    while(r<(e-m)){
        arr[++j] = rightcpy[r++];
    }
    return;
}

void mergesort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int m = s + (e-s)/2;
    mergesort(arr, s, m);
    mergesort(arr, m+1, e);
    merge(arr, s, m, e);
}

int main(){
    int arr[] = {8,5,4,6,2,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}