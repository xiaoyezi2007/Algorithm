#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
extern inline int max(int aa,int bb)
{
    return aa>bb?aa:bb;
}
extern inline int min(int aa,int bb)
{
    return aa>bb?bb:aa;
}
extern inline int read()
{
    int r=0,f=0;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'),c=getchar();
    while(isdigit(c))r=r*10+(c^'0'),c=getchar();
    return f?-r:r;
}
int a[1005][1005];
int deg[2005];
int d[10005];
int ans[10005];
int vis[10005];
int size = 0;
int n,m;
int heap(int op,int x)
{
    switch(op)
    {
    case 1: //add a new element
    {
        size++;
        d[size]=x;
        int t=size;
        while(t>1&&d[t]<d[t/2])
        {
            int temp=d[t];
            d[t]=d[t/2];
            d[t/2]=temp;
            t/=2;
        }
        break;
    }
    case 2: //print the min
        return d[1];
        break;
    case 3: //delete the min
    {
        int temp1=d[1];
        d[1]=d[size];
        d[size]=temp1;
        size--;
        int t=1;
        while(t*2<=size)
        {
            int nxt=2*t;
            if(nxt+1<=size&&d[nxt+1]<d[nxt]) nxt++;
            if(d[nxt]>=d[t]) break;
            int temp2=d[t];
            d[t]=d[nxt];
            d[nxt]=temp2;
            t=nxt;
        }
    }
    }
}
void solve()
{
    scanf("%d%d",&n,&m);
    size = 0;
    for(int i=1; i<=n+m; i++) vis[i]= deg[i] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j] == 0) deg[i]++;  // 0 -> j to i , 1 -> i to j
            else deg[n+j]++;
        }
    }
    for(int i=1; i<=m+n; i++) if(deg[i] == 0) heap(1,i);
    for(int i=1; i<=m+n; i++)
    {
        if(size == 0)
        {
            printf("NO\n");
            return;
        }
        ans[i] = heap(2,-1);
        heap(3,-1);
        if(ans[i]<=n)
        {
            for(int j=1; j<=m; j++)
            {
                if(a[ans[i]][j] == 1)
                {
                    deg[j+n]--;
                    if(deg[j+n] == 0) heap(1,j+n);
                }
            }
        }
        else
        {
            for(int j=1; j<=n; j++)
            {
                if(a[j][ans[i]-n] == 0)
                {
                    deg[j]--;
                    if(deg[j] == 0) heap(1,j);
                }
            }
        }
    }
    printf("YES\n");
    for(int i=1; i<=n+m; i++) printf("%d ",ans[i]);
    printf("\n");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
