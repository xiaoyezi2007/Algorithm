#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
ll a[500005];
ll t1[500005], t2[500005];
int n;
void build()
{
    for (int i = 1;i<=n;i++)
    {
        t1[i]+=(a[i]-a[i-1]); // t1 is a BST of d[i], d[i] = a[i] - a[i-1]
        int j = i + (i&-i);
        if(j<=n) t1[j]+=t1[i];
    }
    for (int i = 1;i<=n;i++)
    {
        t2[i]+=(a[i]-a[i-1])*i;// t2 is a BST of i*d[i]
        int j = i + (i&-i);
        if(j<=n) t2[j]+=t2[i];
    }
}
ll get_sum(ll *t, ll x) // get sum of [1,x]
{
    ll ans = 0;
    while(x > 0)
    {
        ans+=t[x];
        x -= x&-x;
    }
    return ans;
}
ll sum_of_a(ll l, ll r)
{
    return (r+1)*get_sum(t1,r)-l*get_sum(t1,l-1)-(get_sum(t2,r)-get_sum(t2,l-1));
    //sum of [l,r] = \sigema(d_i*(r+1)) - \sigema(d_i * i)
}
void add(ll x, ll k)
{
    int k1 = x*k; // pay attention: must got v1 at first, because x would change.
    while(x<=n)
    {
        t1[x]+=k, t2[x]+=k1;
        x+=x&-x;  // x+lowerbit(x) is x's father
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    build();
    while(m--)
    {
        int op;
        ll x,y;
        cin >> op ;
        if (op == 1) // add k of a[l]~a[r]
        {
            ll l,r,k;
            cin >> l >> r >> k;
            add(l,k), add(r+1,-k);
        }
        else if (op == 2) //sum of [l,r] , but in this question is [x,x]
        {
            ll x;
            cin >> x;
            cout << sum_of_a(x,x) << '\n';
        }
    }

}

//by xiaoyezi2007
