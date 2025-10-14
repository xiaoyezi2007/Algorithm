#include<bits/stdc++.h>
using namespace std;
const int N = 35;
const int W = 605;

#define pi pair<int,int>
#define f first
#define s second
#define ep 1e-6
int n, m;
vector<pi> edge[N];

int dp[N][N][700]; // min square sum of weight ,when :last node is i ,len = j, sum of wight is k
double ans = 1000000000;
int arr[N][N];
void ask(int node)
{
    if(!(arr[1][node]&&arr[node][n])) return;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=W;k++) dp[i][j][k] = 100000000;
    dp[node][0][0] = 0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(pi p:edge[k])
                {
                    dp[p.f][i+1][j+p.s] = min(dp[p.f][i+1][j+p.s],dp[k][i][j]+p.s*p.s);
                }
            }
        }
    }
    if(node == 1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                double x_bar = 1.0*j/i;
                ans = min(ans,1.0*dp[n][i][j]/i-x_bar*x_bar);
            }
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            double x_bar = 1.0*j/i;
            ans = min(ans,1.0*dp[node][i][j]/i-x_bar*x_bar);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) edge[i].clear();
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        arr[u][v] = 1;
        edge[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++) arr[i][i] = 1;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) arr[j][k] |= arr[j][i]&arr[i][k];
    for(int i=1;i<=n;i++) ask(i);
    if(ans>1000000000-ep) cout << "-1\n";
    else printf("%.9lf\n",ans);
}

int main() {
    solve();

    return 0;
}
