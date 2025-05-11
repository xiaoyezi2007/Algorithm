#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 500005
char s[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    ll x;
    while(t--)
    {
        int n;
        int cnt0=0;
        ll ans=0;
        cin >> n;
        cin >> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0') cnt0++;
            else
            {
                if(cnt0>0) ans+=i+1,cnt0--;
                else cnt0++;
            }
        }
        cout << ans << '\n';
    }


}

//by xiaoyezi2007
