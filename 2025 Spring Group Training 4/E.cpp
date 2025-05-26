#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  1000000007
#define ll long long int
#define MAXN 500005
char s[600][600];
int dp[2][505][1005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,x;
        cin >> n >> m >> x;
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1][j-1]=='?')
                {
                    for(int k=0;k<=x;k++)
                    {
                        if(k==0) dp[i&1][j][k]=max(dp[(i&1)^1][j][k],dp[i&1][j-1][k]);
                        else dp[i&1][j][k]=max(max(dp[(i&1)^1][j][k-1],dp[i&1][j-1][k-1]) + 1,max(dp[(i&1)^1][j][k],dp[i&1][j-1][k]));
                    }
                }
                else
                {
                    for(int k=0;k<=x;k++)
                    {
                        dp[i&1][j][k]=max(dp[(i&1)^1][j][k],dp[i&1][j-1][k]) + s[i-1][j-1] - '0';
                    }
                }
            }
        }
        cout << dp[n&1][m][x] << '\n';
        for(int j=1;j<=m;j++) for(int k=0;k<=x;k++) dp[0][j][k]=dp[1][j][k]=0;
    }


}

//by xiaoyezi2007
