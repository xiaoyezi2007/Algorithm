#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 500005
char r1[1000005];
char r2[1000005];
int a[1000005],b[1000005];
set<int> s;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int q,n;
    cin >> n >> q;
    cin >> r1;
    cin >> r2;
    for(int i=1; i<=n; i++)
    {
        a[i]=r1[i-1]-'0';
        b[i]=r2[i-1]-'0';
        if(a[i]+b[i]!=9) s.insert(i);
    }

    while(q--)
    {
        int r, id, d;
        cin >> r >> id >> d;
        int res2 = 2;
        int pp = 0;
        auto it = s.upper_bound(id); // find the first bit that not 9. because if the first-not-9-bit >10,this bit will get a jinwei
        if(it == s.end())
        {
            pp = (a[id] + b[id]);
        }
        else
        {
            int nxt = (*it);
            pp = (a[id] + b[id] + ((a[nxt] + b[nxt]) >= 10)); //pp is the third row now
        }
        if(r == 1) // change the a,b,s
        {
            if(d == a[id])
            {
                cout << pp % 10 << " ";
                cout << 0 << '\n';
                continue;
            }
            if(d + b[id] != 9) s.insert(id);
            else s.erase(id);
            a[id] = d;
        }
        else
        {
            if(d == b[id])
            {
                cout << pp % 10 << " ";
                cout << 0 << '\n';
                continue;
            }
            if(d + a[id] != 9) s.insert(id);
            else s.erase(id);
            b[id] = d;
        }
        it = s.upper_bound(id);
        int tmp;  // tmp is the third row now
        if(it == s.end())
        {
            tmp = (a[id] + b[id]);
        }
        else
        {
            int nxt = (*it);
            tmp = (a[id] + b[id] + ((a[nxt] + b[nxt]) >= 10));
        }
        cout << tmp % 10 << " ";
        if((tmp < 10 && pp >= 10) || (tmp >= 10 && pp < 10)) // if jinwei or jiewei
        {
            auto its = s.lower_bound(id);
            if(its != s.begin())
            {
                its = prev(its); // just use prev to find the previous interator
                res2 += (id - (*its));
            }
            else res2 += (id - 1);

        }
        cout << res2 << '\n';
    }


}

//by xiaoyezi2007
