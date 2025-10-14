#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  998244353
#define ll long long int
#define MAXN 133340
int n,m;
int sz;
struct node
{
    int l,r,t,num; // ask [l,r] and this is num-th query
} q[MAXN]; // query

struct operation
{
    int p,c;
} op[MAXN];
int a[MAXN];
int cntq,cntop;
int s[1000005];
int sum;
int ans[MAXN];
bool cmp(node x,node y)
{
    if(x.l/sz!=y.l/sz)
    {
        return x.l<y.l;
    }
    if(x.r/sz!=y.r/sz)
    {
        return x.r<y.r;
    }
    return x.t<y.t;
}
void add(int x) // x refer to color
{
    s[x]++;
    if(s[x] == 1) sum++;
}
void del(int x)
{
    s[x]--;
    if(s[x] == 0) sum--;
}
void solve()
{
    cin >> n >> m;
    sz = pow(n,2.0/3.0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    char o[3];
    for(int i=1;i<=m;i++)
    {
        cin >> o;
        if(o[0] == 'Q')
        {
            cntq++;
            cin >> q[cntq].l >> q[cntq].r;
            q[cntq].num = cntq;
            q[cntq].t = cntop;
        }
        else if(o[0] == 'R')
        {
            cntop++;
            cin >> op[cntop].p >> op[cntop].c;
        }
    }
    sort(q+1,q+cntq,cmp);
    int l=1,r=0,t=0;
    for(int i=1;i<=m;i++)
    {
        while (l > q[i].l) add(a[--l]);
        while (r < q[i].r) add(a[++r]);
        while (l < q[i].l) del(a[l++]);
        while (r > q[i].r) del(a[r--]);
        while (t < q[i].t)
        {
            t++;
            if(op[t].p>=l&&op[t].p<=r)
            {
                del(a[op[t].p]);
                add(op[t].c);
            }
            swap(op[t].c,a[op[t].p]);
        }
        while (t > q[i].t)
        {
            if(op[t].p>=l&&op[t].p<=r)
            {
                del(a[op[t].p]);
                add(op[t].c);
            }
            swap(op[t].c,a[op[t].p]);
            t--;
        }
        ans[q[i].num] = sum;
    }
    for(int i=1;i<=cntq;i++)
    {
        cout << ans[i] << '\n';
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
}

//by xiaoyezi2007
