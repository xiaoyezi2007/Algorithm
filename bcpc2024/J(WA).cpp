#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
vector<int> child[1000005];
int f[1000005];
long long int fang[1000005];
long long int d[1000005];
long long int ans[1000005];
long long int otherd[1000005];
long long int center[1000005];
long long int num[1000005];
long long int layer[1000005];
int n;
void handle_d(int node)
{
    if(child[node].size()==0)
    {
        d[node]=0;
        return;
    }
    for(int x:child[node])
    {
        handle_d(x);
    }
    for(int x:child[node])
    {
        d[node]+=d[x]+num[x];
    }
    return;
}
void handle_num(int node)
{
    if(child[node].size()==0)
    {
        num[node] = 1;
        return;
    }
    for(int x:child[node])
    {
        handle_num(x);
    }
    for(int x:child[node])
    {
        num[node]+=num[x];
    }
    return;
}
void handle_fang(int node)
{
    center[node]=node;
    if(child[node].size()==0)
    {
        num[node]=1;
        return;
    }
    for(int x:child[node])
    {
        handle_fang(x);
    }
    for(int x:child[node])
    {
        fang[node]+=fang[x]+2*d[x]+num[x];
    }
    ans[node]=fang[node];

    return;
}
void handle_otherd(int node)
{
    for(int x:child[node])
    {
        otherd[x]=otherd[node]-num[x]+(num[1]-num[x]);
        handle_otherd(x);
    }
    return;
}
void dfs(int node)
{
    for(int x:child[node])
    {
        dfs(x);
        int p=center[x];
        long long int tmp=ans[x]+(fang[node]-(fang[x]+2*d[x]+num[x]))+2*(layer[p]-layer[node])*(d[node]-d[x]-num[x])+(num[node]-num[x])*(layer[p]-layer[node])*(layer[p]-layer[node]);
        //printf("%d %d %lld\n",p,node,tmp);
        while(p!=node)
        {
            //printf("%d %d %lld\n",p,node,2*d[p]+num[p]-2*(otherd[p]-otherd[node]-(num[1]-num[node])*(layer[p]-layer[node]))+(num[node]-num[p]));
            if(2*d[p]+num[p]-2*(otherd[p]-otherd[node]-(num[1]-num[node])*(layer[p]-layer[node]))+(num[node]-num[p])>=0)
            {
                center[node]=p;
                ans[node]=tmp;
                break;
            }
            else
            {
                tmp+=2*d[p]+num[p]-2*(otherd[p]-otherd[node]-(num[1]-num[node])*(layer[p]-layer[node]))+(num[node]-num[p]);
                p=f[p];
            }
            //printf("%d %d %lld\n",p,node,tmp);
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&f[i]);
        child[f[i]].push_back(i);
        layer[i]=layer[f[i]]+1;
    }
    handle_num(1);
    handle_d(1);
    handle_fang(1);
    otherd[1]=d[1];
    handle_otherd(1);

    for(int i=1;i<=n;i++) otherd[i]-=d[i];
    dfs(1);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);


}
//by xiaoyezi2007
