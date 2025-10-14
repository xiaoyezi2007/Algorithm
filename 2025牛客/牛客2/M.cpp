#include<bits/stdc++.h> // O(n^(2/3))
using namespace std;
#define ll long long int
const int MAXN = 100000;
const ll mod = 998244353;
char l[MAXN+5],s[MAXN+5];
ll dp[2][2][2][2][2][3]; // as tutorial dp[i][j][k][l][m][n]: when consider i bit, j = a<b,k=b<c,l=c<s,m=a^b^c<l,
//n=min(a>>i+b>>i-c>>i,1)+1,n<0 then out of consideration, the count of triple(a,b,c),where a<=b<=c<=s&&a^b^c<=l
// attention! note leftest bit as the first bit
void clear(int now)
{
    for(int j=0;j<=1;j++) for(int k=0;k<=1;k++) for(int m=0;m<=1;m++) for(int n=0;n<=1;n++) for(int o=0;o<=2;o++) dp[now][j][k][m][n][o] = 0;
}
void solve()
{
    cin >> l >> s;
    int lenl = strlen(l);
    int lens = strlen(s);
    int len = max(lenl,lens);
    for(int i=1;i<=len;i++)
    {
        l[len-i] = lenl-i>=0 ? l[lenl-i]-'0' : 0;
        s[len-i] = lens-i>=0 ? s[lens-i]-'0' : 0;
    }
    //for(int i=0;i<len;i++) printf("%d",s[i]);
    int now = 1;
    clear(0),clear(1);
    dp[0][0][0][0][0][1] = 1;
    for(int i=0;i<len;i++)
    {
        now^=1;
        clear(now^1);
        for(int j=0;j<=1;j++) // j refer to a < b ?
        {
            for(int k=0;k<=1;k++) // k refer to b < c ?
            {
                for(int m=0;m<=1;m++) // m refer to c < s ?
                {
                    for(int n=0;n<=1;n++) // n refer to a^b^c < l ?
                    {
                        for(int o=0;o<=2;o++) // o refer to a+b-c
                        {
                            for(int nxta=0;nxta<=1;nxta++)
                            {
                                for(int nxtb=0;nxtb<=1;nxtb++)
                                {
                                    for(int nxtc=0;nxtc<=1;nxtc++)
                                    {
                                        if((nxta^nxtb^nxtc)>l[i]&&n==0) continue;
                                        if(nxta>nxtb&&j==0) continue;
                                        if(nxtb>nxtc&&k==0) continue;
                                        if(nxtc>s[i]&&m==0) continue;
                                        int nxto = (o-1)*2+nxta+nxtb-nxtc+1;
                                        if(nxto<0) continue;
                                        nxto = min(2,nxto); // 1*2-1 = 1
                                        int nxtj = (j==0&&nxta==nxtb) ? 0 : 1;
                                        int nxtk = (k==0&&nxtb==nxtc) ? 0 : 1;
                                        int nxtm = (m==0&&nxtc==s[i]) ? 0 : 1;
                                        int nxtn = (n==0&&(nxta^nxtb^nxtc)==l[i]) ? 0 : 1;
                                        (dp[now^1][nxtj][nxtk][nxtm][nxtn][nxto]+=dp[now][j][k][m][n][o])%=mod;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    now^=1;
    for(int j=0;j<=1;j++) for(int k=0;k<=1;k++) for(int m=0;m<=1;m++) for(int n=0;n<=1;n++) (ans+=dp[now][j][k][m][n][2])%=mod;
    for(int m=0;m<=1;m++) for(int n=0;n<=1;n++) (ans+=dp[now][1][1][m][n][2])%=mod;
    cout << ans << '\n';
}


int main() {
    int xiaoyezi2007;
    cin >> xiaoyezi2007;
    while(xiaoyezi2007--)
    {
        solve();
    }
    return 0;
}
// by xiaoyezi2007;
