Meisell-Lehmer求区间质数个数O($\frac{n^{2/3}}{log^2n}$)

```c++
#include<bits/stdc++.h> // O(n^(2/3)/log^2)
using namespace std;
#define ll long long int
const int N = 8e6 + 10;
const int MI = 1.8e6;
const int MJ = 60;
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
ll pi(ll n) { // number of prime less or equal than n
	if(n < N) return g[n] - 1;
	ll sn = pow(n, 1. / 3);
	ll m = g[sn] - 1;
	ll res = dp(n, m) + m - 1;
	for(m++; 1ll * p[m] * p[m] <= n; m++)
		res -= pi(n / p[m]) - pi(p[m]) + 1; // 继续递归
	return res;
}

int main() {
    init();
    ll n;
    cin >> n ;
    cout << pi(n);
    return 0;
}

```

注意到能通过加质因数变成下一个完全平方数的数一定大于上一个完全平方数。

因此考虑处理1~n的答案，转化为1 ~根号n每个数的质因子的个数和以及能转化为根号n+1的所有数。

转化为根号n+1的数直接对根号n+1分解质因子遍历。

对1~1e7的数直接线性筛，每一个质数的贡献是根号n/p。

对于更大多数，最大贡献不超过100，枚举贡献val，能够提供该贡献的质数处于根号n/val到根号n/(val+1)。使用上面的科技统计该区间内的质数个数即可。