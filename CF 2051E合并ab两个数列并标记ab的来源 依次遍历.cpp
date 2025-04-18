#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
ll a[200005],b[200005];
bool cmp(pair<ll,int> a,pair<ll,int> b)
{
    return a.first<b.first;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<pair<ll,int>> q(2*n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            q[i]={a[i],1};
        }
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            q[i+n]={b[i],0};
        }
        sort(q.begin(),q.end(),cmp);
        int man=n,neg=0;
        ll ans=n*q[0].first;
        for(int i=1;i<2*n;i++)
        {
            if(q[i-1].second==1)
            {
                neg++;
                if(neg<=k&&q[i].first!=q[i-1].first) ans=max(ans,man*q[i].first);
            }
            else
            {
                man--;
                neg--;
                if(neg<=k&&q[i].first!=q[i-1].first) ans=max(ans,man*q[i].first);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//by xiaoyezi2007
