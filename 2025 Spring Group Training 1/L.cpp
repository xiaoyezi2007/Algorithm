#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define xiaoyezi2007 0
#define by return
#define ep 1e-7
#define mod  (1llu<<63)
#define ll long long int
#define ull unsigned long long int
#define MAXN 3000
vector<ll> a[100005];
ll sumrob[100005];
ll sumgive[100005];
int cmp(vector<ll> a1,vector<ll> a2)
{
    if(a1[0]+a1[1]!=a2[0]+a2[1]) return a1[0]+a1[1] > a2[0]+a2[1];
    else return a1[0]>a2[0];

}
int solve(ll x, ll n)
{
    if(x==0) return 1;
    priority_queue<int,vector<int>,greater<int>> q1; // С
    priority_queue<int,vector<int>,less<int>> q2;
    for(int i=0;i<x;i++) {
        q1.push(a[i][0]); if(i>0) sumrob[i] = sumrob[i-1]+a[i][0]; else sumrob[i]=a[i][0];
        q2.push(a[n-i-1][1]); if(i>0) sumgive[n-i-1] = sumgive[n-i]+a[n-i-1][1]; else sumgive[n-i-1]=a[n-i-1][1];
    }
    for(int i=x;i<n-x;i++)
    {
        if(a[i][0]>q1.top())
        {
            sumrob[i]=sumrob[i-1]+a[i][0]-q1.top();
            q1.pop();
            q1.push(a[i][0]);
        }
        else sumrob[i] = sumrob[i-1];
        if(a[n-i-1][1]<q2.top())
        {
            sumgive[n-i-1]=sumgive[n-i]+a[n-i-1][1]-q2.top();
            q2.pop();
            q2.push(a[n-i-1][1]);
        }
        else sumgive[n-i-1]=sumgive[n-i];
    }
    int idx = x-1;
    while(idx < n-x) {

        if(sumrob[idx] >= sumgive[idx+1]) return 1;
        idx++;
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        a[i].push_back(x);
    }
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        a[i].push_back(x);
    }
    sort(a,a+n,cmp);
    ll ans=0;
    ll l=0,r=n/2;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(solve(mid,n)==1) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout << ans;

    by xiaoyezi2007;
}
