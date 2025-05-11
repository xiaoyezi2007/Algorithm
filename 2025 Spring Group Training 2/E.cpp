#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 500005
vector<pair<int,ll>> e[MAXN]; // e[u] {v,w}
ll dis[MAXN];
int vis[MAXN];
vector<pair<int,ll>> re[MAXN];

void dijkstra(int n, int s)
{
    for(int i=1;i<=n;i++) dis[i] = 1e10,vis[i]=0;
    priority_queue<pair<ll,int>> q; //dis and node , init in big top heap
    dis[s]=0;
    q.push({0, s});
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for(pair<int,ll> p : e[x])
        {
            int y=p.first;
            ll w=p.second;
            if(dis[y]>dis[x]+w)
            {
                dis[y]=dis[x]+w;
                q.push({-dis[y],y}); // add a '-' so the heap actually is a small root heap
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m;
    ll c;
    int flag=0;
    cin >> n >> m >> c;
    for(int i=0;i<m;i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        re[v].push_back({u,w});
        if(w<=c) flag=1;
    }
    if(flag==0)
    {
        cout << '0';
        return 0;
    }
    flag=0;
    for(int i=1;i<=n;i++)
    {
        dijkstra(n,i);
        for(pair<int,ll> x : re[i])
        {
            if(dis[x.first]+x.second<=c) flag=1;
        }
    }
    if(flag) cout << '2';
    else cout << '1';


}

//by xiaoyezi2007
