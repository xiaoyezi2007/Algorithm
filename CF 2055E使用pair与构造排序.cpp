#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
    int flaga,flagb;
    if(a.first<a.second) flaga=0;
    else if(a.first==a.second) flaga=1;
    else flaga=2;
    if(b.first<b.second) flagb=0;
    else if(b.first==b.second) flagb=1;
    else flagb=2;
    if(flaga != flagb) return flaga<flagb;
    if(flaga==0) return a.first<b.first;
    if(flaga==1) return a.first>b.first;
    if(flaga==2) return a.second>b.second;
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<ll,ll>> data(n);
        ll asum=0,bsum=0;
        for(int i=0;i<n;i++)
        {
            cin >> data[i].first >> data[i].second;  // first for ai and second for bi
            asum+=data[i].first;
            bsum+=data[i].second;
        }
        sort(data.begin(),data.end(),cmp);
        vector<ll> pre(n);
        vector<ll> suf(n);
        vector<ll> sum(n);
        ll ans=1e18;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                sum[i]=data[i].first;
                pre[i]=sum[i];
            }
            else
            {
                sum[i]=sum[i-1]+data[i].first-data[i-1].second;
                pre[i]=max(pre[i-1],sum[i]);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                suf[i]=sum[i];
            }
            else
            {
                suf[i]=max(suf[i+1],sum[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(bsum-data[i].second>=asum)
            {
                if(i==0)
                {
                    ans=min(ans,suf[i+1]-(data[i].first-data[i].second));
                }
                else if(i==n-1)
                {
                    ans=min(ans,pre[i]);
                }
                else
                {
                    ans=min(ans,max(pre[i-1],suf[i+1]-(data[i].first-data[i].second)));
                }
            }
        }
        if(ans==1e18) cout << "-1" << '\n';
        else cout << ans+asum << '\n';
    }
    return 0;
}
//by xiaoyezi2007
