#include <stdio.h>
#include <stdlib.h>

void display(int n,int adj[n][n]){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }
}

void warshall(int n,int adj[n][n]){
    int i,j,k;
    for(k = 0;k < n;k++){
        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
}

void main(){
    int n;
    int i,j,ans;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];
    int visited[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Does %d have a connection with %d [1/0]:", i, j);
            scanf("%d", &ans);
            if (ans == 1)
                adj[i][j] = 1;
            else
                adj[i][j] = 0;
        }
    }
    display(n,adj);
    printf("\n");
    warshall(n,adj);
    display(n,adj);
}