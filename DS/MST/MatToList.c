#include<stdio.h>

#define V 5

struct node{
    int index;
    int edgeweight;
    struct node* next;
};

struct node *createnode(int ind, int weight){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->index = ind;
    newnode->edgeweight = weight;
    newnode->next = NULL;
    return newnode;
}

int main(){
    //given adj matrix
    int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
    };

    //convert to adjlist
    struct node *g[V]={NULL};
    struct node *newnode; //for newnode
    struct node *temp; //for traveral
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if(G[i][j] == 0){
                continue;
            }
            newnode=createnode(j, G[i][j]);
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
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);
        temp = g[i];
        while (temp != NULL) {
            printf("(%d, %d) ", temp->index, temp->edgeweight);
            temp = temp->next;
        }
        printf("\n");
    }
}