#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char stringss[50];
char pattern[50];
int opcount=0,growth;
printf("enter the string\n");
scanf("%s",stringss);

printf("enter the pattern\n");
scanf("%s",pattern);

int n = strlen(stringss);
int m = strlen(pattern);
int found=0;

for (int i = 0; i <= n-m; i++)
{
    int count=0;
    int k=i;
    for(int j=0; j<m;j++){
        opcount++;
    if (stringss[k]==pattern[j]){
    count++;
    k++;
    }

    }
  if(count == m){
			found = 1;
			break;

}
}
if(found)
		printf("String Found");
	else
		printf("String not found");
	printf("\nOperation Count: %d",opcount);


}
