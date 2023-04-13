#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
if (a > b)
return a;
else
return b;
}



void constructTable(int W, int n, int table[n + 1][W + 1], int values[n + 1], int weights[n + 1])
{
int i, j;
for (i = 1; i <= n; i++)

 {

for (j = 1; j <= W; j++)

 {

if (j - weights[i] < 0)

 {

table[i][j] = table[i - 1][j];

 }

else

 {

table[i][j] = max(table[i - 1][j], values[i] + table[i - 1][j - weights[i]]);

 }

 }

 }

}



void backtrack(int n, int W, int solution[n], int table[n + 1][W + 1], int weights[n + 1])

{

int i = n;

int j = W;

int ind = n - 1;

while (i != 0)

 {

if (table[i][j] != table[i - 1][j])

 {

solution[ind] = i;

ind--;

j = j - weights[i];

i = i - 1;

 }

else

 {

i = i - 1;

 }

 }

}



void main()

{

int W, n, i, j;

printf("\nEnter capacity of knapsack: ");

scanf("%d", &W);

printf("\nEnter number of items: ");

scanf("%d", &n);

int solution[n];

int weights[n + 1];

int values[n + 1];

weights[0] = -1;

values[0] = -1;

for (i = 0; i < n; i++)

 {

solution[i] = -1;

 }

for (i = 1; i <= n; i++)

 {

printf("\nEnter weight of item %d: ", i);

scanf("%d", &weights[i]);

printf("\nEnter value of item %d: ", i);

scanf("%d", &values[i]);

 }

int table[n + 1][W + 1];

for (i = 0; i <= n; i++)

 {

for (j = 0; j <= W; j++)

 {

table[i][j] = 0;

 }

 }

constructTable(W, n, table, values, weights);

for (i = 0; i <= n; i++)

 {

for (j = 0; j <= W; j++)

 {

printf("%d\t", table[i][j]);

 }

printf("\n");

 }

backtrack(n, W, solution, table, weights);

printf("\nThe items for the optimal solution are: ");

for (i = 0; i < n; i++)

 {

if (solution[i] != -1)

 {

printf("%d ", solution[i]);

 }

 }

}
