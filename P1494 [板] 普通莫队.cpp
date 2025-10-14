#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  998244353
#define ll long long int
#define MAXN 500005
int n,m;
struct node
{
    int l,r,num; // ask [l,r] and this is num-th query
} q[MAXN]; // query
int a[MAXN]; // color
int id[MAXN]; // which block does the i-th color in
ll ans[MAXN][2]; // ans[0] for fenzi and ans[1] for fenmu
int l = 1,r = 0; // l,r now , l init in 1 to avoid RE
ll sum; // contribution now
int s[MAXN]; // color sum now
bool cmp(node x,node y)
{
    if(id[x.r] == id[y.r]) return x.l < y.l; // if x.r and y.r in the same block,then sort by l
    return x.r < y.r; // otherwise, sort by r
}
void add(int x)
{
    sum -= s[a[x]]*(s[a[x]]-1)/2;
    s[a[x]]++;
    sum += s[a[x]]*(s[a[x]]-1)/2;
}
void del(int x)
{
    sum -= s[a[x]]*(s[a[x]]-1)/2;
    s[a[x]]--;
    sum += s[a[x]]*(s[a[x]]-1)/2;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void solve()
{
    cin >> n >> m;
    int sz = n/sqrt(m);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        id[i] = (i-1)/sz + 1;
    }
    for(int i=1;i<=m;i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].num = i;

    }
    sort(q+1,q+m,cmp);
    for(int i=1;i<=m;i++)
    {
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        ans[q[i].num][0] = sum;
        ans[q[i].num][1] = (1ll*r-l+1)*(r-l)/2;
    }
    for(int i = 1;i<=m;i++)
    {
        if(ans[i][0] == 0) cout << "0/1\n";
        else
        {
            ll g = gcd(ans[i][0],ans[i][1]);
            cout << ans[i][0]/g << '/' << ans[i][1]/g << '\n';
        }
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
