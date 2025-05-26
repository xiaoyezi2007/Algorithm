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

    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i]>pre[i-1]) pre[i]=a[i];
        else pre[i]=pre[i-1];
    }
    for(int i=2; i<=n; i++)
    {
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1; i<=n; i++) st[i][0]=a[i];
    for(int j=1; j<=lg[n]; j++)
    {
        for(int i=1; i<=n-(1<<j)+1; i++)
        {
            if(st[i][j-1]<=st[i+(1<<(j-1))][j-1]) st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
    int ans=0;
    for(int k=1; k<=n; k++)
    {
        int flag=0;
        for(int i=1; k*(i-1)+1<=n; i++)
        {
            if(pre[k*(i-1)]>query(k*(i-1)+1,min(k*i,n)))
            {
                flag=1;
                break;
            }
        }
        if(flag==0) ans++;
    }
    cout << ans;



    by xiaoyezi2007;
}
