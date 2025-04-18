#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
struct DSU {
    std::vector<int> p, sz, h;

    DSU(int n = 0) : p(n), sz(n, 1), h(n) {
        std::iota(p.begin(), p.end(), 0);
    }

    int leader(int x) {
        if (x == p[x]) {
            return x;
        }
        return leader(p[x]);
    }

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    bool _merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (h[x] < h[y]) {
            std::swap(x, y);
        }
        if (h[x] == h[y]) {
            ++h[x];
        }
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }

    int size(int x) {
        return sz[leader(x)];
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        DSU dsu(n);
        dsu._merge(x, y);
    }
    return 0;
}
//by xiaoyezi2007
