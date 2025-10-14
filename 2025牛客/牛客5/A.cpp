#include<bits/stdc++.h>
using namespace std;
#define int long long

int updiv(int x,int y)
{
    return (x-1)/y+1;
}

void solve()
{
    int n,k,s,t;
    cin >> n >> k >> s >> t;
    int K = min(k,n-k);
    int ans = 1000000000;
    if(s%2==t%2)
    {
        if(s==t) ans = 0;
        else if(K!=0) ans = min(ans,2*updiv(abs(s-t),2*K));
    }
    int ls = abs(s-k);
    int rs = n-abs(n-k-s);
    if(ls%2==t%2)
    {
        if(ls<=t&&t<=rs) ans = min(ans,1ll);
        else if(K!=0&&t<ls) ans = min(2*updiv(ls-t,2*K)+1,ans);
        else if(K!=0&&t>rs) ans = min(2*updiv(t-rs,2*K)+1,ans);
    }
    if(ans == 1000000000) cout << "-1\n";
    else cout << ans << '\n';
}

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
