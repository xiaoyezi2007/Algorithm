#include<stdio.h>
#include<math.h>
int a[6000];
int d[6000];
int main()
{
    int n,i,j,max;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        d[i]=1;
    }
    for(i=2;i<=n;i++)
    {
        max=0;
        for(j=1;j<i;j++)
        {
            if(a[j]>=a[i])
            {
                if(max<d[j])
                    max=d[j];
            }
        }
        d[i]+=max;
    }
    max=1;
    for(i=1;i<=n;i++)
    {
        if(max<d[i])
            max=d[i];
    }
    printf("%d",max);

}
