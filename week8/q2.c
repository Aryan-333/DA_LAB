#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n)
{
    int i, k, v, heapify, j;
    for (i = (n/2); i >= 1; i--)
    {
        k = i;
        v = arr[k];
        heapify = 0;
            while (heapify == 0 && 2 * k <= n)
            {
                j = 2 * k;
                if (j < n)
                    if (arr[j] < arr[j + 1]) //finding the bigger among the two childrens
                        j = j + 1;
                if (v >= arr[j]) //then only comparing with bigger among the two childrens
                    heapify = 1;
                else //swapping if it is bigger
                {
                    arr[k] = arr[j];
                    k = j;
                }
            }
        arr[k] = v; //to replace the the child , above we have only assigned parent here we are changing child too
    }
    return;
}
   

void main()
{

    int n, arr[100];
    printf("enter the number of element");
    scanf("%d", &n);

    printf("enter the elements");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heapify(arr, n);

    printf("\nThe heap created is : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nThe sorted heap is : ");
    while (n!=0)
    {
        printf("%d",arr[1]);
        arr[1]=arr[n];
        n--;
        heapify(arr,n);
    }
}