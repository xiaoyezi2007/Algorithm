#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
int pos[500005];
int q[1000005];
int qcnt = 1;
vector<int> edge[500005];
int visit[500005];
int st[1000005][30];
int lg[1000005];
void dfs(int node)
{
    visit[node] = 1;
    pos[node] = qcnt;
    q[qcnt++] = node;
    for(int x : edge[node])
    {
        if(visit[x]==0)
        {
            dfs(x);
            q[qcnt++] = node;
        }
    }
}
void st_build(int n)
{
    for(int i=2;i<=n;i++)
    {
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=n;i++)
    {
        st[i][0] = q[i];
    }
    for(int j=1;j<=lg[n];j++)
    {
        for(int i=1;i<=n-(1<<j)+1;i++)
        {
            if(pos[st[i][j-1]]<=pos[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
}
int st_query(int x,int y)
{
    int l=lg[y-x+1];
    if(pos[st[x][l]]<=pos[st[y-(1<<l)+1][l]]) return st[x][l];
    else return st[y-(1<<l)+1][l];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m,s;
    cin >> n >> m >> s;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(s);
    st_build(2*n-1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        cout << st_query(min(pos[x],pos[y]),max(pos[x],pos[y])) << '\n';
    }
}

//by xiaoyezi2007
