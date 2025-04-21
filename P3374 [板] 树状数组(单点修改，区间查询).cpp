#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
ll a[500005];
ll c[500005];
int n;
// c is BST. c[x] count sum of [x - lowerbit(x) + 1, x], where lowerbit(x) means the lowest 1 of x and those 0 lower than 1
// e.g. lowerbit(b'001100) = b'100 = 8
//lowerbit(x) = x&-x
void build()
{
    for (int i = 1;i<=n;i++)
    {
        c[i]+=a[i];
        int j = i + (i&-i);
        if(j<=n) c[j]+=c[i]; // father can be separate by a set of children they do not intersect.
    }
}
ll get_sum(ll x) // get sum of [1,x]
{
    ll ans = 0;
    while(x > 0)
    {
        ans+=c[x];
        x -= x&-x;
    }
    return ans;
}
void add(ll x, ll k)
{
    while(x<=n)
    {
        c[x]+=k;
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
        cin >> op >> x >> y;
        if (op == 1)
        {
            add(x,y);
        }
        else if (op == 2)  //get sum of [x, y] , which equals to [1,y] - [1,x-1]
        {
            cout << get_sum(y) - get_sum(x-1) << '\n';
        }
    }

}

//by xiaoyezi2007
