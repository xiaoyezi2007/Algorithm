#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 500005
int fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],dfn[MAXN],rnk[MAXN];
// father,depth,sub-tree size,son with max sub-tree, top of chain, dfs order, rnk[dfs[x]]=x
vector<int> edge[MAXN];
int cnt = 0;
void dfs1(int o) //o is this node
{
    son[o] = -1;
    siz[o] = 1;
    for (int x : edge[o])
    {
        if (x==fa[o]) continue;
        dep[x] = dep[o] + 1;
        fa[x] = o;
        dfs1(x);
        siz[o] += siz[x];
        if (son[o] == -1 || siz[x] > siz[son[o]]) son[o] = x;
    }
}

void dfs2(int o, int t) // o is this node and t is top of chain
{
    top[o] = t;
    cnt++;
    dfn[o] = cnt;
    rnk[cnt] = o;
    if (son[o] == -1) return;
    dfs2(son[o], t);  // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
    for (int x : edge[o])
    {
        if(x!=son[o]&&x!=fa[o]) dfs2(x,x);
    }
}


int queryLCA(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]>dep[top[y]])
        {
            x=fa[top[x]];
        }
        else
        {
            y=fa[top[y]];
        }
    }
    return dep[x]>dep[y] ? y : x;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m,s;
    cin >> n >> m >> s;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin >> u >>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs1(s);   //two dfs to got chain!
    dfs2(s,s);

    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        cout << queryLCA(x,y) << '\n';
    }

}

//by xiaoyezi2007
