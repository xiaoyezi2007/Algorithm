#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
char s[5005];
ll ans[5005][5005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    cin >> s;
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        ans[i][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j+i<n;j++)
        {
            ans[j][j+i]=(s[j]==s[j+i])&(i==1||ans[j+1][j+i-1]); // initial is [i,j] is a palindrome
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j+i<n;j++)
        {
            if(i==1) ans[j][j+i]=2+ans[j][j+i];
            else ans[j][j+i]=ans[j+1][j+i]+ans[j][j+i-1]-ans[j+1][j+i-1]+ans[j][j+i]; // ans[l][r]=ans[l+1][r]+ans[l][r-1]-ans[l+1][r-1]+(isPalindrome[l][r] ? 1 : 0)
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << ans[x-1][y-1] << '\n';
    }
    return 0;
}
//by xiaoyezi2007
