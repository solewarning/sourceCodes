#include<stdio.h>

#define N 100

int queue[N];
int front = -1, rear = -1;

void enqueue(int v){
    if(rear == -1){
        queue[++rear]= v;
        front = rear;
        return;
    }
    queue[++rear] = v;
}

int dequeue(){
    if(front == rear){
        int n = queue[front];
        rear = front = -1;
        return n;
    }
    return queue[front++];
}

void bfs(int adjmatrix[N][N], int n, int start){
    int visited[N]= {0};
    enqueue(start);
    visited[start]=1;
    while(front != -1){
        int current = dequeue();
        for (int i = 0; i < n; i++)
        {
            if(adjmatrix[current][i]==1 && visited[i] == 0){
                enqueue(i);
                visited[i]=1;
            }
        }
        printf("%d ", current);
    }
}

int main(){
    int  adjmatrix[N][N];
    int start, v;
    printf("enter number of vertices: ");
    scanf("%d", &v);
    for (int i = 0; i < v; i++)
    {
        for (int j = i+1; j < v; j++)
        {
            printf("enter edge weight(if no edge then 0 else 1) %d%d : ", i, j);
            scanf("%d", &adjmatrix[i][j]);
            adjmatrix[j][i] = adjmatrix[i][j];
        } 
    }
    printf("enter vetex to start: ");
    scanf("%d", &start);

    bfs(adjmatrix, v, start);
}
