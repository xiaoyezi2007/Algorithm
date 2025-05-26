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
int a[1000005];
int pre[1000005];
int lg[1000005];
int st[1000005][30];
int query(int x,int y)
{
    int l=lg[y-x+1];
    if(st[x][l]<=st[y-(1<<l)+1][l]) return st[x][l];
    else return st[y-(1<<l)+1][l];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        cout << max(0,n-(k-1)/2) << " " << min(2*n,n+k/2) << '\n';
    }




    by xiaoyezi2007;
}
