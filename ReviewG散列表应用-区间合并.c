#include<stdio.h>
#include<string.h>
int range[1000005];
void f()
{
    int i,n;
    for(i=1;i<=1000002;i++)
    {
        if(range[i]==0)
            continue;
        printf("%d ",i);
        for(n=range[i];i<=n;i++)
        {
            if(range[i]>n)
                n=range[i];
        }
        i--;
        printf("%d\n",i);
    }
}
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        if(b>range[a])
            range[a]=b;
    }
    f();
}
