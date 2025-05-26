#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  1000000007
#define ll long long int
#define MAXN 500005
int ans[100005];

void f(int x, int l, int r, int n)
{
    if(n==0) return;
    if(x==0)
    {
        ans[l]=n-2;
        ans[r]=n;
        ans[r-1]=n-3;
        ans[r-2]=n-1;
        ans[r-3]=n-4;
        f(x^1,l+1,r-4,n-5);
    }
    else
    {
        ans[l]=n;
        ans[l+1]=n-3;
        ans[l+2]=n-1;
        ans[l+3]=n-4;
        ans[r]=n-2;
        f(x^1,l+4,r-1,n-5);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    if(n<5) cout << "-1";
    else
    {
        int k=n;
        n/=5;
        n*=5;
        f(0,0,n-1,n);
        for(int i=0;i<n;i++)
        {
            cout << ans[i] << " ";
            if(i==n-4)
            {
                if(k%5>=1) cout << n+1 << " ";
                if(k%5>=4) cout << n+4 << " ";
            }
            else if(i==n-3)
            {
                if(k%5>=2) cout << n+2 << " ";
            }
            else if(i==n-1)
            {
                if(k%5>=3) cout << n+3 << " ";
            }
        }

    }


}

//by xiaoyezi2007
