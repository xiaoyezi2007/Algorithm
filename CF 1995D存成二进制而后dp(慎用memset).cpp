#include <bits/stdc++.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
using namespace std;
int alphasum[20][500005];
char s[400005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,c,k;
        scanf("%d%d%d",&n,&c,&k);
        scanf("%s",s);
        bool good[400005]= {0};
        bool bad[400005]= {0};
        for(int i=0; i<c; i++)
        {
            for(int j=0; j<n; j++)
            {
                alphasum[i][j+1]=alphasum[i][j]+(s[j]==i+'A');
            }
        }

        for(int i=0; i<=n-k; i++)
        {
            int bit=0;
            for(int j=0; j<c; j++)
            {
                if(alphasum[j][i+k]-alphasum[j][i]!=0) bit|=(1<<j);
            }
            good[bit]=1;
        }

        good[(1<<(s[n-1]-'A'))]=1;
        for(int i=0; i<(1<<c); i++)
        {
            bad[i]=good[((1<<c)-1)^i];
        }
        for(int i=(1<<c)-1; i>=0; i--)
        {
            for(int j=0; j<c; j++)
            {
                bad[i]=bad[i|(1<<j)]|bad[i];
            }
        }

        int ans=10000000;
        for(int i=0; i<(1<<c); i++)
        {
            if(bad[i]==0) ans=min(ans,__builtin_popcount(i));
        }
        printf("%d\n",ans);

    }
}

