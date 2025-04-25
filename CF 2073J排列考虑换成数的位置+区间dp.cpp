#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
int pos[600];
int a[600];
int dp[505][505];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1000000000;
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int len = 1;len < n;len++)
    {
        for(int i=1;i+len<=n;i++)
        {
            for(int k=i+1;k<=i+len;k++)
            {
                dp[i][i+len] = min(dp[i][i+len], dp[i][k-1]+dp[k][i+len]+max(pos[i]-pos[k],pos[k]-pos[i]));
            }
        }
    }
    cout << dp[1][n];

}

//by xiaoyezi2007
