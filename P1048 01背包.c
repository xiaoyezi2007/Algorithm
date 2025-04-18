#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int dp[2][1005];
int value[105],weight[105];
int main()
{
    int t,m;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&weight[i],&value[i]);
    }
    int k=0;
    for(int i=1;i<=m;i++)
    {
        k=(k+1)%2;
        for(int j=t;j>=0;j--)
        {
            if(j>=weight[i])
            {
                if(dp[(k+1)%2][j-weight[i]]+value[i]>=dp[(k+1)%2][j]) dp[k][j]=dp[(k+1)%2][j-weight[i]]+value[i];
                else dp[k][j]=dp[(k+1)%2][j];
            }
            else
            {
                dp[k][j]=dp[(k+1)%2][j];
            }
        }

    }
    printf("%d",dp[k][t]);
}
