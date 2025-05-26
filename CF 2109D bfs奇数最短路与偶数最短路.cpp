#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  1000000007
#define ll long long int
#define MAXN 500005
int a[200005];
vector<int> edge[200005];
int vis[200005][2];
int q[400005];
int qp[400005];
void bfs(int node,int n)
{
    int l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        vis[i][0]=vis[i][1]=2000000001;
    }
    qp[r]=0;
    q[r++]=node;
    vis[node][0]=0;
    while(l<r)
    {
        for(int x : edge[q[l]])
        {
            if(vis[x][qp[l]^1]>vis[q[l]][qp[l]]+1)
            {
                vis[x][qp[l]^1]=vis[q[l]][qp[l]]+1;
                q[r]=x;
                qp[r]=(qp[l]^1);
                r++;
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

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        ll sum=0;
        int ji=10001;
        cin >> n >> m >> k;
        for(int i=1;i<=k;i++)
        {
            cin >> a[i];
            sum+=a[i];
            if(a[i]%2&&a[i]<ji) ji=a[i];
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        bfs(1,n);
        for(int i=1;i<=n;i++)
        {
            if(i==1) cout << "1";
            else if(vis[i][sum%2]<=sum||(ji!=10001&&vis[i][(sum+1)%2]<=sum-ji)) cout << "1";
            else cout << "0";
        }
        cout << '\n';
        for(int i=1;i<=n;i++) edge[i].clear();
    }


}

//by xiaoyezi2007
