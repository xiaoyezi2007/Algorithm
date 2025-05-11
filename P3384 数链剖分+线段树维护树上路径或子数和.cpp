#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 500005
int fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],dfn[MAXN],rnk[MAXN];
ll in[100005];
long long int a[100005]; // pay attention! the first node is a[1] and d[1]
long long int d[500005]; //no problem if >4*n
long long int b[500005];
// father,depth,sub-tree size,son with max sub-tree, top of chain, dfs order, rnk[dfs[x]]=x
// the dfs order of one chain must be continuous.
vector<int> edge[MAXN];
int cnt = 0;
int MOD,n;
void dfs1(int o)
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

void dfs2(int o, int t)
{
    top[o] = t;
    cnt++;
    dfn[o] = cnt;
    rnk[cnt] = o;
    if (son[o] == -1) return;
    dfs2(son[o], t);  // dfs son[o] first so that dfs in one chain will be continuous.
    for (int x : edge[o])
    {
        if(x!=son[o]&&x!=fa[o]) dfs2(x,x);
    }
}

void build(long long int l,long long int r,long long int p) //left of range , right of range ,the number of range
{
    if(l==r) //when the length of the range is 1
    {
        d[p]=a[l];
        return;
    }
    long long int m=l+((r-l)>>1);
    build(l,m,p<<1),build(m+1,r,(p<<1)+1);
    d[p]=d[p<<1]+d[(p<<1)+1];
}
long long int getsum(long long int l,long long int r,long long int s,long long int t,long long int p)//left and right for query range,left and right for range now,the number of range now
{
    if(l<=s&&r>=t) return d[p];//when now is smaller than query
    long long int m=s+((t-s)>>1);
    if(b[p])// when the signal is exist
    {
        d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p],b[p*2+1]+=b[p];//download the signal to "subnode"
        b[p]=0;// clear signal of this node
    }
    long long int sum=0;
    if(l<=m) sum+=getsum(l,r,s,m,2*p);
    if(r>m) sum+=getsum(l,r,m+1,t,2*p+1);
    return sum;
}
void update(long long int l,long long int r,long long int c,long long int s,long long int t,long long int p)//left and right for query range,plus what?,left and right for range now,the number of range now
{
    if(l<=s&&r>=t)//when now is smaller than query
    {
        d[p]+=(t-s+1)*c;
        b[p]+=c;
        return;
    }
    long long int m=s+((t-s)>>1);
    if(b[p]&&s!=t) //when there already has been a signal
    {
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p], b[p * 2 + 1] += b[p];
        b[p] = 0;
    }
    if(l<=m) update(l,r,c,s,m,p*2);
    if(r>m) update(l,r,c,m+1,t,2*p+1);//always puts the signal to the last range
    d[p]=d[p*2]+d[p*2+1];
}

void add_path(int x,int y,int z)
{
    while(top[x]!=top[y]) // if not in same chain ,calculate this chain to top,and jump to top's father.
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(dfn[top[x]],dfn[x],z,1,n,1);
        x=fa[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    update(dfn[y],dfn[x],z,1,n,1); // if in same chain ,then its dfs order must be continuous
}

int get_sum_path(int x,int y)
{
    ll ans = 0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans = (ans + getsum(dfn[top[x]],dfn[x],1,n,1))%MOD;
        x=fa[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    ans = (ans + getsum(dfn[y],dfn[x],1,n,1)) %MOD;
    return ans;
}

void add_subtree(int x,int z)
{
    update(dfn[x],dfn[x]+siz[x]-1,z,1,n,1); //dfs of a subtree must be continuous!
}

int get_sum_subtree(int x)
{
    return getsum(dfn[x],dfn[x]+siz[x]-1,1,n,1)%MOD;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m,s;
    cin >> n >> m >> s >> MOD;
    for(int i=1;i<=n;i++) cin >> in[i];
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin >> u >>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs1(s);
    dfs2(s,s);

    for(int i=1;i<=n;i++) a[dfn[i]] = in[i];
    build(1,n,1);
    for(int i=0;i<m;i++)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            int x,y,z;
            cin >> x >> y >> z;
            add_path(x,y,z);
        }
        else if(op == 2)
        {
            int x,y;
            cin >> x >> y;
            cout << get_sum_path(x,y) << '\n';
        }
        else if(op == 3)
        {
            int x,z;
            cin >>x >> z;
            add_subtree(x,z);
        }
        else if(op == 4)
        {
            int x;
            cin >>x;
            cout << get_sum_subtree(x) << '\n';
        }
    }

}

//by xiaoyezi2007
