#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int mod = 998244353;
ll n,m,k;
long long int ksm(long long int a, long long int b){
    long long int  res = 1;
    while(b) {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    cin >> n >> m >> k;
    ll r = 2*m-1-m*n+k;
    __int128 ans = 1;
    if(r<0||m-1-r<0)
    {
        cout << "0";
        return;
    }
    for(int i=1;i<=m-1;i++) (ans*=i)%=mod;
    for(int i=m;i>=m-r+1;i--) (ans*=i)%=mod;
    for(int i=1;i<=r;i++) (ans*=ksm(i,mod-2))%=mod;
    for(ll i = m*(n-1);i>=m*(n-1)-(m-r-1)+1;i--) (ans*=i)%=mod;
    for(int i = 1;i<=m-1-r;i++) (ans*=ksm(i,mod-2))%=mod;
    ll out = ans;
    cout << out;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();

}
//by xiaoyezi2007
