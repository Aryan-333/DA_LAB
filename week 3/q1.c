#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a,int n){
    int opcount =0;
    for (int i = 0; i < n-1; i++)
    {
        for(int j=0; j<n-i-1;j++){
            opcount++;
            if(a[j]> a[j+1]){

                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]= temp;


            
             }
        }
        
    }
    printf("opcount: %d\n",opcount);
}

int main(){
int n, a[1000];

printf("Enter the number of elements\n");
scanf("%d",&n);

printf("enter the elements\n");
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}

bubbleSort(a,n);
printf("bubble sorted array is: \n");

 
    for (int i = 0; i < n; i++)
{
    printf("%d  ",a[i]);
}
}