#include<bits/stdc++.h>
using namespace std;
#define ll long long int;
const __int128 N = 1000;
const __int128 B = 31;
const __int128 M = 1e18;
const __int128 MM = 1e9;
__int128 a[N+5];
int ans[N+5];
__int128 b[N+5];
int tmp[B+5];
map<int,int> mp;
bool check(int x,int t)
{
    if(t==0) return false;
    __int128 sum = 0;
    for(int i=1;i<=B;i++)
    {
        if((t>>(i-1)&1) == 1) sum+=a[B*x+i];
    }
    if(mp.find(sum%MM)!=mp.end()&&mp[sum%MM]!=t)
    {
        int tt = mp[sum%MM];
        sum = 0;
        for(int i=1;i<=B;i++)
        {
            if((t>>(i-1)&1) == 1 && (tt>>(i-1)&1) == 1 || (t>>(i-1)&1) == 0 && (tt>>(i-1)&1) == 0)
            {
                ans[x*B+i] = 0;
            }
            else if((t>>(i-1)&1) == 1 && (tt>>(i-1)&1) == 0)
            {
                ans[x*B+i] = 1;
                sum+=a[x*B+i];
            }
            else
            {
                ans[x*B+i] = -1;
                sum-=a[x*B+i];
            }
        }
        sum = (sum%M+M)%M;
        b[x] = sum/MM;
        return true;
    }
    mp[sum%MM] = t;
    return false;
}
bool check1(int t)
{
    if(t==0) return false;
    __int128 sum = 0;
    for(int i=0;i<B;i++)
    {
        if((t>>i&1) == 1) sum+=b[i];
    }
    if(mp.find(sum%MM)!=mp.end()&&mp[sum%MM]!=t)
    {
        int tt = mp[sum%MM];
        for(int i=0;i<B;i++)
        {
            if((t>>i&1) == 1 && (tt>>i&1) == 1 || (t>>i&1) == 0 && (tt>>i&1) == 0)
            {
                tmp[i] = 0;
            }
            else if((t>>i&1) == 1 && (tt>>i&1) == 0)
            {
                tmp[i] = 1;
            }
            else
            {
                tmp[i] = -1;
            }
        }
        return true;
    }
    mp[sum%MM] = t;
    return false;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    srand(time(0));
    long long int in[1005];
    for(int i=1;i<=N;i++) cin >> in[i],a[i] = in[i];
    for(int i=0;i<B;i++)
    {
        int t = 0;
        mp.clear();
        while(!check(i,t))
        {
            t = 0;
            for(int j=0;j<B;j++) t<<=1 , t|=rand()%2;
        }
    }
    int t = 0;
    mp.clear();
    while(!check1(t))
    {
        t = 0;
        for(int j=0;j<B;j++) t<<=1 , t|=rand()%2;
    }
    for(int i=1;i<=B*B;i++)
    {
        int x = ans[i]*tmp[(i-1)/B];
        if(x==-1) cout << "1";
        else if(x==0) cout << "0";
        else cout << "2";
    }
    for(int i=B*B+1;i<=N;i++) cout << "0";
}
