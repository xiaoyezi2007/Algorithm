#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1e4;
const int mod = 998244353;
int n,k;
char s[MAXN+5];

int sa[MAXN+5], rk[MAXN*2+5], oldrk[MAXN*2+5], id[MAXN+5], cnt[MAXN+5];
int height[MAXN+5];
int lg[MAXN+5];
int st[MAXN+5][20];
void initSA()
{
    int i, m, p, w;
    m = 127;
    for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;
    memcpy(oldrk + 1, rk + 1, n * sizeof(int));
    for (p = 0, i = 1; i <= n; ++i)
    {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]])
        {
            rk[sa[i]] = p;
        }
        else
        {
            rk[sa[i]] = ++p;
        }
    }

    for (w = 1; w < n; w <<= 1, m = n)
    {
        memset(cnt, 0, sizeof(cnt));
        memcpy(id + 1, sa + 1,
               n * sizeof(int));
        for (i = 1; i <= n; ++i) ++cnt[rk[id[i] + w]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[rk[id[i] + w]]--] = id[i];

        memset(cnt, 0, sizeof(cnt));
        memcpy(id + 1, sa + 1, n * sizeof(int));
        for (i = 1; i <= n; ++i) ++cnt[rk[id[i]]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[rk[id[i]]]--] = id[i];

        memcpy(oldrk + 1, rk + 1, n * sizeof(int));
        for (p = 0, i = 1; i <= n; ++i)
        {
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                    oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
            {
                rk[sa[i]] = p;
            }
            else
            {
                rk[sa[i]] = ++p;
            }
        }
    }
    for (int k = 0,i = 1; i <= n; ++i)
    {
        if (rk[i] == 0) continue;
        if (k) --k;
        while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
        height[rk[i]] = k;
    }
}
void initST()
{
    for(int i=2; i<=n; i++)
    {
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1; i<=n; i++) st[i][0] = height[i];
    for(int j=1; j<=lg[n]; j++)
    {
        for(int i=1; i<=n-(1<<j)+1; i++)
        {
            if(st[i][j-1]<=st[i+(1<<(j-1))][j-1]) st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
}
int askST(int x,int y)
{
    int l=lg[y-x+1];
    if(st[x][l]<=st[y-(1<<l)+1][l]) return st[x][l];
    else return st[y-(1<<l)+1][l];
}
int askLCP(int i,int j)
{
    return askST(min(rk[i],rk[j])+1,max(rk[i],rk[j]));
}
int good[MAXN+5];
int tri[MAXN*MAXN+5],nxt[MAXN*MAXN+5][2];
int tricnt = 0;
ll tot = 0;
void clearGood()
{
    for(int i=1;i<=n;i++) good[i] = 0;
}
void solve()
{
    cin >> n >> k;
    cin >> s;
    for(int i=n;i>=1;i--) s[i] = s[i-1];
    initSA();
    initST();
    //cout << askLCP(1,5);
    for(int i=n;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            int pre = askLCP(i,j);
            if(i+pre+k<j||pre==0) continue;
            else if(i+pre>=j) good[max(j+j-i-k-1,j)]++,good[min(n+1,j+j-i)]--;
            else good[max(j+j-i-k-1,j)]++,good[min(n+1,j+pre)]--;
        }
        int cnt = 0;
        for(int j=i+1;j<=n;j++)
        {
            cnt+=good[j];
            if(cnt>0) good[j] = 1;
            else good[j] = 0;
            //cout << good[j];
        }
        //cout << '\n';
        good[n+1] = 0;
        for(int j=n;j>=i;j--)
        {
            good[j]+=good[j+1];
        }
        tot+=good[i];
        int pt = 0;
        for(int j=i;j<=n;j++)
        {
            if(nxt[pt][s[j]-'0'] == 0)
            {
                nxt[pt][s[j]-'0'] = ++tricnt;
            }
            pt = nxt[pt][s[j]-'0'];
            tri[pt]+=good[j];
        }
        clearGood();
    }
    tri[0] = tri[nxt[0][0]]+tri[nxt[0][1]];
    //cout << tri[0];
    int xiaoyezi2007;
    cin >> xiaoyezi2007;
    ll x = 0;
    ll q;
    while(xiaoyezi2007--)
    {
        ll v;
        cin >> v;
        q = (x%mod+v-1)%tot+1;
        int pt = 0;
        x = 0;
        while(1)
        {
            int nxt0 = nxt[pt][0] == 0?0:tri[nxt[pt][0]];
            int nxt1 = nxt[pt][1] == 0?0:tri[nxt[pt][1]];
            //cout << nxt0 << nxt1 << '\n';
            if(tri[pt]-nxt0-nxt1>=q)
            {
                break;
            }
            q-=tri[pt]-nxt0-nxt1;
            if(nxt0<q)
            {
                q-=nxt0;
                cout << "1";
                pt = nxt[pt][1];
                ((x<<=1)+=1)%=mod;
            }
            else
            {
                cout << "0";
                pt = nxt[pt][0];
                (x<<=1)%=mod;
            }
        }
        cout << '\n';
    }

}


int main()
{
    solve();
}
