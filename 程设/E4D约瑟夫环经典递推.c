#include<stdio.h>
#include<math.h>

int main()
{
    int n,k,a,i;
    scanf("%d%d",&n,&k);
    a=0;
    for(i=2;i<=n;i++)
    {
        a=(a+k)%i;
    }
    printf("%d",a+1);

}
