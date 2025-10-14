#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<long long,long long>
#define f first
#define s second
#define ep 1e-6
int n,m,d;
int l[30];
pi a[100005];
int dp[52][52];
int mx[52][52];
pi que[105][52][52];
int le[52][52],r[52][52];
bool cmp(pi p,pi q)
{
    if(p.f!=q.f) return p.f<q.f;
    return p.s<q.s;
}
void solve()
{
    cin >> n >> m >> d;
    for(int i=1; i<=n; i++) cin >> l[i];
    for(int i=1; i<=m; i++) cin >> a[i].f >> a[i].s;
    sort(a+1,a+m+1,cmp);
    sort(l+1,l+n+1);
     for(int j=0; j<=2*n; j++) for(int k=0; k<=2*n; k++) dp[j][k] = -1,mx[j][k] =  -1,le[j][k] = r[j][k] = 100;
    dp[0][0] = 0;
    mx[0][0] = 0;
    //que[--le[0][0]][0][0] = {0,0};
    for(int i=1; i<=m; i++)
    {

        for(int j=0; j<=2*n; j++) for(int k=0; k<=2*n; k++) dp[j][k] = -1;

        for(int j=1; j<=i&&j<=2*n; j++) for(int k=0; k<=j; k++)
            {
                int c = 2-a[i].s;
                if(k==0&&c==1) continue;
                /*
                for(int ii=0; ii<i; ii++)
                {
                    if(dp[ii][j-1][k-c] == -1) continue;
                    if(j%2==0&&a[i].f-a[ii].f<=d&&a[i].f<l[(j+1)/2]) dp[i][j][k] = max(dp[i][j][k],dp[ii][j-1][k-c]+a[i].f);
                }
                */
                if(j%2==0)
                {
                    while(r[j-1][k-c]>le[j-1][k-c]&&a[i].f-a[que[r[j-1][k-c]-1][j-1][k-c].s].f>d) r[j-1][k-c]--;
                    if(a[i].f<=l[(j+1)/2]&&r[j-1][k-c]>le[j-1][k-c]) dp[j][k] = max(dp[j][k],que[r[j-1][k-c]-1][j-1][k-c].f+a[i].f);
                }
                if(j%2&&a[i].f<=l[(j+1)/2]&&mx[j-1][k-c]!=-1) dp[j][k] = max(dp[j][k],mx[j-1][k-c]+a[i].f);

            }
        for(int j=1;j<=i&&j<=2*n;j++) for(int k=0;k<=j;k++)
        {
            if(dp[j][k]!=-1)
                {
                    while(r[j][k]>le[j][k]&&dp[j][k]>que[le[j][k]][j][k].f) le[j][k]++;
                    que[--le[j][k]][j][k] = {dp[j][k],i};
                }
                mx[j][k] = max(mx[j][k],dp[j][k]);
        }
    }


    for(int i=0; i<=2*n; i++)
    {
        int ans = -1;
        ans = max(ans,mx[2*n][i]);
        cout << ans << ' ';
    }
    cout << '\n';


}

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
