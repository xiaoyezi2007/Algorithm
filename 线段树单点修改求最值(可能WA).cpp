#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
int N;
vector<ll> segtree(4*MAXN);
ll f(ll a,ll b) // the rule when we combine the two children , that is what we are calculating for
{
    return max(a,b);
}
void pull(int t) // combine the two children of node t
{
    segtree[t]=f(segtree[2*t],segtree[2*t+1]);
}
void point_set(int idx, ll val, int L = 1,int R = N,int t = 1) // set arr[idx-1] to val, idx begin from 1 to n;
{
    if(L==R) segtree[t]=val;
    else
    {
        int M=(L+R)/2;
        if(idx <= M) point_set(idx,val,L,M,2*t);
        else point_set(idx,val,M+1,R,2*t+1);
        pull(t);
    }
}
ll range_add(int left,int right,int L = 1,int R = N,int t = 1)// calculate the ans of segment left to right
{
    if(left<=L&&R<=right) return segtree[t];
    else
    {
        int M=(L+R)/2;
        ll tmp=1e18;
        if(left<=M) tmp=f(tmp,range_add(left,right,L,M,2*t));
        if(right>M) tmp=f(tmp,range_add(left,right,M+1,R,2*t+1));
        return tmp;
    }
}
void build(vector<ll>& arr,int L = 1,int R = N,int t = 1) //attention! data in arr is begin from 0,but in segment tree ,we assume element is store in 1 to N
{
    if(L==R) segtree[t]=arr[L-1];
    else
    {
        int M=(L+R)/2;
        build(arr,L,M,2*t);
        build(arr,M+1,R,2*t+1); // attention to M+1!
        pull(t);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {

    }
    return 0;
}
//by xiaoyezi2007
