#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
ll a[3005];
ll f[3005][3005]; //put first i element,and i-th element is a_j, the number of situation.
ll sum[3005][3005];
int pos[3005];
int bd[3005][2];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(a[j]>=a[i]) bd[i][0]=j;
            else break;
        }
        for(int j=i;j<=n;j++)
        {
            if(a[j]>=a[i]) bd[i][1]=j;
            else break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(bd[i][0]==1) f[1][i]=1;sum[1][i]=sum[1][i-1]+f[1][i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(bd[j][0]<=i&&bd[j][1]>=i)
            {
                f[i][j]=sum[i-1][j];
                sum[i][j]=(sum[i][j-1]+f[i][j])%mod;
            }
            else
            {
                f[i][j]=0;
                sum[i][j]=(sum[i][j-1]+f[i][j])%mod;
            }
        }
    }
    cout << sum[n][n];

}

//by xiaoyezi2007
