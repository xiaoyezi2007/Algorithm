#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
ll edge[100005][3];
ll dis[100005];
ll INF = 1000000007;
bool Bellman_ford(int n,int m,int s)  //O(mn)
{
    for(int i=1;i<=n;i++) dis[i]=1000000000;
    dis[s] = 0;
    bool flag = false;
    for(int i=0;i<n-1;i++)
    {
        flag = false;
        for(int j=0;j<m;j++)
        {
            int u = edge[j][0];
            int v = edge[j][1];
            ll w = edge[j][2];
            if(dis[u]==INF) continue; // if u cannot arrive now, then v cannot arrive as well
            if(dis[v]>dis[u]+w)
            {
                flag = true;
                dis[v] = dis[u] + w;
            }
        }
        if(!flag) break;
    }
    return flag;
}
vector<pair<int,ll>> e[100005]; //edge[u] pair<v,w>
int cnt[100005],vis[100005];
queue<int> q;
bool SPFA(int n,int m,int s) //faster for random but worst O(mn)
{
    for(int i=1;i<=n;i++) dis[i]=1000000000;
    dis[s] = 0, vis[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop(),vis[u]=0;
        for(pair<int,ll> p : e[u])
        {
            int v = p.first;
            int w = p.second;
            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return false;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m,s;//query the shortest path from s to every node,when n nodes and m edges
    cin >> n >> m >> s;
    for(int i=0;i<m;i++)
    {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        e[edge[i][0]].push_back({edge[i][1],edge[i][2]});
    }
    if(SPFA(n,m,s))
    {
        for(int i=1;i<=n;i++) cout << dis[i] << ' ';
    }
    else
    {
        cout << "There exist a negative loop which can be arrived from the node s !";
    }
}

//by xiaoyezi2007
