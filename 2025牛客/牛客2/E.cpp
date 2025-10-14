#include<bits/stdc++.h> // O(n^(2/3))
using namespace std;
#define ll long long int
const int N = 8e6 + 10;
const int MI = 1.8e6;
const int MJ = 60;
const int MAXN = 1e7;
vector<int> pri;
int notprime[MAXN+5];
ll n;
int f[MI + 5][MJ + 5];
int p[N / 10], ip[N], g[N], cnt;
void init() {
    for(int i = 2;i<N;i++) {
		if(!ip[i]) {
			p[++cnt] = i;
		}
		for(int j = 1; j <= cnt && p[j] * i < N; j++) {
			ip[i * p[j]] = 1;
			if(i % p[j] == 0) {
				break;
			}
		}
	}
	// 警惕！这里的 g 数组表示的 pi(n) 含有 1，是 pi(n)+1
	for(int i=1;i<N;i++) g[i] = g[i - 1] + !ip[i];
	for(int i=1;i<=MI;i++) f[i][0] = i;
	for(int i=1;i<=MI;i++) for(int j=1;j<=MJ;j++)
		f[i][j] = f[i][j - 1] - f[i / p[j]][j - 1];
}
ll dp(ll i, ll j) {
	if(i <= MI && j <= MJ) return f[i][j];
	if(!i || !j) return i;
	if(i < N && 1ll * p[j] * p[j] >= i) return max(0ll, g[i] - j);
	return dp(i, j - 1) - dp(i / p[j], j - 1);
}
ll pi(ll n) {
	if(n < N) return g[n] - 1;
	ll sn = pow(n, 1. / 3);
	ll m = g[sn] - 1;
	ll res = dp(n, m) + m - 1;
	for(m++; 1ll * p[m] * p[m] <= n; m++)
		res -= pi(n / p[m]) - pi(p[m]) + 1; // 继续递归
	return res;
}

ll ask(ll n)
{
    ll ans = 0;
    ll x = (ll) sqrt(n);
    for(int p : pri)
    {
        ans+=x/p;
    }
    for(int val = 1;val<100;val++)
    {
        ll r = x/val;
        ll l = x/(val+1);
        if(r<=MAXN) break;
        ans+=(pi(r)-pi(max(l,1ll*MAXN)))*val;
    }
    ll tmp = x+1;
    x++;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i == 0)
        {
            while(x%i==0) x/=i;
            if(tmp*tmp-i<=n) ans++;
        }
    }
    if(x!=1)
    {
        if(tmp*tmp-x<=n) ans++;
    }
    return ans;
}

int main() {
    init();
    ll l,r;
    cin >> l >> r;
    for(int i=2;i<=MAXN;i++)
    {
        if(notprime[i]==0) pri.push_back(i);
        for(int x:pri)
        {
            if(i*x>MAXN) break;
            notprime[i*x]=1; //all the i*k is not prime
            if(i%x==0) break; //this mean i*k has already been found by x*k
        }
    }
    cout << ask(r) - ask(l-1);
    return 0;
}
