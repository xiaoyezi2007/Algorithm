#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
int len=0;
long long int ans=0;
char s[10005];
long long int v[10005];
int a[10005];
long long int dp[3][10005];


int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n-3;i++)
    {
        scanf("%lld",&v[i]);
    }
    int cnts=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='s')
        {
            cnts++;
        }
        if(s[i]=='p'&&cnts>0)
        {
            s[i]='!';
            cnts--;
        }
    }
    int cnto=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o')
        {
            cnto++;
        }
        if(s[i]=='!')
        {
            a[len++]=cnto;
        }
    }
    if(len==0)
    {
        printf("0");
        return 0;
    }
    for(int i=2;i<=a[0] && i<=cnto/len;i++)
    {
        dp[0][i]=v[i-2];
    }
    for(int x=1;x<len;x++)
    {
        for(int i=0;i<=a[x-1];i++)
        {
            for(int j=2;j<=(cnto-i)/(len-x) && i+j<=a[x];j++)
            {
                dp[x%2][i+j]=max2(dp[x%2][i+j],dp[(x+1)%2][i]+v[j-2]);
            }
        }
    }
    long long int ans=0;
    for(int i=0;i<=cnto;i++)
    {
        ans = max2(ans,dp[(len-1)%2][i]);
    }
    printf("%lld",ans);

}
