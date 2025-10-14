#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) ((a)<(b)?(a):(b))
int id[10000];
int sum[10000];
int lian[10000][2];
int ans[10000];
int d[10000][10000];
int n,e;
int cmp(const void *p1,const void *p2)
{
    int u1=*(int *)p1;
    int u2=*(int *)p2;
    if(sum[u1]>sum[u2]) return 1;
    if(sum[u1]<sum[u2]) return -1;
    if(u1>u2) return 1;
    if(u1<u2) return -1;
    return 0;
}
int isconnect(int a,int b)
{
    int re[10000]={0};
    int l=0,r=0;
    int dui[10000]={0};
    dui[0]=a;
    re[a]=0;
    while(l<=r)
    {
        for(int i=0;i<n;i++)
        {
            if(d[i][dui[l]]==1&&re[i]==0)
            {
                r++;
                dui[r]=i;
                re[i]=1;
            }
        }
        l++;
        if(re[b]==1) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&e);
    int all=0;
    int add=0;
    for(int i=0;i<e;i++)
    {
        scanf("%d",&id[i]);
        scanf("%d%d%d",&lian[id[i]][0],&lian[id[i]][1],&sum[id[i]]);
    }
    qsort(id,e,sizeof(id[0]),cmp);
    for(int i=0;i<e;i++)
    {
        if(isconnect(lian[id[i]][0],lian[id[i]][1]))
        {
            continue;
        }
        all++;
        d[lian[id[i]][0]][lian[id[i]][1]]=d[lian[id[i]][1]][lian[id[i]][0]]=1;
        ans[id[i]]=1;
        add+=sum[id[i]];
        if(all==n-1) break;

    }
    printf("%d\n",add);
    for(int i=1;i<=e;i++)
    {
        if(ans[i]==1)
        {
            printf("%d ",i);
        }
    }

}

