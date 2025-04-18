#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
long long int a[100005]; // pay attention! the first node is a[1] and d[1]
long long int d[500005]; //no problem if >4*n
long long int b[500005];
void build(long long int l,long long int r,long long int p) //left of range , right of range ,the number of range
{
    if(l==r) //when the length of the range is 1
    {
        d[p]=a[l];
        return;
    }
    long long int m=l+((r-l)>>1);
    build(l,m,p<<1),build(m+1,r,(p<<1)+1);
    d[p]=d[p<<1]+d[(p<<1)+1];
}
long long int getsum(long long int l,long long int r,long long int s,long long int t,long long int p)//left and right for query range,left and right for range now,the number of range now
{
    if(l<=s&&r>=t) return d[p];//when now is smaller than query
    long long int m=s+((t-s)>>1);
    if(b[p])// when the signal is exist
    {
        d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p],b[p*2+1]+=b[p];//download the signal to "subnode"
        b[p]=0;// clear signal of this node
    }
    long long int sum=0;
    if(l<=m) sum+=getsum(l,r,s,m,2*p);
    if(r>m) sum+=getsum(l,r,m+1,t,2*p+1);
    return sum;
}
void update(long long int l,long long int r,long long int c,long long int s,long long int t,long long int p)//left and right for query range,plus what?,left and right for range now,the number of range now
{
    if(l<=s&&r>=t)//when now is smaller than query
    {
        d[p]+=(t-s+1)*c;
        b[p]+=c;
        return;
    }
    long long int m=s+((t-s)>>1);
    if(b[p]&&s!=t) //when there already has been a signal
    {
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p], b[p * 2 + 1] += b[p];
        b[p] = 0;
    }
    if(l<=m) update(l,r,c,s,m,p*2);
    if(r>m) update(l,r,c,m+1,t,2*p+1);//always puts the signal to the last range
    d[p]=d[p*2]+d[p*2+1];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    build(1,n,1);
    while(m--)
    {
        int op;
        scanf("%d",&op);
        {
            if(op==2)//this op query the sum of range x to y
            {
                long long int x,y;
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",getsum(x,y,1,n,1));
            }
            else//this operation plus k for all number in range x to y
            {
                long long int x,y,k;
                scanf("%lld%lld%lld",&x,&y,&k);
                update(x,y,k,1,n,1);
            }
        }
    }

}
