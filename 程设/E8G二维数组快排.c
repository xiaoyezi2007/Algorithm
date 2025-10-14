#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[11];
char name[1002][12];
int sco[1002][13];
int ans[1002];
int rise(const void *p1, const void *p2)
{
int v1, v2;
v1 = *((int *)p1);
v2 = *((int *)p2);
if(v1 > v2) return 1;
if(v1 < v2) return -1;
return 0;
}

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=n-1;i++)
    {
        getchar();
        scanf("%s%d",name[0],&sco[i][0]);
        strcpy(name[sco[i][0]],name[0]);
        for(j=1;j<=m;j++)
            scanf("%d",&sco[i][j]);

    }
    qsort(sco,n,sizeof(sco[0]),rise);
    for(i=1;i<=m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[sco[j][i]]!=0&&ans[j]==0)
            {
                ans[j]=sco[j][i];
                a[sco[j][i]]--;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",name[i+1],ans[i]);
    }
}
