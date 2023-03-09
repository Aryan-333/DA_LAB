#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct Stack
{
    char stack[100];
    int top;
} Stack;

void Push(Stack *s, char item)
{
    if (s->top == max - 1)
    {
        printf("Stack Overflow");
    }
    s->stack[++(s->top)] = item;
}

char Pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack Undeflow");
    }
    return (s->stack[s->top--]);
}

void display(Stack *s)
{
    int i;
    for (i = 0; i <= (s->top); i++)
    {
        printf("%c", s->stack[i]);
    }
    printf("\t");
}

char Peak(Stack *s)
{
    return s->stack[s->top];
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

void main()
{
    Stack s1, *s;
    s = &s1;
    s->top = -1;
    int vertices,i, j, ind = 0,ans,empty = 1,vo = 0,po = 0;
    char temp, visit_order[10],pop_order[10];

    printf("\nHow many vertices does the graph have:\n");
    scanf("%d", &vertices);
    int matrix[vertices][vertices];
    int ch = 65;
    char visited[vertices];
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
    visit_order[vo++] = 'A';
    Push(s, 'A');
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            char x = 65 + j;
            empty = 1;
            if (matrix[i][j] == 1 && !(search(visited, x, vertices)))
            {
                empty = 0;
                visited[ind++] = x;
                Push(s, x);
                visit_order[vo++] = Peak(s);
                i = j;
                j = 0;
            }
        }
        if (empty == 1)
        {
            if (s->top != -1)
            {
                pop_order[po++] = Pop(s);
                char t = Peak(s);
                i = t - 65 - 1;
                j = 0;
            }
        }
    }
    printf("The visit order is: ");
    for (i = 0; i < vertices; i++)
    {
        printf("%c ", visit_order[i]);
    }
    printf("The pop order is: ");
    for (i = 0; i < vertices; i++)
    {
        printf("%c ", pop_order[i]);
    }
}