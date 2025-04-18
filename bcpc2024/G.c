#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005

long long int gcdf(long long int a,long long int b)
{
    long long int i;
    if(a<b)
        {
            i=a;
            a=b;
            b=i;
        }
    if(b==0)
        return a;
    while(a%b!=0)
    {
        i=a%b;
        a=b;
        b=i;

    }
    return b;
}
long long int a[200005];
long long int b[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int cnta=0,cntb=0;
        long long int ans=0;
        long long int x,y;
        long long int tmp=0;
        scanf("%lld%lld",&x,&y);
        if(y>1e8) tmp=1e5;
        else if(y>1e6) tmp=1e4;
        else tmp=1e3;
        for(int i=1;i<=tmp+1;i++)
        {
            if(x%i==0)
            {
                a[cnta++]=i;
            }
            if(y%i==0)
            {
                b[cntb++]=i;
            }
        }
        for(int i=0;i<cnta;i++)
        {
            if(x/a[i]<=a[i]) break;
            else
            {
                a[cnta++]=x/a[i];
            }
        }
        for(int i=0;i<cntb;i++)
        {
            if(y/b[i]<=b[i]) break;
            else
            {
                b[cntb++]=y/b[i];
            }
        }
        for(long long int i=0;i<cnta;i++)
        {
            for(long long int j=0;j<cntb;j++)
            {
                long long int mul=a[i]*b[j];
                long long int g=gcdf(a[i],b[j]);
                mul/=g;
                if(y/mul>x/mul && ((y/mul-x/mul>1) || (y%mul!=0)))
                {
                    if(ans<a[i]+b[j]) ans=a[i]+b[j];
                }
            }
        }
        printf("%lld\n",ans);
    }

}
