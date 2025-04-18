#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
char a[1005][1005];
int p[1005];
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
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        ll ans=0;
        for(int x=1;x<=10;x++) // if median is x
        {
            int sum=n;

            vector<int> pre(n);
            vector<int>b(n);
            for(int i=0;i<n;i++) // those less than x think as -1
            {
                if(a[i]>x) b[i]=1;
                else b[i]=-1;
            }
            for(int i=0;i<n;i++) // if pre[i]=pre[j] then i to j is a bad array
            {
                pre[i]=sum;
                sum+=b[i];
            }
            vector<int> cnt(2*n+3);
            sum=n;
            int j=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==x) // only consider those ending in x
                {
                    while(j<=i)
                    {
                        cnt[pre[j]]++;
                        j++;
                    }
                }
                sum+=b[i];
                ans+=cnt[sum];
            }
        }
        ans=1ll*(n+1)*n/2-ans;
        cout << ans << '\n';

    }
    return 0;
}
//by xiaoyezi2007
