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
int a[500005];
int d[500005];
int queup[1000005][2];
int quedown[1000005][2];
int ans[1000005][2];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++) d[i]=a[i+1]-a[i];
    int upr=0,upl=0,downr=0,downl=0;
    k--;
    for(int i=0;i<n-1;i++)
    {
        int x=d[i];

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
    ll tmp = 1000000000ll*1000000000;
    //for(int i=k-1;i<n-1;i++) cout << ans[i][1] << " ";
    for(int i=k-1;i<n-1;i++)
    {
        if(1ll*ans[i][0]*(a[i+1]-a[i-k+1]) < tmp) tmp = 1ll*ans[i][0]*(a[i+1]-a[i-k+1]);
    }
    cout << tmp;



    by xiaoyezi2007;
}
