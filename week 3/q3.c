#include <stdio.h>
#include <stdlib.h>

int isPartition(int arr[],int n, int target_sum){
    if(target_sum == 0)
    return 1;
    if( n == 0 && target_sum != 0)
    return 0;

    if (arr[n-1]>target_sum)
    {
        return isPartition(arr,n-1,target_sum);
    }
    else{
    return isPartition(arr,n-1,target_sum) || isPartition(arr,n-1,target_sum - arr[n-1]);
    }

}

void main(){
    int n, arr[n],sum=0;
    
    printf("Enter number of element\n");
    scanf("%d",&n);

    if(n<=1)
    {
        printf("Partition not possible\n");
    }
    else
    {
        printf("Enter the elements\n");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum = sum + arr[i];
        }
    
    if(sum%2==0){
        if (isPartition(arr,n,sum/2))
        {
            printf("Partition possible\n");
        }
        else{
        printf("Partition not possible\n");
        }
    }
    else{ printf("Partition not possible\n");}
    }
    




    }