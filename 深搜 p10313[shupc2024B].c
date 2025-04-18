#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define max2(a,b) ((a)>(b)?(a):(b))
int ans=0,n,m;
void dfs4(int sco,char pan[15][15])
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(pan[i][j+1]=='.'&&pan[i+1][j]=='.'&&pan[i+1][j+1]=='.'&&pan[i+1][j+2]=='.'&&pan[i+2][j+1]=='.')
            {
                if(sco+5>ans)
                {
                    ans=sco+5;
                    if(ans==18)
                    {
                        printf("%d",ans);
                        exit(0);
                    }
                }
                return;
            }
        }
    }
    if(sco>ans) ans=sco;
}
void dfs3(int sco,char pan[15][15])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(pan[i][j+1]=='.'&&pan[i+1][j]=='.'&&pan[i+1][j+1]=='.'&&pan[i][j]=='.')
            {
                pan[i][j+1]=pan[i+1][j]=pan[i+1][j+1]=pan[i][j]='#';
                dfs4(sco+4,pan);
                pan[i][j+1]=pan[i+1][j]=pan[i+1][j+1]=pan[i][j]='.';
            }
        }
    }
    dfs4(sco,pan);
}
void dfs2(int sco,char pan[15][15])
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(pan[i][j+1]=='.'&&pan[i+1][j]=='.'&&pan[i+2][j+1]=='.'&&pan[i+1][j+2]=='.')
            {
                pan[i][j+1]=pan[i+1][j]=pan[i+2][j+1]=pan[i+1][j+2]='#';
                dfs3(sco+4,pan);
                pan[i][j+1]=pan[i+1][j]=pan[i+2][j+1]=pan[i+1][j+2]='.';
            }
        }
    }
    dfs3(sco,pan);
}
void dfs1(int sco,char pan[15][15])
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(pan[i][j]=='.'&&pan[i+1][j+1]=='.'&&pan[i+2][j]=='.'&&pan[i][j+2]=='.'&&pan[i+2][j+2]=='.')
            {
                pan[i][j]=pan[i+1][j+1]=pan[i+2][j]=pan[i][j+2]=pan[i+2][j+2]='#';
                dfs2(sco+5,pan);
                pan[i][j]=pan[i+1][j+1]=pan[i+2][j]=pan[i][j+2]=pan[i+2][j+2]='.';
            }
        }
    }
    dfs2(sco,pan);
}
int main()
{
    scanf("%d%d",&n,&m);
    char a[15][15];
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    dfs1(0,a);
    printf("%d",ans);
}
