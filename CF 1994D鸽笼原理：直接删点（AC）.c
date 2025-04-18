#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int a[2005];
int hash1[2005];
int ans[2005][2];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=n-1;i>=1;i--)
        {
            int r[2005]={0};
            for(int j=1;j<=n;j++)
            {
                if(hash1[j]==1) continue;
                if(r[a[j]%i]!=0)
                {
                    ans[i][0]=j;
                    ans[i][1]=r[a[j]%i];
                    hash1[j]=1;
                    break;
                }
                r[a[j]%i]=j;
            }
        }
        memset(hash1,0,sizeof(hash1));
        puts("YES");
    for(int i=1;i<=n-1;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
    }


    return 0;
}

