#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  1000000007
#define ll long long int
#define MAXN 300005
int sta[3000005];
int ind[3000005];
int ans[3000005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int cnt = 0;
    int n;
    cin >> n;
    for(int i =0;i<n;i++)
    {
        int x;
        cin >> x;
        while(cnt>0&&x>sta[cnt-1])//pop until not bigger
        {
            cnt--;
            ans[ind[cnt]]=i+1;
        }
        sta[cnt]=x;
        ind[cnt++]=i;
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
}

//by xiaoyezi2007
