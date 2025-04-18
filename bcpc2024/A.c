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

int main()
{
    int x;
    scanf("%d",&x);
    int ans=0,k=0;
    for(int i=1;i<2024;i++)
    {
        int t=(x*i)%2024;
        if(t>ans)
        {
            ans = t;
            k = i;
        }
    }
    printf("%d",k);
}
