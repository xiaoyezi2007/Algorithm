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
int a[3005];
vector<int> edge[3005];
int d[3005];
int tim[6005];
ll dp[3005];
void bfs(int n,int s)
{
    int q[3005];
    int vis[3005]={0};
    int l=0,cnt=0;
    q[cnt++]=s;
    vis[s]=1;
    while(l<cnt)
    {
        for(int x : edge[q[l]])
        {
            if(vis[x]!=1)
            {
                q[cnt++]=x;
                d[x]=d[q[l]]+1;
                vis[x]=1;
            }
        }
        l++;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m,t;
    cin >> n >> m >> t;
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        if(u!=v)
        {
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
    bfs(n,1);
    //for(int i=1;i<=n;i++) printf("%d\n",d[i]);
    for(int i=2;i<=n;i++)
    {
        int time=2*d[i];
        if(a[tim[time]]<a[i]) tim[time]=i;
    }
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(dp[i]<dp[j]+a[tim[i-j]]) dp[i]=dp[j]+a[tim[i-j]];
        }
        cout << dp[i] << " ";
    }

    by xiaoyezi2007;
}
