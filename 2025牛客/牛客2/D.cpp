#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,V;
int dp[2][505][505];
const int N = 1e5+5;
const int inf = 1e18;
int h[N],s[N],d[N];

vector<int> v[505][505];
vector<int> ss[505];
int sortVAR;
bool cmp(int a,int b)
{
    return h[a] - d[a]*sortVAR > h[b] - d[b]*sortVAR;
}
void clear(int now)
{
    for(int j=1;j<=V;j++) for(int k=0;k<=V;k++) dp[now][j][k]=-inf;
}
void solve() {
    cin>>n>>V;
    for(int i=1;i<=V;i++) ss[i].clear();
    for(int k=1;k<=V;k++) for(int i=1;i<=k;i++) v[k][i].clear();


    for(int i=1;i<=n;i++) cin>>h[i]>>s[i]>>d[i],ss[s[i]].push_back(i);

    for(int k = 1;k<=V;k++)
    {
        sortVAR = V-k;
        for(int i=1;i<=k;i++)
        {
            if(ss[i].size()<=k/i) v[k][i] = ss[i];
            else
            {
                nth_element(ss[i].begin(),ss[i].begin()+k/i,ss[i].end(),cmp);
                for(int j=0;j<k/i;j++) v[k][i].push_back(ss[i][j]);
            }

        }
    }

    int lst=0;int ans = -inf;
    for(int j=1;j<=V;j++) for(int k=0;k<=V;k++)  dp[lst][j][k]=-inf;
    for(int k=0;k<V;k++) {

        lst = 0;
        for(int i=1;i<=V;i++) {
             // v[V-k][i]
            for(int tt=0;tt<v[V-k][i].size();tt++) {
                int now = lst^1;
                //clear(now);
                int x = v[V-k][i][tt];
                int del = h[x]-d[x]*k;
                // cout<<k<<" "<<h[x]<<" "<<d[x]<<" "<< s[x] <<"\n";
                for(int j=0;j<s[x];j++) dp[now][j][k] = dp[lst][j][k];
                for(int j=s[x];j<=V-k;j++) {
                    dp[now][j][k]=max(dp[lst][j][k],dp[lst][j-s[x]][k]+del);
                }
                lst = now;

            }
        }
        ans = max(ans,dp[lst][V-k][k]);
        // for(int i=0;i<=V;i++) cout<<dp[lst][V-i][i]<<" ";cout<<"\n";
    }

    // for(int i=0;i<=V;i++) cout<<dp[lst][i][0]<<" ";cout<<"\n";



    cout<<max(0LL,ans)<<"\n";
}
signed main() {
    int _;cin>>_;
    while(_--) solve();
    return 0;
}
