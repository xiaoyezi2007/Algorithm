#include<stdio.h>
#include<math.h>
long long int a[200010];
int main()
{
    int n,m,l,r,x,ans=0,i;
    long long int lim,sum=0;
    scanf("%d%d%lld",&n,&m,&lim);
    while(m--)
    {
        scanf("%d%d%d",&l,&r,&x);
        a[l]+=x;
        a[r+1]-=x;
    }
    for(i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum>=lim)
            ans++;

    }
    printf("%d",ans);


}
