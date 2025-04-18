#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
long long int l[3000];
long long int r[3000];
long long int node[3000][2];
long long int cross[3000];
long long int z[3000];
long long int ans=0;
int cmp(const void *p1, const void *p2)
{
    long long int * a1=(long long int *)p1;
    long long int * a2=(long long int *)p2;
    if(a1[1]<a2[1]) return -1;
    if(a1[1]>a2[1]) return 1;
    return 0;
}
int cmpone(const void *p1, const void *p2)
{
    long long int a1=*(long long int *)p1;
    long long int a2=*(long long int *)p2;
    if(a1<a2) return -1;
    if(a1>a2) return 1;
    return 0;
}
long long int lower_bound(long long int left, long long int right, long long int key) //下界二分查找（找出第一个值不小于key的位置）
{
    while(left < right) //条件为小于而非小于等于
    {
        long long int mid = left + (right - left) / 2;
        if(cross[mid] >= key) right = mid; //此处为大于等于
        else left = mid + 1; //此处必须要+1
    }
    return left;
}
int find(long long int key,long long int low,long long int high)//功能为对升序数组二分查找，返回前缀，若连续多项相同则输出第一项。b为查找对象，key为要查找的数，low与high确定查找范围
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==z[mid])
        {
            return 1;
        }
        else if(key<z[mid])
            high=mid-1;
        else
            low=mid+1;

    }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&l[i],&r[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%lld%lld",&node[i][0],&node[i][1]);
    }
    qsort(node,m,sizeof(node[0]),cmp);
    int maxnode=0;
    for(int i=0;i<m;i++)
    {
        long long int x=node[i][0];
        long long int y=node[i][1];
        if(i!=0 && node[i][1]>node[i-1][1])
        {
            maxnode=i;
        }
        int zcnt=0;
        for(int j=0;j<maxnode;j++)
        {
            if(((1e9+1)-node[j][0])/node[j][1]<((1e9+1)-x)/y)
            {
                cross[j]=1e9+1;
            }
            else if((-(1e9+1)-node[j][0])/node[j][1]>(-(1e9+1)-x)/y)
            {
                cross[j]=-(1e9+1);
            }
            else
            {
                double real=node[j][0]-1.0*node[j][1]*(x-node[j][0])/(y-node[j][1]);
                cross[j]=(long long int) real;
                if((y-node[j][1])*(cross[j]-node[j][0])==(node[j][0]-x)*node[j][1])
                {
                    z[zcnt++]=cross[j];
                }
            }
        }
        qsort(cross,maxnode,sizeof(cross[0]),cmpone);
        qsort(z,zcnt,sizeof(z[0]),cmpone);
        for(int j=0;j<n;j++)
        {
            long long int lid=lower_bound(0,maxnode,l[j]);
            long long int rid=lower_bound(0,maxnode,r[j]);
            if(find(r[j],0,zcnt-1)==0&&lid==rid)
            {
                if(ans<y*(r[j]-l[j])) ans=y*(r[j]-l[j]);
            }
        }
    }
    printf("%lld",ans);
}
