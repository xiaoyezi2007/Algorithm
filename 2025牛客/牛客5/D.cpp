#include<bits/stdc++.h>
using namespace std;
#define M 998244353
vector<int> pri;
int notprime[2000015];
vector<int> edge[1000005];
void init()
{
    int n = 1000005;
    notprime[1] = 1;
    for(int i=2;i<=2000000;i++)
    {
        if(notprime[i]==0) pri.push_back(i);
        for(int x:pri)
        {
            if(i*x>2*n) break;
            notprime[i*x]=1; //all the i*k is not prime
            if(i%x==0) break; //this mean i*k has already been found by x*k
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=max(0,i-100);j<=i+100;j++)
        {
            if(i==j) continue;
            if(!notprime[i^j]) edge[i].push_back(j);
        }
        reverse(edge[i].begin(),edge[i].end());
    }
}
int gotans = 0;

int vis[1000005];
vector<int> ans;
void solve()
{
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "0\n";
        return;
    }
    if(n==2)
    {
        cout << "-1\n";
        return;
    }
    ans.resize(n);
    ans[0] = 0;
    vis[0] = 1;
    for(int i=1;i<n;i++)
    {
        for(int x:edge[ans[i-1]])
        {
            if(x>=n) continue;
            if(!vis[x])
            {
                ans[i] = x;
                vis[x] = 1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
    for(int i=0;i<n;i++) vis[i] = 0;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    init();
    while(t--)
    {
        solve();
    }
    return 0;
}
//by xiaoyezi2007
