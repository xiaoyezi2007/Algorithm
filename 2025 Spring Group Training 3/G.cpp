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
map<pair<int,int>,int> mp;
int cnt = 0;
struct DSU {
    std::vector<int> p, sz, h;

    DSU(int n = 0) : p(n), sz(n, 6), h(n) {
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
        if (x == y)
        {
            sz[x]-=2;
            return false;
        }
        if (h[x] < h[y]) {
            std::swap(x, y);
        }
        if (h[x] == h[y]) {
            ++h[x];
        }
        sz[x] += sz[y]-2;
        //printf("%d\n",sz[x]);
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
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >>n;
    DSU dsu(n);
    while(n--)
    {
        int op,x,y;
        cin >> op >> x >> y;
        if(op==1)
        {
            mp.insert({{x,y},cnt});
            cnt++;
            auto it1 = mp.find({x,y+1});
            auto it2 = mp.find({x,y-1});
            auto it3 = mp.find({x+1,y});
            auto it4 = mp.find({x-1,y});
            auto it5 = mp.find({x-1,y+1});
            auto it6 = mp.find({x+1,y-1});
            if(it1!=mp.end()) dsu._merge(cnt-1,mp[{x,y+1}]);
            if(it2!=mp.end()) dsu._merge(cnt-1,mp[{x,y-1}]);
            if(it3!=mp.end()) dsu._merge(cnt-1,mp[{x+1,y}]);
            if(it4!=mp.end()) dsu._merge(cnt-1,mp[{x-1,y}]);
            if(it5!=mp.end()) dsu._merge(cnt-1,mp[{x-1,y+1}]);
            if(it6!=mp.end()) dsu._merge(cnt-1,mp[{x+1,y-1}]);
        }
        else
        {
            cout << dsu.size(mp[{x,y}]) << '\n';
        }
    }


    by xiaoyezi2007;
}
