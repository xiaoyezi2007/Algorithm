#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
char s[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> s;
    int n=strlen(s);
    int cnt=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
            ans+=i;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        ans-=i;
    }
    if(ans%3) cout << "Alice";
    else cout << "Bob";

}

//by xiaoyezi2007
