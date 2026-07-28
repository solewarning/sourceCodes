#include<stdio.h>

#define N 100

void dfs(int adjmatrix[N][N],int visited[N], int n, int root){
    printf("%d ", root);
    for (int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && adjmatrix[root][i]==1){
            visited[i] = 1;
            dfs(adjmatrix, visited, n, i);
        }
    }
       
}

int main(){
    int  adjmatrix[N][N];
    int start, v;
    printf("enter number of vertices: ");
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        for (int j = i; j < v; j++)
        {
            if(i==j){
                adjmatrix[i][j]=0;
                continue;
            }
            printf("enter edge weight(if no edge then 0 else 1) %d%d : ", i, j);
            scanf("%d", &adjmatrix[i][j]);
            adjmatrix[j][i] = adjmatrix[i][j];
        } 
    }
    printf("enter vetex to start: ");
    scanf("%d", &start);
    
    int visited[N]={0};
    visited[start]= 1;
    dfs(adjmatrix, visited, v, start);
}
