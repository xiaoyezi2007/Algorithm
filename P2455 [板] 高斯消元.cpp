#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
double eq[111][111];
double ans[111];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) cin >> eq[i][j];
    int nwline = 1;
    for(int i=1;i<=n;i++)
    {
        int r = nwline;
        for(int j=nwline+1;j<=n;j++)
        {
            if(fabs(eq[r][i])<fabs(eq[j][i]))
            {
                r=j;
            }
        }
        if(fabs(eq[r][i])<ep) // no main yuan
        {
            continue;
        }
        for(int j=1;j<=n+1;j++)
        {
            swap(eq[nwline][j],eq[r][j]);
        }
        for(int j=1;j<=n;j++)
        {
            if(j==nwline) continue;
            double div = eq[j][i]/eq[nwline][i];
            for(int k=i;k<=n+1;k++)
            {
                eq[j][k]-=eq[nwline][k]*div;
            }
        }
        nwline++;

    }
    if(nwline <= n)
    {
        while(nwline<=n) {if(fabs(eq[nwline++][n+1])>=ep) {cout << "-1";return 0;}} //no solution if the last column not all 0
        cout << "0"; // else infinity solution
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        printf("x%d=%.2f\n",i,eq[i][n+1]/eq[i][i]);
    }
}

//by xiaoyezi2007
