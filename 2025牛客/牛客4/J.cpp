#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
const int mod = 998244353;
const int MAXN = 205;
int ex[MAXN][MAXN],ey[MAXN][MAXN];
int vis[MAXN][5*MAXN];
int ans[MAXN];
int n;
int dis(int x1,int y1,int x2,int y2,int L,int R)
{
    vector<pi> len[5*MAXN];
    for(int i=0;i<MAXN;i++) for(int j=0;j<5*MAXN;j++) vis[i][j] = INT_MAX;
    int cnt = 0;
    len[0].push_back({x1,y1});
    vis[x1][y1] = 0;
    while(cnt<=2*((x2>x1?x2-x1:x1-x2)+(y2>y1?y2-y1:y1-y2)))
    {
        for(pi p : len[cnt]) if(vis[p.first][p.second] == cnt)
        {
            int x = p.first;
            int y = p.second;
            if(x-1>=0&&vis[x-1][y]>cnt+ey[x-1][y%n])
            {
                vis[x-1][y] = cnt+ey[x-1][y%n];
                len[cnt+ey[x-1][y%n]].push_back({x-1,y});
            }
            if(x+1<n&&vis[x+1][y]>cnt+ey[x][y%n])
            {
                vis[x+1][y] = cnt+ey[x][y%n];
                len[cnt+ey[x][y%n]].push_back({x+1,y});
            }
            if(y-1>=L&&vis[x][y-1]>cnt+ex[x][(y-1)%n])
            {
                vis[x][y-1] = cnt+ex[x][(y-1)%n];
                len[cnt+ex[x][(y-1)%n]].push_back({x,y-1});
            }
            if(y+1<=R&&vis[x][y+1]>cnt+ex[x][y%n])
            {
                vis[x][y+1] = cnt+ex[x][y%n];
                len[cnt+ex[x][y%n]].push_back({x,y+1});
            }
        }
        cnt++;
    }
    //cout << vis[x2][y2];
    return vis[x2][y2];
}

void dis2(int x1,int y1,int x2,int y2)
{
    vector<int> tmp(n);
    if(y1<y2) dis(x1,y1,x2,y2,max(y1-2,0),min(y2+2,5*n-1));
    else dis(x1,y1,x2,y2,max(y2-2,0),min(y1+2,5*n-1));
    if(y1<y2)
    {
        for(int i=0;i<n;i++) tmp[(y1+i)%n] = vis[0][i+y1];
    }
    else
    {
        for(int i=0;i<n;i++) tmp[(y1-i+n)%n] = vis[0][y1-i];
    }
    for(int i=0;i<n;i++) tmp[i]+=vis[x2][y2];
    if(y1<y2) dis(x2,y2,x1,y1,max(y1-2,0),min(y2+2,5*n-1));
    else dis(x2,y2,x1,y1,max(y2-2,0),min(y1+2,5*n-1));
    if(y2<y1)
    {
        for(int i=0;i<n;i++) tmp[(y2+i)%n] += vis[n-1][i+y2];
    }
    else
    {
        for(int i=0;i<n;i++) tmp[(y2-i+n)%n] += vis[n-1][y2-i];
    }
    for(int i=0;i<n;i++) ans[i] = min(ans[i],tmp[i]);
}
void solve()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ans[i] = INT_MAX;
        for(int j=0;j<n;j++)
        {
            cin >> ex[i][j];
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> ey[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        dis(0,i+2*n,n-1,i+n,0,5*n-1);
        ans[i] = min(ans[i],vis[n-1][i+3*n]);
        ans[i] = min(ans[i],vis[n-1][i+n]);
        //cout << ans[i] << '\n';
    }
    for(int i=0;i<n;i++)
    {
        dis2(0,n+i,n-1,n+i+n-1);
        dis2(0,n+i,n-2,n+i+n-1);
        dis2(1,n+i,n-1,n+i+n-1);
        dis2(0,n+i+n-1,n-1,n+i);
        dis2(0,n+i+n-1,n-2,n+i);
        dis2(1,n+i+n-1,n-1,n+i);
    }
    for(int i=0;i<n;i++) cout << ans[i] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int xiaoyezi2007;
    cin >> xiaoyezi2007;

    while(xiaoyezi2007--)
    {
        solve();
    }
}
//by xiaoyezi2007
