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
int pod[1005][5];
int depth[1005];
int sur[1005];
int ans[6005][3];
int cnt=0;

void mv(int x,int dx,int y,int dy)
{
    ans[cnt][0]=x+1;
    ans[cnt++][1]=y+1;
    pod[y][dy]=pod[x][dx];
    pod[x][dx]=0;
}
int f(int epty, int color, int n)
{
    int a=-1,b=-1,c=-1;
    for(int i=0;i<=n;i++)
    {
        if(pod[i][0]==color)
        {
            if(a==-1) a=i;
            else if(b==-1) b=i;
            else c=i;
        }
        if(pod[i][1]==color)
        {
            if(b==-1) b=i;
            else if(c==-1) c=i;
        }
        if(pod[i][2]==color)
        {
            c=i;
        }
    }
    mv(a,0,epty,2);
    if(pod[b][0]==color)
    {
        mv(b,0,epty,1);
    }
    else if(pod[b][0]==0)
    {
        mv(b,1,epty,1);
    }
    else
    {
        mv(b,0,a,0);
        mv(b,1,epty,1);
    }
    for(int i=0;i<3;i++)
    {
        if(pod[c][i]==0) continue;
        else if(pod[c][i]==color)
        {
            mv(c,i,epty,0);
        }
        else
        {
            if(pod[a][1]==0 && a!=c)
            {
                mv(c,i,a,1);
            }
            else if(pod[a][0]==0 && a!=c)
            {
                mv(c,i,a,0);
            }
            else if(pod[b][1]==0 && b !=c)
            {
                mv(c,i,b,1);
            }
            else if(pod[b][0]==0 && b!=c)
            {
                mv(c,i,b,0);
            }
        }
    }
    return c;
}
int solve(int epty, int n)
{
    for(int i=1;i<=n;i++)
    {
        if(depth[i]<=3&&sur[i]==1)
        {
            return f(epty,i, n);
        }
    }
}
bool check(int n)
{
    int flag=0;
    for(int i=1;i<=n;i++) depth[i]=0, sur[i]=0;
    for(int i=0;i<=n;i++)
    {
        if(pod[i][0]==pod[i][1]&&pod[i][1]==pod[i][2])
        {
            depth[pod[i][0]]=100;
        }
        else
        {
            flag=1;
            sur[pod[i][0]]=1;
            for(int k=0;k<3;k++) depth[pod[i][k]]+=k;
        }
    }
    if(flag==1) return true;
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;

    cin >> n;
    int epty = n;
    for(int k=0; k<3; k++)
    {
        for(int i=0; i<n; i++)
        {
            cin >> pod[i][k];
        }
    }
    while(check(n))
    {
        epty = solve(epty,n);
    }
    if(pod[n][0]!=0)
    {
        mv(n,0,epty,2);
        mv(n,1,epty,1);
        mv(n,2,epty,0);
    }
    cout << cnt << '\n';
    for(int i=0;i<cnt;i++)
    {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }

    by xiaoyezi2007;
}
