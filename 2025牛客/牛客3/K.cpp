#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
const int mod = 998244353;
const int MAXN = 5005;
ll dp[MAXN][MAXN];
int vis[MAXN];
int a[MAXN];
int r[MAXN];
int cnt[MAXN][MAXN]; // cnt[i][j],\sum ( num <=i && (vis pos <=j or vis == 0))
void clear(int n)
{
    for(int i=0;i<=n;i++)
    {
        vis[i] = 0;
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = cnt[i][j] = 0;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    clear(n);
    for(int i=1;i<=n;i++) cin >> a[i],vis[a[i]] = 1;
    for(int i=1;i<=n;i++)
    {
        cnt[i][0]=cnt[i-1][0]+(!vis[i]);
        for(int j=1;j<=n;j++)
        {
            cnt[i][j] = cnt[i][j-1]+(a[j]<=i&&a[j]!=0);
        }
    }
    //for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("!%d",cnt[i][j]);
    int not_vis_min = n+1;
    for(int i=n;i>=1;i--)
    {
        if(vis[i] == 0) not_vis_min = i;
        r[i] = not_vis_min;
    }
    if(a[1] == 0)
    {
        dp[1][r[1]] = 1;
    }
    else
    {
        dp[1][a[1]] = 1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i+1] == 0)
            {
                (dp[i+1][r[j+1]]+=dp[i][j])%=mod;
                if(cnt[j][i+1]>=i+1) (dp[i+1][j]+=i*dp[i][j]%mod)%=mod;
                else if(vis[j]==0) (dp[i+1][r[j+1]]+=i*dp[i][j]%mod)%=mod;
            }
            else
            {
                if(a[i+1]>j)
                {
                    (dp[i+1][a[i+1]]+=dp[i][j])%=mod;
                    if(vis[j] == 0) (dp[i+1][r[a[i+1]+1]]+=i*dp[i][j]%mod)%=mod;
                }
                else if(a[i+1]<j)
                {
                    (dp[i+1][j]+=i*dp[i][j]%mod)%=mod;
                }
            }
        }
    }
    cout << dp[n][n] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int xiaoyezi2007;
    cin >> xiaoyezi2007;

    while(xiaoyezi2007--)
    {
        solve();
    }
}
//by xiaoyezi2007
