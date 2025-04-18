#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
int n,ans;
vector<int> edge[MAXN];
vector<int> value[MAXN]; // value of the edge
int dp[MAXN]; // dp[i] : the longest path of subtree of i,which must begin from i

void dfs(int node,int father)
{
    for(int i=0;i<edge[node].size();i++)
    {
        if(edge[node][i]==father) continue;
        dfs(edge[node][i],node);
        ans = max2(ans,dp[node]+dp[edge[node][i]]+value[node][i]); // the path of dp[node] and dp[edge[node][i]] must be the different path, so ans can be these two path connect
        dp[node] = max2(dp[node],dp[edge[node][i]]+value[node][i]); // the longest path must be its children's longest path plus a edge.
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,val;
        scanf("%d%d%d",&u,&v,&val);
        edge[u].push_back(v),edge[v].push_back(u);
        value[u].push_back(val),value[v].push_back(val);
    }
    dfs(1,0);
    printf("%d\n",ans);
}
//by xiaoyezi2007
