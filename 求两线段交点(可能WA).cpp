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
pair<double,double> intersection(double L1x1,double L1y1,double L1x2,double L1y2,double L2x1,double L2y1,double L2x2,double L2y2)//require not parallel
{
    double dirL1[2]={L1x2-L1x1,L1y2-L1y1}; //dir of L1
    double dirL2[2]={L2x2-L2x1,L2y2-L2y1};// dir of L2
    double diru[2]={L1x2-L2x2,L1y2-L2y2}; // a dir u that L2node2 point to L1node2
    double T = (diru[0]*dirL2[1]-diru[1]*dirL2[0])/(dirL1[0]*dirL2[1]-dirL1[1]*dirL2[0]); // |u x dirL2|/|dirL1 x dirL2|
    return make_pair(L1x2-T*dirL1[0],L1y2-T*dirL1[1]);// L1node2 - T*dirL1
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    pair<double,double> p=intersection(0,0,1,1,1,0,0,1);
    printf("%lf,%lf",p.first,p.second);

    by xiaoyezi2007;
}
