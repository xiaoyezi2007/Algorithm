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
int a[200005];
int b[200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            if(2*i<=n) printf("%d ",2*i);
        }
        for(int i=1;i<n;i++)
        {
            if(2*i-1<=n) printf("%d ",2*i-1);
        }
        printf("\n");
    }

}
