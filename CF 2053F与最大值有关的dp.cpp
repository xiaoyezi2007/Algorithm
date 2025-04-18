#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        ll ans=0;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
                if(a[i][j] > 0) a[i][j]--;
            }
        }
        vector<int> cnt(k);
        for(int i=1;i<n;i++) // calculate those fixed
        {
            for(int x:a[i-1])
            {
                if(x>=0) cnt[x]++;
            }
            for(int x:a[i])
            {
                if(x>=0) ans+=cnt[x];
            }
            for(int x:a[i-1]) if(x>=0) cnt[x]=0;
        }
        vector<int> blank(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==-1) blank[i]++;
            }
        }
        vector<ll> dp(k);
        ll mm=0; //the max if any x is not occurred in last line
        ll re_add=0;
        ll mx=0; //the max if x is occurred in last line
        for(int i=1;i<n;i++)
        {
            for(int x:a[i])
            {
                if(x>=0) cnt[x]++; // occurrence of x in the i-th line
            }
            for(int x:a[i])
            {
                if(x>=0&&cnt[x]>0)
                {
                    dp[x]=max(dp[x],mm) + 1LL*blank[i-1]*cnt[x]; // if fill x in the i-1-th line and when we consider a new line

                    mx=max(dp[x],mx);
                    cnt[x]=0;
                }
            }
            ll re=1LL*blank[i-1]*blank[i]; // when fill same with i-1 and i
            for(int x:a[i-1])
            {
                if(x>=0) cnt[x]++; // occurrence of x in the i-1-th line
            }

            ll tmp=mx; // save the max when not fill the new i-th line
            for(int x:a[i-1])
            {
                if(x>=0&&cnt[x]>0)
                {
                    dp[x]=1LL*blank[i]*cnt[x]+max(max(dp[x],mm),max(tmp,mm)-re); // same as x with last line or not same respectively , minus re both

                    mx=max(mx,dp[x]);

                    cnt[x]=0;
                }
            }
            mm=max(mm,tmp-re);

            re_add+=re;

        }

        ans+=max(mx,mm)+re_add;
        cout << ans << '\n';
    }
    return 0;
}
//by xiaoyezi2007
