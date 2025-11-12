#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
#define int long long
#define ll long long
#define f first
#define s second
char turn[10];
char s[100005];
int cnt = 0;
void solve1()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if(x==1) ans = 0;
        else if(x==n) ans = 1;
    }
    cout << ans << '\n';
}

void solve2()
{
    int n,x;
    cin >> n >> x;
    int l=1,r=n;
    if(x==0)
    {
        int ansl = 1;
        while(l<r)
        {
            if(r-l==1)
            {
                cout <<"? "<< r << " " << n << '\n';
                cout.flush();
                int ans;
                cin >> ans;
                if(ans == n-1) l=r;
                break;
            }
            int mid = (l+r)/2;
            cout <<"? "<< mid << " " << n << '\n';
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == n-1)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << "! " << l << '\n';
        cout.flush();
    }
    else
    {
        int ansr = n;
        while(l<r)
        {
            if(r-l==1)
            {
                cout <<"? "<< 1 << " " << l << '\n';
                cout.flush();
                int ans;
                cin >> ans;
                if(ans == n-1) r=l;
                break;
            }
            int mid = (l+r)/2;
            cout <<"? "<< "1 " << mid << '\n';
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == n-1)
            {
                r = mid;
            }
            else l=mid;
        }
        cout << "! " << r << '\n';
        cout.flush();
    }
}

signed main()
{
    /*
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    */
    cin >> turn;
    int t;
    cin >> t;
    while(t--)
    {
        if (strcmp(turn,"first") == 0)
        {
            solve1();
        }
        else if(strcmp(turn, "second") == 0)
        {
            solve2();
        }
    }
}
//by xiaoyezi2007
