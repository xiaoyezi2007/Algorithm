#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
int d[200005],u[200005],v[200005];
bool connect[200005];
vector<int>edge[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m;
    ll ans=0;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u[i] >> v[i];
        d[u[i]]++,d[v[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        if(d[u[i]]<d[v[i]]||(d[u[i]]==d[v[i]]&&u[i]<v[i])) //构造偏序：度数低指向度数高，如果度数相同则编号低指向标号高。则三元环变成形如A->B,B->C,A->C的样子，考虑A则保证唯一
        {
            edge[u[i]].push_back(v[i]);
        }
        else
        {
            edge[v[i]].push_back(u[i]);
        }
    }
    for(int i=1;i<=n;i++) //枚举一个点A
    {
        for(int j:edge[i]) connect[j] = true; //初始化所有A指向的点C
        for(int j:edge[i]) //枚举这个点指向的点B
        {
            for(int k:edge[j]) //枚举B指向的点C
            {
                if(connect[k]) ans++; //判断A是否指向C
            }
        }
        for(int j:edge[i]) connect[j] = false;
    }
    cout << ans;

}

//by xiaoyezi2007
