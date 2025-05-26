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
int a[100005];
vector<int> divsor[100005];
set<int> st[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for(int i=2;i<=100000;i++)
    {
        for(int j=1;i*j<=100000;j++)
        {
            divsor[i*j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            st[a[i]].insert(i);
        }
        while(q--)
        {
            ll k,l,r;
            ll ans=0;
            cin >> k >> l >> r;
            vector<int> id;
            for(int x : divsor[k])
            {
                auto it = st[x].lower_bound(l);
                if(it!=st[x].end()&&*it<=r) id.push_back(*it);
            }
            sort(id.begin(),id.end());
            int last=l;
            for(int x : id)
            {
                ans+=k*(x-last);
                while(k%a[x]==0) k/=a[x];
                last=x;
            }
            ans+=k*(r-last+1);
            cout << ans << '\n';
        }
        for(int i=1;i<=n;i++) st[a[i]].clear();
    }


    by xiaoyezi2007;
}
