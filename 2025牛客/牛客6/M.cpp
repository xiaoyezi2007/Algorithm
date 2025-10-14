#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int n,m;
const int mod = 998244353;
vector<int> sub(vector<int> b,vector<int> c)
{

    int cntb = b.size();
    int cntc = c.size();
    vector<int> d(max(cntb,cntc)+1);
    for (int i = 0; i < max(cntb,cntc); ++i)
    {
        int x = 0;
        if(i<cntc) x = c[i];
        d[i] += b[i] - x;
        if (d[i] < 0)
        {
            d[i + 1] -= 1;
            d[i] += m;
        }
    }
    vector<int> ans;
    int flag = 0;
    for(int i = d.size()-1;i>=0;i--)
    {
        if(flag) ans.push_back(d[i]);
        else
        {
            if(d[i]!=0)
            {
                ans.push_back(d[i]);
                flag = 1;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    //cout << ans[0];
    return ans;
}
int compare(vector<int> a,vector<int> b)
{
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return -1;
    int len = a.size();
    for(int i = len-1; i>=0; i--)
    {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
    return 0;
}
int mto10(vector<int> a)
{
    int len = a.size();
    int sum = 0;
    for(int i=len-1; i>=0; i--)
    {
        sum = (sum*m%mod+a[i])%mod;
    }
    return sum;
}
vector<int> solveEven(int idx)
{
    vector<int> b,c;
    b.push_back(a[idx+1]),c.push_back(a[idx]);
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(i==idx||i==idx+1) continue;
        if(cnt == n/2-1) break;
        b.push_back(a[i]);
        cnt++;
    }
    for(int i=n-1; i>=0; i--)
    {
        if(i==idx||i==idx+1) continue;
        if(cnt == n-2) break;
        c.push_back(a[i]);
        cnt++;
    }
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    return sub(b,c);
}
vector<int> f()
{
    int mi = mod;
        int idl = -1,idr = -1;
        for(int i=0; i<n-1; i++) mi = min(mi,a[i+1]-a[i]);
        for(int i=n/2; i>0; i--)
        {
            if(a[i]-a[i-1] == mi)
            {
                idl = i-1;
                break;
            }
        }
        for(int i=n/2; i<n-1; i++)
        {
            if(a[i+1]-a[i] == mi)
            {
                idr = i;
                break;
            }
        }
        vector<int> d1,d2;
        if(idr==-1)
        {
            return solveEven(idl);
        }
        if(idl==-1)
        {
            return solveEven(idr);
        }
        d1 = solveEven(idl),d2 = solveEven(idr);
        if(compare(d1,d2)>0) return d2;
        else return d1;
}
void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    if(n%2)
    {
        if(a[0]!=0)
        {
            vector<int> b,c;
            for(int i = n/2; i>=0; i--) b.push_back(a[i]);
            for(int i=n/2+1; i<n; i++) c.push_back(a[i]);
            cout << mto10(sub(b,c)) << '\n';
            return;
        }
        else
        {
            vector<int> b,c;
            int cnt = 0;
            b.push_back(a[1]),b.push_back(a[0]);
            cnt+=2;
            for(int i=2;i<n;i++)
            {
                if(cnt == n/2+1) break;
                b.push_back(a[i]);
                cnt++;
            }
            for(int i=n-1;i>=0;i--)
            {
                if(cnt == n) break;
                c.push_back(a[i]);
                cnt++;
            }
            reverse(b.begin(),b.end());
            reverse(c.begin(),c.end());
            vector<int> d = sub(b,c);
            for(int i=0;i<n-1;i++) a[i] = a[i+1];
            n--;
            vector<int> ans = f();
            if(compare(ans,d)>0) cout << mto10(d) << '\n';
            else cout << mto10(ans) << '\n';

        }
    }
    else
    {
        cout << mto10(f()) << '\n';

    }
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
