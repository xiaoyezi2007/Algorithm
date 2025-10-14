#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<long long,long long>
#define f first
#define s second
#define ep 1e-6
const int M = 1000000007;
int inv[2005];
int n,W;
int w[10][10];
pi line[30][10];
int cnt[10][10];
int mask = 0;
int xi[2005]; // rongchixishu of W/(w of subset)
int ans[(1<<17)];
int ksm(int a, int b){
    int  res = 1;
    while(b) {
        if(b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
void dfs(int x)
{
    if(x>2*n+2)
    {
        ans[mask] = 0;
        for(int i=1;i<=W;i++) (ans[mask]+=inv[i]*W%M*(M-xi[i])%M)%=M;
        return;
    }
    dfs(x+1);
    //cout << x;
    mask|=(1ll<<(x-1));
    for(int i=1;i<=n;i++)
    {
        int xx = line[x][i].f;
        int yy = line[x][i].s;
        cnt[xx][yy]++;
        if(cnt[xx][yy] == 1)
        {
            for(int i=W-w[xx][yy];i>=0;i--) (xi[i+w[xx][yy]]+=M-xi[i])%=M;
        }
    }

    dfs(x+1);
    mask^=(1ll<<(x-1));
    for(int i=1;i<=n;i++)
    {
        int xx = line[x][i].f;
        int yy = line[x][i].s;
        cnt[xx][yy]--;
        if(cnt[xx][yy] == 0)
        {
            for(int i=0;i<=W-w[xx][yy];i++) (xi[i+w[xx][yy]]+=xi[i])%=M;
        }
    }
}
void solve()
{
    int q;
    cin >> n >> q;
    W = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> w[i][j],(W+=w[i][j])%=M;
    for(int i=1;i<=2*n+2;i++) for(int j=1;j<=n;j++) cin >> line[i][j].f >> line[i][j].s;
    //cout << "?";
    mask = 0;
    xi[0] = 1;
    dfs(1);
    while(q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}

void init()
{
    for(int i=1;i<=2000;i++) inv[i] = ksm(i,M-2);
}

signed main()
{
    init();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
