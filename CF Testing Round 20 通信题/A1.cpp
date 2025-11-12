#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
#define int long long
#define ll long long
#define f first
#define s second
char turn[10];
char s[100005];
void solve()
{
    cin >> turn;
    if (strcmp(turn,"first") == 0)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            s[i] = 'a'+x-1;
        }
        for(int i=0;i<n;i++) cout << s[i];
    }
    else if(strcmp(turn, "second") == 0)
    {
        cin >> s;
        int len = strlen(s);
        cout << len << '\n';
        for(int i=0;i<len;i++) cout << s[i]-'a'+1 << ' ';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
}
//by xiaoyezi2007
