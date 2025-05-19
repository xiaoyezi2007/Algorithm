#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define xiaoyezi2007 0
#define by return
#define ep 1e-7
#define mod  (1llu<<63)
#define ll long long int
#define ull unsigned long long int
#define MAXN 3000
ll w[1005];
vector<pair<int,int>> edge[60];
vector<pair<int,int>> e[60];
ll ans[60];
ll tim[1005];
void bfs(int node)
{
    int q[60];
    int cntq=0;
    int vis[60];
    for(int i=0;i<=50;i++) vis[i]=0;
    int l=0;
    q[cntq++]=node;
    vis[node]=1;
    while(l<cntq)
    {
        for(pair<int,int> p : edge[q[l]])
        {
            int v=p.first;
            int company=p.second;
            if(vis[v]==0)
            {
                vis[v]=vis[q[l]]+1;
                e[q[l]].push_back({v,company});
                q[cntq++]=v;
            }
            else if(vis[v]==vis[q[l]]+1)
            {
                e[q[l]].push_back({v,company});
            }
        }
        l++;
    }
}
void dfs(int node,ll cost)
{
    if(cost<ans[node]) ans[node] = cost;
    for(pair<int,int> p : e[node])
    {
        int v=p.first;
        int company=p.second;
        tim[company]++;
        dfs(v,cost+tim[company]*w[company]);
        tim[company]--;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        edge[u].push_back({v,c});
        edge[v].push_back({u,c});
    }
    bfs(1);
    for(int i=2;i<=n;i++) ans[i]=1e9+7;
    dfs(1,0);
    for(int i=2;i<=n;i++) cout << ans[i] << '\n';

    by xiaoyezi2007;
}
