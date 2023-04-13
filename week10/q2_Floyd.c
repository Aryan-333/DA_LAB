#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
    if(a >= b)
        return b;
    else
        return a;     
}

void display(int n, int adj[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("%d  ", adj[i][j]);
        }
        printf("\n");
    }
}

void floyd(int n,int adj[n][n]){
    int i,j,k;
    for(k = 0;k < n;k++){
        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
            }
        }
    }
}

void main()
{
    int n, a;
    printf("enter the number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("enter distance between i[%d], j[%d] (enter 33 for infinity)", i, j);
            scanf("%d", &a);
                adj[i][j] = a;
        }
    }

    display(n, adj);
        printf("\n");
        printf("\n");
    floyd(n,adj);
    display(n, adj);
}