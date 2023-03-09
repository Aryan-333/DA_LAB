#include <stdio.h>
#include <stdlib.h>
#define max_size 50

typedef struct Queue
{   int front;
    int rear;
    char *arr;
} Queue;

int isFull(Queue *q)
{
    return q->rear == max_size - 1;
}

int isEmpty(Queue *q)
{
    return q->rear == q->front;
}

void enqueue(Queue *q, char element)
{
    if (isFull(q))
    {
        printf("\nArray is Full\n");
    }
    q->arr[++q->rear] = element;
}

void dequeue(Queue *q)
{
    q->front = q->front + 1;
    return;
}

void display(Queue *q)
{
    int i;
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%c  ", q->arr[i]);
    }
}

int search(char visited[], char x, int vertices)
{
    int i;
    for (i = 0; i < vertices; i++)
    {
        if (x == visited[i])
            return 1;
    }
    return 0;
}

int peak_front(Queue *q){
    char c = q->arr[q->front];
    return c;
}

void main(){
    Queue *q,q1;
    q = &q1;
    q->front = 0;
    q->rear = -1;
    q->arr = (char *)malloc(max_size * sizeof(char));
    int i,j,ind = 0,ans,vertices;
    printf("\nHow many vertices does the graph have:\n");
    scanf("%d", &vertices);
    char visited[vertices];
    int matrix[vertices][vertices];
    int ch = 65;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("Does %c have a connection with %c [1/0]:", i + 65, j + 65);
            scanf("%d", &ans);
            if (ans == 1)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("  %d", matrix[i][j]);
        }
        printf("\n");
    }
    visited[ind++] = 'A';
    enqueue(q,'A');
    for(i = 0;i < vertices;i++){
         for(j = 0;j < vertices;j++){
             char x = 65 + j;
             if(matrix[i][j] == 1 && !(search(visited,x,vertices))){
                 enqueue(q,x);
                 visited[ind++] = x;
             }
         }
         dequeue(q);
         i = peak_front(q) - 65 - 1;
         j = 0;
     }
     printf("Visit order is: ");
     for(i = 0; i < vertices;i++){
         printf("  %c",visited[i]);
     }
}