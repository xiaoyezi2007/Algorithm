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
        if(d[u[i]]<d[v[i]]||(d[u[i]]==d[v[i]]&&u[i]<v[i])) //����ƫ�򣺶�����ָ������ߣ����������ͬ���ŵ�ָ���Ÿߡ�����Ԫ���������A->B,B->C,A->C�����ӣ�����A��֤Ψһ
        {
            edge[u[i]].push_back(v[i]);
        }
        else
        {
            edge[v[i]].push_back(u[i]);
        }
    }
    for(int i=1;i<=n;i++) //ö��һ����A
    {
        for(int j:edge[i]) connect[j] = true; //��ʼ������Aָ��ĵ�C
        for(int j:edge[i]) //ö�������ָ��ĵ�B
        {
            for(int k:edge[j]) //ö��Bָ��ĵ�C
            {
                if(connect[k]) ans++; //�ж�A�Ƿ�ָ��C
            }
        }
        for(int j:edge[i]) connect[j] = false;
    }
    cout << ans;

}

//by xiaoyezi2007
