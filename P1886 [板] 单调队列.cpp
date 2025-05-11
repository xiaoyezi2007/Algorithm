#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
int queup[1000005][2];
int quedown[1000005][2];
int ans[1000005][2];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,k;
    int upr=0,upl=0,downr=0,downl=0;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(downl<downr&&quedown[downl][1]<i-k+1) downl++;
        if(upl<upr&&queup[upl][1]<i-k+1) upl++;
        while(upl<upr&&x<queup[upr-1][0]) upr--;
        queup[upr][0]=x;
        queup[upr++][1]=i;
        while(downl<downr&&x>quedown[downr-1][0]) downr--;
        quedown[downr][0]=x;
        quedown[downr++][1]=i;
        ans[i][0]=queup[upl][0];
        ans[i][1]=quedown[downl][0];

    }
    for(int i=k-1;i<n;i++)
    {
        cout << ans[i][0] << ' ';
    }
    cout << '\n';
    for(int i=k-1;i<n;i++)
    {
        cout << ans[i][1] << ' ';
    }
}

//by xiaoyezi2007
