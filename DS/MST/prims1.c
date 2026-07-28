#include<stdio.h>

#define V 5

int main(){
    int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
    };
    
    int visited[V] = {0}; //to track visited vertices
    visited[0] = 1;
    int inMST = 0; //to end while loop
    int from, to;
    int i,j;
    printf("MST\n");
    printf("from\tto\tweight\n");
    while (inMST < V-1){
        from = to = -1;
        for (i = 0; i < V; i++){
            if(visited[i]){
                for (j = 0; j < V; j++)
                {
                    if(visited[j] || G[i][j] == 0){
                        continue;
                    }
                    if(from == -1){
                        from = i;
                        to = j;
                        continue;
                    }
                    if(G[from][to]> G[i][j]){
                        from = i;
                        to = j;
                    }    
                }
                
            }
        }
        visited[to]=1;
        printf("%d\t%d\t%d\n", from, to, G[from][to]);
        inMST++;
    }   
}