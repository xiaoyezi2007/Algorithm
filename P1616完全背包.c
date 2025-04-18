#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
long long int w[10005],v[10005],f[10000005];
int main()
{
    long long int t,m;
    scanf("%lld%lld",&t,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld",&w[i],&v[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=w[i];j<=t;j++)
        {
            if(f[j]<=f[j-w[i]]+v[i]) f[j]=f[j-w[i]]+v[i];
        }
    }
    printf("%lld",f[t]);
}
