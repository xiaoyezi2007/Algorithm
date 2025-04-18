#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 200005


int a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    int zero=0,two=0;
    long long int ans=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0) zero++;
        else if(a[i]==2) two++;
    }
    for(int i=0;i<two-1;i++)
    {
        ans=(ans*2)%mod;
    }
    for(int i=0;i<zero;i++)
    {
        ans=(ans*2)%mod;
    }
    ans=(ans-1+mod)%mod;
    printf("%lld",ans);

}
