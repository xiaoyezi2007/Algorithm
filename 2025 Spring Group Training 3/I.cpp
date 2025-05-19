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
char s[10][10];
int a[10];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for(int i=1;i<=6;i++) cin >> s[i];
    for(int i=1;i<=6;i++) if(s[i][0]=='t') a[i]=1; else a[i]=0;
    int ans=0;
    if(a[2]==a[5]) ans++;
    if(a[1]==a[4]) ans++;
    if(a[3]==a[6]) ans++;
    if(a[3]==a[6]&&a[1]==a[4]&&a[2]==a[5])
    {
        if(a[1]==a[2]||a[1]!=a[3]||a[2]==a[3]) ans++;
    }
    cout << ans + 4;


    by xiaoyezi2007;
}
