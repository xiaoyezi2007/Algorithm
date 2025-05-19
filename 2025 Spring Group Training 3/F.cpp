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
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        ll ans;
        ll n,m;
        cin >> n >> m;
        if(n>=m) cout << n-m << '\n';
        else
        {
            ans=1000000000;
            for(ll l=1,r; l<=n;l=r+1)
            {
                r=min(n,(m-1)/((m-1)/l));
                ans=min(ans,n-m+((m-1)/l)*l);
            }
            cout << ans << '\n';
        }

    }


    by xiaoyezi2007;
}
