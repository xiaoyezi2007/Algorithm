#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
bool cmp(const array<int,3> a,const array<int,3> b)
{
    return a[2]<b[2];
}
int d[450][450][450];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,q;
        cin >> n >> m >> q;
        vector<array<int,3>> edge(m);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            v--;
            u--;
            edge[i]={u,v,w};
        }
        sort(edge.begin(),edge.end(),cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[0][i][j]=1e9;
            }
        }
        for(int i=0;i<n;i++)
        {
            d[0][i][i]=0;
        }
        for(array<int,3> e : edge)
        {
            int v=e[0],u=e[1];
            d[0][u][v]=d[0][v][u]=1;
        }
        for(int h=0;h<n;h++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    d[0][i][j]=min(d[0][i][j],d[0][i][h]+d[0][h][j]);
                }
            }
        }
        vector<int> ans(m+1);
        int cnt=1;
        int newest=0;
        for(array<int,3> e:edge)
        {
            int u=e[0],v=e[1],w=e[2];
            if(d[newest][u][v]>0) // if d between two node is 0,change edge between them to 0 make no sence
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        d[cnt][i][j]=min({d[cnt-1][i][j],d[cnt-1][i][u]+d[cnt-1][v][j],d[cnt-1][i][v]+d[cnt-1][j][u]});
                    }
                }
                newest=cnt;
                ans[cnt++]=w;
            }

        }
        while(q--)
        {
            int u,v,k;
            cin >> u >> v >> k;
            u--;
            v--;
            int l=0,r=n-1;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(d[mid][u][v]<k)
                {
                    r=mid;
                }
                else
                {
                    l=mid;
                }
            }
            cout << ans[r] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
//by xiaoyezi2007
