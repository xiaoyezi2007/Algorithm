#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
char s[2005][2005];
ll dp[5][2005][2005];
ll sumr[5][2005];
ll sumc[5][2005];
ll cntr[2005];
ll cntc[2005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int r,c;
    cin >> r >> c;
    for(int i=0;i<r;i++)
    {
        cin >> s[i];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(s[i][j]=='.') cntr[i]++,cntc[j]++;
        }
    }
    for(int k = 1;k<=4;k++)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(k==1 && s[i][j]=='.')
                {
                    dp[k][i][j] = 1;
                    sumr[k][i]+=dp[k][i][j];
                    sumc[k][j]+=dp[k][i][j];
                }
                else if (s[i][j]=='.')
                {
                    dp[k][i][j]=sumr[k-1][i]+sumc[k-1][j]-2*dp[k-1][i][j];
                    sumr[k][i]+=dp[k][i][j];
                    sumc[k][j]+=dp[k][i][j];
                }

            }
        }
    }
    ll ans = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            ans+=dp[4][i][j]-2*dp[3][i][j]+dp[2][i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        if(cntr[i]>=3) ans-=cntr[i]*(cntr[i]-1)*(cntr[i]-2);
    }
    for(int i=0;i<c;i++)
    {
        if(cntc[i]>=3) ans-=cntc[i]*(cntc[i]-1)*(cntc[i]-2);
    }
    cout << ans;


}

//by xiaoyezi2007
