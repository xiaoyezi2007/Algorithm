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
int a[3000];
int b[3000];
int loca[3000];
int locb[3000];
int ans[10000005][2];
int cnt;
void exchange(int idx,int i) {
    ans[cnt][0]=idx;
    ans[cnt++][1]=loca[i];
    int location = loca[i];
    swap(loca[a[idx]],loca[i]);
    swap(a[location],a[idx]);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> stack;
    cnt=0;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        loca[a[i]]=i;
    }
    for(int i=1; i<=n; i++)
    {
        cin >> b[i];
        locb[b[i]]=i;
    }
    for(int i=1; i<=n; i++)
    {
        if(loca[i]==locb[i]) continue;
        if(loca[i]<locb[i])
        {
            // cout<<i<<"* ";
            cout << "-1\n";
            return;
        }
        int idx=loca[i]-1;
        stack.clear();
        while(idx>=locb[i])
        {
            while(a[idx]==b[idx]) idx--;
            while(!stack.empty() && a[stack.back()] > a[idx]) stack.pop_back();
            stack.push_back(idx);
            idx--;
            // exchange(idx,i);
        }
        for(int j=0;j<stack.size();j++) {
            idx = stack[j];
            exchange(idx,i);
            // cout<<idx<<" ";
        }
    }
    cout << cnt << '\n';
    for(int i=0;i<cnt;i++)
    {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    by xiaoyezi2007;
}
