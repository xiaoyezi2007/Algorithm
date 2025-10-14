#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a[200005];
int len[200005];
int flag = 0;
int mx = 0;
int n,y,m;
int ksm(int x,int y,int p)
{
    int res = 1;
    while(y)
    {
        if(y&1)
        {
            if(x==-1) return -1;
            res = res*x;
            if(res>p) return -1;
        }
        x = x*x;
        if(x>p) x = -1;
        y>>=1;
    }
    return res;
}
bool isup(int s)
{

    for(int i=1;i<=flag;i++)
    {
        int s1 = 0;
        for(int j=1;j<=len[i];j++)
        {
            int tmp = a[i][j-1];
            if(tmp>=s) return false;
            if(tmp == 0) continue;
            tmp*=ksm(s,len[i]-j,max(y,mx));
            if(tmp<0||tmp>mx) tmp = mx+1;
            s1+=tmp;
            if(s1>mx) s1 = mx+1;

        }
        s = s1;
    }
    return true;
}
int check(int s)
{
    for(int i=1;i<=n;i++)
    {
        int s1 = 0;
        for(int j=1;j<=len[i];j++)
        {
            int tmp = a[i][j-1];
            if(tmp>=s) return -1;
            s1 = min(s1*s+tmp,1ll*1000000007);

        }
        s = s1;
    }
    if(s == y) return 0;
    if(s>y) return 1;
    return -1;
}
void solve()
{
    flag = 0;
    mx = 0;
    cin >> n >> y >> m;
    for(int i=1;i<=n;i++) a[i].clear();
    for(int i=1;i<=n;i++)
    {
        cin >> len[i];
        if(len[i] == 1) flag = i;
        int x;
        for(int j=0;j<len[i];j++)
        {
            cin >> x;
            mx = max(x,mx);
            a[i].push_back(x);
        }
    }
    int l = 1,r = m;
    int ans = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(mid)<0) l = mid+1;
        else
        {
            ans = mid;
            r = mid-1;
        }
    }
    if(ans == -1||check(ans)!=0)
    {
        cout << "-1 -1\n";
        return;
    }
    int ans1 = ans;
    l = ans,r = m;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(mid) == 0)
        {
            ans1 = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans << ' ' << ans1 << '\n';
}

signed main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
