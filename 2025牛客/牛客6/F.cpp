#include<bits/stdc++.h>
using namespace std;
#define M 998244353
#define int long long
const int MAXN = 100000;
const int MAXCOST = 80;
int dist[MAXN+5][MAXCOST+5],pre[MAXN+5][MAXCOST+5];
//dist i,j : consider tree with [1,i] , the expected number of segment of cost = j.
//pre i,j : consider tree with [1,i] , the expected number of segment(only[1,x]) of cost = j.
int ksm(int a, int b){
    int  res = 1;
    while(b) {
        if(b & 1ll)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    pre[1][1] = dist[1][1] = 1ll;
    for(int i=2;i<=n;i++)
    {
        pre[i][1] = dist[i][1] = 1ll;
        for(int j=2;j<=min(MAXCOST,2*n);j++)
        {
            pre[i][j] = (pre[i/2][j-1]+pre[i/2][j-2]+pre[i/2+i%2][j-1]+pre[i/2+i%2][j-2])%M;
            (pre[i][j]*=ksm(2,M-2))%=M;
            if(j==3) pre[i][j] = (pre[i][j]-1+M)%M; //solve [1,i]wrong
        }
        for(int j=2;j<=min(MAXCOST,2*n);j++)
        {
            dist[i][j] = (dist[i/2][j-1]+dist[i/2+i%2][j-1])%M;
            for(int x = 1;x<j-1;x++)
            {
                (dist[i][j]+=pre[i/2][x]*pre[i/2+i%2][j-x-1]%M)%=M;
                if(j==3&&x==1) dist[i][j] = (dist[i][j]-1+M)%M; // solve [1,i] wrong as well
            }
        }
    }
    for(int i=1;i<=2*n;i++)
    {
        if(i>MAXCOST) cout << "0\n";
        else cout << dist[n][i] << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
    return 0;
}
//by xiaoyezi2007
