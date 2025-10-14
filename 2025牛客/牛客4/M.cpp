#include<bits/stdc++.h>
using namespace std;
#define ll long long int;
int a[60];
int ans = 50;
map<vector<int>,int> vis;
int find(int n)
{
    sort(a,a+n);
    int mi = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1]+(1<<mi)) a[i] = a[i-1] , mi++;
        else mi = 1;
    }
    if(a[0] == a[n-1]) return a[0];
    int cap = a[0];
    for(int i=0;i<n;i++) a[i]-=cap;
    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(a[i]);
    if(vis.find(v)!=vis.end()) return vis[v]+cap;
    int anss = 50;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) continue;
        for(int j=0;j<i;j++)
        {
            if(j!=0&&a[j]==a[j-1]) continue;
            int tmp[10];
            for(int i=0;i<n;i++) tmp[i] = a[i];
            int x=a[i],y=a[j];
            a[i] = (x+y)/2;
            a[j] = (x+y)/2;
            anss = min(anss,find(n));
            for(int i=0;i<n;i++) a[i] = tmp[i];
        }
    }
    vis[v] = anss;
    return anss+cap;
}
void solve()
{
    ans = 50;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    ans = find(n>6?6:n);
    cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

}
//by xiaoyezi2007
