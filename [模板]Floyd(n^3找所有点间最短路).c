#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) (a)<(b)?(a):(b)
int f[2000][2000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j) f[i][j]=50000000; //give positive infinity at first
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w<f[u][v])  //prevent from self-loop
        {
            f[u][v]=w;
            f[v][u]=w;
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int x=1;x<=n;x++)
        {
            for(int y=1;y<=n;y++)
            {
                f[x][y] = min2(f[x][y], f[x][i] + f[i][y]);//f is for the sub-graph of node 1,2,...,i the least path
                f[y][x]=f[x][y];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(f[i][j]!=50000000) printf("%d ",f[i][j]); //prevent from not connected
            else printf("0 ");
        }
        printf("\n");
    }

}
