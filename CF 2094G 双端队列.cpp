#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define xiaoyezi2007 0
#define by return
#define ep 1e-7
#define mod  (1llu<<63)
#define ll long long int
#define ull unsigned long long int
#define MAXN 3000
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        deque<ll> q1,q2;
        int q;
        cin >> q;
        ll ans1=0,ans2=0;
        ll sum=0;
        ll sz=0;
        while(q--)
        {
            int op;
            cin >> op;
            if(op==1)
            {
                ll last=q1.back();
                q1.pop_back();
                q1.push_front(last);
                ans1+=sum-sz*last;
                last=q2.front();
                q2.pop_front();
                q2.push_back(last);
                ans2+=sz*last-sum;
            }
            else if(op==2)
            {
                swap(q1,q2);
                swap(ans1,ans2);
            }
            else if(op==3)
            {
                ll x;
                cin >> x;
                q1.push_back(x);
                sz++;
                sum+=x;
                ans1+=sz*x;
                q2.push_front(x);
                ans2+=sum;
            }
            cout << ans1 << '\n';
        }
    }


    by xiaoyezi2007;
}
