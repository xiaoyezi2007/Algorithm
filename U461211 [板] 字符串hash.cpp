#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  998244353
#define ll long long int
#define MAXN 500005
#define pi 3.14159265358
#define double long double
using ull = unsigned long long;
ull base = 131;
ull mod1 = 212370440130137957, mod2 = 1e9 + 7; // if you want know the hash value of sub-string ,you can use:
// hash(s[l...r]) = hash(s[1...r]) - hash(s[1...l-1])*base^(r-l+1)
// in this way, you can pre-calculate all the hash(s[1...i]) and got ans fast!
ull get_hash1(string s) {
  int len = s.size();
  ull ans = 0;
  for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod1;
  return ans;
}

ull get_hash2(string s) {
  int len = s.size();
  ull ans = 0;
  for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod2;
  return ans;
}

bool cmp(const string s, const string t) {
  bool f1 = get_hash1(s) != get_hash1(t);
  bool f2 = get_hash2(s) != get_hash2(t);
  return f1 || f2;
}
set<pair<ull,ull>> st;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll n;
    int ans = 0;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        ull hash1 = get_hash1(s);
        ull hash2 = get_hash2(s);
        st.insert({hash1,hash2});
    }
    cout << st.size();
}

//by xiaoyezi2007
