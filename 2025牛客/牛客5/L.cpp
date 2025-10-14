#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define M 998244353
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
int Pn_1[200005];
int S[200005];
signed main()
{
    int n,m,p;
    cin >> n >> m >> p;
    if(p==1)
    {
        for(int i=0;i<=m;i++) cout << n%M << ' ';
        return 0;
    }
    int in = 1;
    for(int i=1;i<=n-1;i++) (in*=i)%=M;
    Pn_1[0] = ksm(p,n-1);
    for(int i=1;i<=m;i++) Pn_1[i] = Pn_1[i-1]*((n-1+i)%M)%M*(1-p+M)%M*ksm(i,M-2)%M;
    S[0] = (1-ksm(p,n)+M)*ksm(1-p+M,M-2)%M;
    for(int i=1;i<=m;i++) S[i] = (S[i-1] - Pn_1[i]*p%M*ksm(1-p+M,M-2)%M+M)%M;
    int sum = 0;
    for(int i=0;i<=m;i++)
    {
        (sum+=S[i])%=M;
        int ans = (sum+S[i]*(1-ksm(p,n)+M)%M*ksm(ksm(p,n),M-2)%M)%M;
        cout << ans << ' ';
        assert(ans>=0);
    }
}
