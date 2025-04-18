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
long long int f(long long int x)
{
    ll a = 1, b = 0;
	if(x % 4 == 0) return x;
	else if(x % 4 == 1) return a;
	else if(x % 4 == 2) return x + 1;
	return b;
}
int main()
{
    long long int l,r,ans;
    scanf("%lld%lld",&l,&r);


    ans = f(l-1)^f(r); //ans = XOR for all Integer on [l,r]


    printf("%lld",ans);
}
//by xiaoyezi2007
