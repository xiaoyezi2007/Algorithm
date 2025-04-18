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

int gcdf(int a,int b)
{
    int i;
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
        int cnta=0,cntb=0;
        int ans=0;
        long long int x,y;
        scanf("%lld%lld",&x,&y);
        for(int i=1;i<=y;i++)
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
            for(int j=0;j<cntb;j++)
            {
                long long int mul=a[i]*b[j];
                int g=gcdf(a[i],b[j]);
                mul/=g;
                if(y/mul>x/mul && ((y/mul-x/mul>1) || (y%mul!=0)))
                {
                    if(ans<a[i]+b[j]) ans=a[i]+b[j];
                }
            }
        }
        printf("%d\n",ans);
    }

}
