#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
long long int f[70][70]; // f[i][j] = sum of separation of 2^i ,the max in separation is 2^j
long long int dp[70][70]; // when consider one[i] bit , the max in separation is 2^j, how many separation?
int one[70];
int main()
{
    f[0][0]=1;
    for(int i=1;i<=60;i++)
    {
        f[i][i]=1;
        for(int j=0;j<i;j++)
        {
            for(int h=0;h<=j;h++)
            {
                f[i][j]=(f[i][j]+(f[i-1][h]*f[i-1-h][j-h])%mod)%mod;
            }
        }
    }
    long long int x,y;
    long long int ans=0;
    scanf("%lld%lld",&x,&y);
    int t=0;
    while(x<=y)
    {
        long long int que=y-x;
        if(que==0)
        {
            ans++;
            break;
        }
        int cnt=0;
        for(int i=0;i<=60;i++)
        {
            if((que&1ll)==1ll)
            {
                one[cnt++]=i;
            }
            que>>=1ll;
        }
        for(int i=0;i<=one[0]&&i<=t;i++)
        {
            dp[0][i]=f[one[0]][i];
        }
        for(int i=1;i<cnt;i++)
        {
            for(int j=0;j<=t && j<=one[i];j++)
            {
                for(int h=0;h<=j;h++)
                {
                    dp[i][j]=(dp[i][j]+(dp[i-1][h]*f[one[i]-h][j-h])%mod)%mod;
                }
            }
        }
        for(int j=0;j<=t&&j<=one[cnt-1];j++)
        {
            ans=(ans+dp[cnt-1][j])%mod;
        }
        for(int i=0;i<=61;i++)
        {
            for(int j=0;j<=61;j++)
            {
                dp[i][j]=0;
            }
        }
        x*=2;
        t++;
    }
    printf("%lld",ans);
}
