#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
#define int long long
#define ll long long
#define f first
#define s second
const int n = 15;
char turn[10];
int a[25];
int cnt = 1;
int mi[20000];
void solve1()
{
    int x;
    cin >> x;
    x--;
    for(int i=1;i<=20;i++) a[i] = 0;
    cnt = 1;

    for(int i=1;i<=15;i++)
    {
        while(mi[cnt]==1) cnt++;
        a[cnt] = x%2;
        cnt++;
        x/=2;
    }
    for(int i=0;i<=4;i++)
    {
        int id = (1<<i);
        for(int j=1;j<=20;j++)
        {
            if(((j>>i)&1)==1)
            {
                a[id]^=a[j];
            }
        }
    }
    vector<int> out;
    for(int i=1;i<=20;i++)
    {
        if(a[i] == 1) out.push_back(i);
    }
    cout << out.size() << '\n';
    for(int num:out) cout << num << ' ';
    cout << '\n';
}

void solve2()
{
    int n;
    cin >> n;
    for(int i=1;i<=20;i++) a[i] = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int error = 0;
    for(int i=0;i<=4;i++)
    {
        int id = (1<<i);
        int S = 0;
        for(int j=1;j<=20;j++)
        {
            if(((j>>i)&1) == 1)
            {
                S^=a[j];
            }
        }
        if(S==1)
        {
            error|=(1<<i);
        }
    }
    a[error]^=1;
    //cout << "e:"<<error << '\n';
    int x = 0;
    for(int i=20;i>0;i--)
    {
        if(mi[i] == 1) continue;
        x*=2;
        if(a[i] == 1)
        {
            x+=1;
        }
    }
    x++;
    cout << x << '\n';
}

signed main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> turn;
    int t;
    cin >> t;
    for(int i=1;i<=(1<<10);i<<=1)
    {
        mi[i] = 1;
    }
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
/*
0

17
1 2 3 5 6 7 8 9 10 11 12 13 14 15 17 18 19
*/

