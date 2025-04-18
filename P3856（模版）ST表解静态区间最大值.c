#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int lg[100005];
int st[100005][20];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=n;i++) scanf("%d",&st[i][0]);
    for(int j=1;j<=lg[n];j++)
    {
        for(int i=1;i<=n-(1<<j)+1;i++)
        {
            if(st[i][j-1]>=st[i+(1<<(j-1))][j-1]) st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int l=lg[y-x+1];
        if(st[x][l]>=st[y-(1<<l)+1][l]) printf("%d\n",st[x][l]);
        else printf("%d\n",st[y-(1<<l)+1][l]);
    }
}
