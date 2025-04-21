#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
vector<int> edge[30];
ll dp[1<<19][20]; // ״ѹdp,dp[s][i]��s��¼�ߵ����ĵ㣬iһ��·������һ���㡣dp����s��Щ�������һ������i��·��������
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
            if(dp[st][i]==0) continue; // �������0���ǲ����Ե��
            for(int j : edge[i])
            {
                if((st&-st)>(1<<(j-1))) continue;  //ÿ����ֻ�ӱ����С�ĵ㿪ʼ������������˱�Ÿ�С�ĵ����������ߡ�
                if(st&(1<<(j-1)))
                {
                    if((st&-st)==(1<<(j-1))) //�����һ����ǡ�����߹��ı����С�ĵ㣬��ôֱ�Ӽ���ans��
                    {
                        ans+=dp[st][i];
                    }
                }
                else
                {
                    dp[st|(1<<(j-1))][j]+=dp[st][i]; //��������ǣ���ô������ǰ�߲�����s��i
                }
            }
        }
    }
    cout << (ans-m)/2; // ����ÿ�������Դӱ����С�ĵ㿪ʼ�������������ߣ��������ּ��㷽��������ÿ��������һ����Ԫ������Ҫ���������������

}

//by xiaoyezi2007
