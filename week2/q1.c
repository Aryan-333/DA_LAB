#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m,n,opcount = 0, gcd;

    printf("enter two number:");
    scanf("%d%d",&n,&m);

    int smallest = m<n ? m:n;

    while (smallest!=0)
    {
        opcount++;
        if (m%smallest==0 && n%smallest == 0)
        {
            gcd = smallest;
            break;
        }
        smallest--;
    }
    
    printf("\n GCD = %d",gcd);
    printf("\n Operation count = %d",opcount);
}

