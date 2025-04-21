#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
vector<int> edge[30];
ll dp[1<<19][20]; // 状压dp,dp[s][i]，s记录走到过的点，i一条路径最后的一个点。dp经过s这些点且最后一个点是i的路径个数。
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    {
        dp[1<<(i-1)][i]=1;
    }
    for(int st=1;st<(1<<n);st++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp[st][i]==0) continue; // 如果等于0就是不可以到达。
            for(int j : edge[i])
            {
                if((st&-st)>(1<<(j-1))) continue;  //每个环只从编号最小的点开始计数，如果来了编号更小的点则跳过不走。
                if(st&(1<<(j-1)))
                {
                    if((st&-st)==(1<<(j-1))) //如果下一个点恰好是走过的编号最小的点，那么直接加入ans。
                    {
                        ans+=dp[st][i];
                    }
                }
                else
                {
                    dp[st|(1<<(j-1))][j]+=dp[st][i]; //如果都不是，那么继续向前走并更新s和i
                }
            }
        }
    }
    cout << (ans-m)/2; // 由于每个环可以从编号最小的点开始沿着两个方向走，并且这种计算方法会额外对每条边视作一个二元环，需要处理这两种情况。

}

//by xiaoyezi2007
