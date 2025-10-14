#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n,m;
    cin >> n >> m;
    if(0.8*m>n&&1.2*m<2*n-1)
    {
        cout << "-1\n";
        return;
    }
    for(int i=0;i<=n;i++)
    {
        ll ans = i*(n-i)+n;
        if(ans>=0.8*m&&ans<=1.2*m)
        {
            for(int j=0;j<i;j++) cout << "0";
            for(int j=0;j<n-i;j++) cout << "1";
            cout << '\n';
            return;
        }
    }
    for(int t = 3;t<=6;t++)
    {
        if(1.0*(t-1)/2/t*n*n>=0.8*m&&1.0*(t-1)/2/t*n*n<=1.2*m)
        {
            int len = n;
            int more = 0;
            for(int i=1;i<=t-1;i++) len-=i;
            more = len%t;
            len/=t;
            int cnt = 0;
            for(int i=0;i<t;i++)
            {
                if(i!=0) for(int j=0;j<i;j++) cout << "1";
                for(int j=0;j<len;j++) cout << "0";
            }
            for(int i=0;i<more;i++) cout << "0";
            cout << '\n';
            return;
        }
    }
    while(1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
