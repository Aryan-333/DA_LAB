#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[],int i){

    int parent= i/2; //imagine in an array; parent child relation 
    while(parent>0)
    {
        if(arr[parent] < arr[i])
        {
            int a = arr[parent];
            arr[parent]=arr[i];
            arr[i]=a;

            // i=parent;
            // parent= i/2;
        }
        else 
        return;
    }    

}

void main(){

    int n,arr[100];
    printf("enter the number of element");
    scanf("%d",&n);

    printf("enter the elements");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
        heapify(arr,i);
    }
        printf("\nThe heap created is : ");
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    

}