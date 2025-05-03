#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
ll a[605][605];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    ll p;
    cin >> n >> p; // p is mod
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
    ll det = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            while(a[i][i])  //zhanzhuan , so without double!
            {
                ll div=a[j][i]/a[i][i];
                for(int k=i;k<n;k++)
                {
                    a[j][k]=(a[j][k]-div*a[i][k]%p+p)%p;
                }
                swap(a[i],a[j]);
                det=-det;
            }
            swap(a[i],a[j]);
            det=-det;
        }
    }
    for(int i=0;i<n;i++) det=det*a[i][i]%p;
    cout << (det+p)%p;
}

//by xiaoyezi2007
