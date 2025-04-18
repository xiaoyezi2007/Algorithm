#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
long long int a[400005];
long long int b[400005];
long long int skip[400005];
long long int submit[400005];
long long int cost[400005];
long long int idc[400005];
int siz=0;
void push(long long int spend,int id)
{
    siz++;
    cost[siz]=spend;
    idc[siz]=id;
    int t=siz;

    while(t>1&&cost[t]<cost[t/2])
    {
        long long int temp=cost[t];
        cost[t]=cost[t/2];
        cost[t/2]=temp;
        temp=idc[t];
        idc[t]=idc[t/2];
        idc[t/2]=temp;
        t/=2;
    }
}
void pop()
{
    long long int temp1=cost[1];
    cost[1]=cost[siz];
    cost[siz]=temp1;
    temp1=idc[1];
    idc[1]=idc[siz];
    idc[siz]=temp1;
    siz--;
    int t=1;
    while(t*2<=siz)
    {
        long long int nxt=2*t;
        if(nxt+1<=siz&&cost[nxt+1]<cost[nxt]) nxt++;
        if(cost[nxt]>=cost[t]) break;
        long long int temp2=cost[t];
        cost[t]=cost[nxt];
        cost[nxt]=temp2;
        temp2=idc[t];
        idc[t]=idc[nxt];
        idc[nxt]=temp2;
        t=nxt;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
        }
        long long int head=1;
        long long int lasthead=0;
        skip[1]=0;
        while(head<=n)
        {
            for(int i=head; i>lasthead; i--)
            {
                if(b[i]>head)
                {
                    push(skip[head]+a[i],b[i]);
                }
                skip[i]=skip[head];
            }

            while(siz>0&&idc[1]<=head)
            {
                pop();
            }
            if(siz>0)
            {
                lasthead=head;
                head=idc[1];
                skip[head]=cost[1];
                while(siz>0&&idc[1]<=head) pop();
            }
            else
            {
                break;
            }
        }
        long long int ans=0;
        for(int i=1;i<=n;i++)
        {
            submit[i]=submit[i-1]+a[i];
        }
        for(int i=1; i<=head; i++)
        {

            if(submit[i]-skip[i]>ans)
            {
                ans=submit[i]-skip[i];
            }
        }
        printf("%lld\n",ans);
        for(int i=1; i<=n; i++)
        {
            submit[i]=0;
            skip[i]=0;
            idc[i]=cost[i]=0;
            siz=0;
        }
    }

}
//by xiaoyezi2007
