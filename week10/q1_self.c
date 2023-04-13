#include <stdio.h>
#include <stdlib.h>

void display(int n, int adj[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("%d", adj[i][j]);
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
            printf("does i[%d] has connection with j[%d] [0/1]", i, j);
            scanf("%d", &a);
            if (a == 1)
            {
                adj[i][j] = 1;
            }
            else if (a == 0)
            {
                adj[i][j] = 0;
            }
            else
            {
                printf("enter valid input\n");
                return;
            }
        }
    }

    display(n, adj);
        printf("\n");
        printf("\n");
    warshall(n,adj);
    display(n, adj);
}