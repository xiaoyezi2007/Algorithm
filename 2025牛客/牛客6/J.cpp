#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
int ksm(int a, int b){
    int  res = 1;
    while(b) {
        if(b & 1ll)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
vector<int> edge[5005];
int dp[5005][5005][2];
int subsz[5005];
int n;
void dfs(int node,int father)
{
    dp[node][1][1] = 1;
    dp[node][0][0] = 1;
    subsz[node] = 1;
    for(int x:edge[node])
    {
        if(x == father) continue;
        dfs(x,node);
        for(int i=subsz[node]+subsz[x];i>=1;i--)
        {
            for(int j=max(1ll,i-subsz[node]);j<=min(subsz[x],i);j++)
            {
                (dp[node][i][0]+=dp[node][i-j][0]*(dp[x][j][0]+dp[x][j][1])%M)%=M;
                (dp[node][i][1]+=dp[node][i-j][1]*dp[x][j][0]%M)%=M;
            }
        }
        subsz[node] += subsz[x];
    }
}
void init(int node,int father)
{
    for(int x:edge[node])
    {
        if(x==father) continue;
        init(x,node);
        subsz[node]+=subsz[x];
    }
    subsz[node]++;
}
int in[5005];
signed main()
{
    cin >> n;
    in[0] = 1;
    for(int i=1;i<=n;i++) in[i] = in[i-1]*i%M;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    //init(1,0);
    dfs(1,0);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int tmp = (dp[1][i][0]+dp[1][i][1])%M;
        (tmp*=in[i]*in[n-i]%M)%=M;
        int tmp1 = (dp[1][i+1][0]+dp[1][i+1][1])%M;
        (tmp1*=in[i+1]*in[n-i-1]%M)%=M;
        (ans+=(n-i)*(tmp-tmp1+M)%M)%=M;
    }
    cout << ans*ksm(in[n],M-2)%M;
}
