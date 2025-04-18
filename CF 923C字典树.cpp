#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
ll a[300005];
ll p[300005];
ll cnt=0;
int nxt[9000005][2];
int exist[9000005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        ll t=0;
        for(int j=29;j>=0;j--)
        {
            ll x=(p[i]>>j)&1ll;
            if(!nxt[t][x]) nxt[t][x]=++cnt;

            t=nxt[t][x];
            exist[t]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        ll t=0;
        ll ans=0;
        for(int j=29;j>=0;j--)
        {
            ll x=(a[i]>>j)&1ll;

            if(exist[nxt[t][x]]==0)
            {
                ans|=((x^1ll)<<j);
                exist[nxt[t][x^1ll]]--;
                t=nxt[t][x^1ll];
            }
            else
            {
                ans|=((x)<<j);
                exist[nxt[t][x]]--;
                t=nxt[t][x];
            }
        }
        ans^=a[i];
        cout << ans << " ";
    }


    return 0;
}
//by xiaoyezi2007
