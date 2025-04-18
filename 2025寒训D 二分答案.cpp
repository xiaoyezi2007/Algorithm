#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
vector<pair<ll,ll>> wa;
vector<pair<ll,ll>> v;
vector<pair<ll,ll>> w;
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first<b.first;
}
int solve(ll k,int n)
{
    vector<int> h(n);
    for(int i=0;i<n;i++)
    {
        if(v[i].first<k)
        {
            h[v[i].second]=1;
        }
        else break;
    }
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(h[w[i].second]==1)
        {
            while(p<n&&(h[wa[p].second]!=0||wa[p].first-k<w[i].first)) p++;
            if(p==n) return 0;
            else p++;
        }
        else continue;
    }
    return 1;
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
        int n;
        cin >> n;

        for(int i=0;i<n;i++)
        {
            ll x,y;
            cin >> x >> y;
            w.push_back({y,i});
            wa.push_back({y+x,i});
            v.push_back({x,i});
        }
        sort(w.begin(),w.end(),cmp);
        sort(v.begin(),v.end(),cmp);
        sort(wa.begin(),wa.end(),cmp);
        ll l=0,r=v[n-1].first+10;
        ll ans;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(solve(mid,n)==1) l=mid+1,ans=mid;
            else r=mid-1;
        }
        cout << ans << '\n';
        wa.clear();
        w.clear();
        v.clear();
    }
}
//by xiaoyezi2007
