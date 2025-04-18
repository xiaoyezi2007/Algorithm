#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
long long int fac[200005];
long long int inv[200005];

ll qpow(ll x,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1) res=(1ll*res*x)%mod;
		x=(1ll*x*x)%mod;
		n>>=1;
	}
	return res;
}

ll Com(int n,int m){
    return ((fac[n]%mod)*inv[m]%mod)*inv[n-m]%mod;
}

void init()
{
    inv[0]=fac[0]=1;
    inv[1]=1;
    for(int i=1;i<MAXN;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv[1]=1;
    for(int i=2;i<MAXN;i++){
        inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
    }
    inv[0]=1;
    for(int i=1;i<MAXN;i++){
        inv[i]=inv[i-1]*inv[i]%mod;
    }
}
int main() //O(1) solve Combination number under mod
{
    int t;
    scanf("%d",&t);
    init();
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",Com(n,m));
    }

}
//by xiaoyezi2007
