#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define V 5

struct node{
    int u, v, edgeweight;
    struct node* next;
};

struct node *createnode(int a, int b, int weight){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->u = a;
    newnode->v = b;
    newnode->edgeweight = weight;
    newnode->next = NULL;
    return newnode;
}

void heapify(struct node *arr[], int r, int n){
    int left = 2*r+1, right = 2*r+2, largest = r;
    if(left <= n && arr[largest]->edgeweight < arr[left]->edgeweight){
        largest = left;
    }
    if(right <= n && arr[largest]->edgeweight < arr[right]->edgeweight){
        largest = right;
    }
    if(largest!=r){
        struct node* temp = arr[r];
        arr[r] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, n);
    }
}

void heapsort(struct node *arr[], int n){
    /*
        last parent index == size/2-1 == (last index + 1)/2
    */

    for (int i = (n+1)/2 -1; i>=0; i--){
        heapify(arr, i, n);
    }
    struct node *swapper;
    for (int i = 0; i < n; i++)
    {
        swapper = arr[0];
        arr[0] = arr[n-i];
        arr[n-i] = swapper;
        heapify(arr, 0, n-i-1);
    } 
}

int ultpar(int parent[], int index){
    if(parent[index]==index){
        return index;
    }
    return ultpar(parent, parent[index]);
}

int main(){
    int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
    };
    
    //convert to list
    struct node *g[V]={NULL};
    struct node *newnode; //for newnode
    struct node *temp; //for traveral
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if(G[i][j] == 0){
                continue;
            }
            newnode=createnode(i, j, G[i][j]);
            if(!g[i]){
                g[i]=newnode;
                continue;
            }
            temp=g[i];
            while(temp->next!=NULL){
                temp = temp ->next;
            }
            temp->next = newnode;
        }  
    }

    //get edges together
    struct node *Edges[V*V]={NULL};
    int n = -1;  //last index
    for (int i = 0; i < V; i++)
    {
        temp = g[i];
        while(temp!=NULL){
            Edges[++n]=temp;
            temp = temp->next;
        }
    }

    //sort
    heapsort(Edges, n);
    
    //print checking disjoint set
    int parent[V*V], size[V*V] = {0};
    for (int i = 0; i < n+1; i++){
        parent[i] = i;
    }
    printf("u\tv\tedgeweight\n");
    for (int i = 0; i < n+1; i++){
        int uroot = ultpar(parent, Edges[i]->u);
        int vroot = ultpar(parent, Edges[i]->v);
        if (uroot != vroot) {
            printf("%d\t%d\t%d\n", Edges[i]->u, Edges[i]->v, Edges[i]->edgeweight);
            if (size[uroot] > size[vroot]) {
                size[uroot] += size[vroot];
                parent[vroot] = uroot;
            } 
            else {
                size[vroot] += size[uroot];
                parent[uroot] = vroot;
            }
        }   

    }
}