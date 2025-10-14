#include <bits/stdc++.h>
using namespace std;
//O(n^3)
#define ll long long
const ll Maxn=505;
const ll inf=1e18;
ll n,m,mp[Maxn][Maxn],matched[Maxn];
ll slack[Maxn],pre[Maxn],ex[Maxn],ey[Maxn];//ex,ey¶¥±ê
bool visx[Maxn],visy[Maxn];
void match(ll u)
{
    ll x,y=0,yy=0,delta;
    memset(pre,0,sizeof(pre));
    for(ll i=1;i<=n;i++)slack[i]=inf;
    matched[y]=u;
    while(1)
    {
        x=matched[y];delta=inf;visy[y]=1;
        for(ll i=1;i<=n;i++)
        {
            if(visy[i])continue;
            if(slack[i]>ex[x]+ey[i]-mp[x][i])
            {
                slack[i]=ex[x]+ey[i]-mp[x][i];
                pre[i]=y;
            }
            if(slack[i]<delta){delta=slack[i];yy=i;}
        }
        for(ll i=0;i<=n;i++)
        {
            if(visy[i])ex[matched[i]]-=delta,ey[i]+=delta;
            else slack[i]-=delta;
        }
        y=yy;
        if(matched[y]==-1)break;
    }
    while(y){matched[y]=matched[pre[y]];y=pre[y];}
}
ll KM()
{
    memset(matched,-1,sizeof(matched));
    memset(ex,0,sizeof(ex));
    memset(ey,0,sizeof(ey));
    for(ll i=1;i<=n;i++)
    {
        memset(visy,0,sizeof(visy));
        match(i);
    }
    ll res=0;
    for(ll i=1;i<=n;i++)
        if(matched[i]!=-1)res+=mp[matched[i]][i];
    return res;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=-inf;
    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        mp[u][v]=w;
    }
    cout << KM() << '\n';
    for(ll i=1;i<=n;i++) cout << matched[i] << ' '; // matched node with i
    return 0;
}
