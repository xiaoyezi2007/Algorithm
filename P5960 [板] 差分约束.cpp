#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
ll dis[100005];
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

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int c1,c2,y;
        cin >> c1 >> c2 >> y;
        e[c2].push_back({c1,y}); //if x_c1 - x_c2 <= y then x_c1 <= x_c2 + y so shortpath(c1) <= shortpath(c1) + y,this can be regard as a road from x2 to x1!
    }
    for(int i=1;i<=n;i++)
    {
        e[n+1].push_back({i,0}); // a node with 0 linked to every node.
    }
    if(SPFA(n+1,m,n+1))
    {
        for(int i=1;i<=n;i++) cout << dis[i] << ' ';// see x_ci as shortpath(ci)!
    }
    else
    {
        cout << "NO";
    }
}

//by xiaoyezi2007
