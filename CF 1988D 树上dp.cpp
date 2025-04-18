#include <bits/stdc++.h>
using namespace std;
long long int a[300005];
vector<int> edge[300005];
long long int dp[300005][30]; //if node x is killed in the round i,then the cost will be dp[x][i]
void dfs(int x,int father)
{
    for(int i=1;i<=23;i++)
    {
        dp[x][i]=a[x]*i;
    }
    for(int nxt:edge[x]) //means ergodic every node next to x
    {
        if(nxt==father) continue;  //this situation we serach repeatedly!
        dfs(nxt,x);
        for(int j=1;j<=23;j++) // the transition is dp[x][i]=a[x]*i+sigma(min(dp[y][j])for all j and i!=j)for all y that next to x    !!!!!
        {
            long long int mi=1000000000000000000;
            for(int h=1;h<=23;h++)
            {
                if(j==h) continue;
                if(dp[nxt][h]<=mi) mi=dp[nxt][h];
            }
            dp[x][j]+=mi;
        }
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=1,x,y; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);// push_back means add a element in the end of vector
            edge[y].push_back(x);
        }
        dfs(1,0); // let the first node be the head of all dp
        long long int ans=dp[1][1];
        for(int i=1;i<=23;i++) //so ergodic all the round and find the min answer
        {
            if(dp[1][i]<=ans) ans=dp[1][i];
        }

        printf("%lld\n",ans);
        for(int i=1;i<=n;i++)
        {
            edge[i].clear();
            memset(dp[i],0,sizeof(dp[i]));
        }
    }
}
