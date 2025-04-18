#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
vector<pair<int,int>> ans[6];
char s[2000006];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<char>> a(n+2,vector<char>(m+2));
        for(int i=1;i<=n;i++)
        {
            cin >> s;
            for(int j=1;j<=m;j++)
            {
                a[i][j]=s[j-1];
            }
        }
        for(int i=0;i<=n+1;i++) a[i][0]=a[i][m+1]='.';
        for(int i=0;i<=m+1;i++) a[0][i]=a[n+1][i]='.';
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]=='#')
                {
                    ans[(i+2*j)%5].push_back({i,j});
                    cnt++;
                    if(a[i][j+1]=='.')
                    {
                        ans[(i+2*j+2)%5].push_back({i,j});
                        cnt++;
                    }

                    if(a[i][j-1]=='.')
                    {
                        ans[(i+2*j-2)%5].push_back({i,j});
                        cnt++;
                    }
                    if(a[i+1][j]=='.')
                    {
                        ans[(i+2*j+1)%5].push_back({i,j});
                        cnt++;
                    }
                    if(a[i-1][j]=='.')
                    {
                        ans[(i+2*j-1)%5].push_back({i,j});
                        cnt++;
                    }
                }

            }
        }
        for(int i=0;i<5;i++)
        {
            if(ans[i].size()<=(cnt/5))
            {
                for(pair<int,int> x:ans[i])
                {
                    a[x.first][x.second]='S';
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        cout << a[i][j];
                    }
                    cout << '\n';
                }
                break;
            }
        }
        for(int i=0;i<5;i++) ans[i].clear();

    }
    return 0;
}
//by xiaoyezi2007
