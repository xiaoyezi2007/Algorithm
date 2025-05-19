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
int ans[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    if(n%4==2||n%4==3) cout << "-1";
    else if(n==4) cout << "7 3 1 2";
    else if(n==5) cout << "1 7 3 4 5";
    else if(n%4==0)
    {
        for(int i=2;i<=n;i+=2)
        {
            ans[i]=n/2-i/2+1;
        }
        ans[n-1]=n/2+1;
        ans[n/2-1]=n+2;
        int cnt=n+3;
        for(int i=n-3;i>=3;i-=2)
        {
            if(i==n/2-1) continue;
            ans[i]=cnt;
            cnt++;
        }
        ans[1]=n/4*7;
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
    }
    else
    {
        n--;
        for(int i=2;i<=n;i+=2)
        {
            ans[i]=n/2-i/2+1;
        }
        ans[n+1]=n/2+1;
        ans[n/2-1]=n+2;
        int cnt=n+3;
        for(int i=n-1;i>=3;i-=2)
        {
            if(i==n/2-1) continue;
            ans[i]=cnt;
            cnt++;
        }
        ans[1]=n/4*7+1;
        for(int i=1;i<=n+1;i++) cout << ans[i] << " ";
    }


    by xiaoyezi2007;
}
