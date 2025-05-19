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
pair<double,double> intersection(double L1x1,double L1y1,double L1x2,double L1y2,double L2x1,double L2y1,double L2x2,double L2y2)
{
    double dirL1[2]={L1x2-L1x1,L1y2-L1y1};
    double dirL2[2]={L2x2-L2x1,L2y2-L2y1};
    double diru[2]={L1x2-L2x2,L1y2-L2y2};
    double T = (diru[0]*dirL2[1]-diru[1]*dirL2[0])/(dirL1[0]*dirL2[1]-dirL1[1]*dirL2[0]);
    return make_pair(L1x2-T*dirL1[0],L1y2-T*dirL1[1]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll a[10];
    ll b[10];
    ll cnta=0,cntb=0;
    for(int i=0;i<5;i++)
    {
        cin >> a[i];
        cnta+=a[i];
    }
    for(int i=0;i<5;i++)
    {
        cin >> b[i];
        cntb+=b[i];
    }
    if(cnta>=cntb) cout << "Blue";
    else cout << "Red";

    by xiaoyezi2007;
}
