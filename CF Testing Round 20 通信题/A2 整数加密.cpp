#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
#define int long long
#define ll long long
#define f first
#define s second
char turn[10];
char s[100005];
int cnt = 0;
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
            for(int j=1;j<=10;j++)
            {
                s[cnt++] = x%10+'a';
                x/=10;
            }
        }
        for(int i=0;i<cnt;i++) cout << s[i];
    }
    else if(strcmp(turn, "second") == 0)
    {
        cin >> s;
        int len = strlen(s);
        cout << len/10 << '\n';
        for(int i=0;i<len/10;i++)
        {
            int x = 0;
            int id =1;
            for(int j=0;j<10;j++)
            {
                int p = s[i*10+j]-'a';
                x+=p*id;
                id*=10;
            }
            cout << x << ' ';
        }
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
