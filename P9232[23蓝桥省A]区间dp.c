#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define ep 1e-7
int main()
{
    int m;
    long long int ans=0;
    char a;
    scanf("%d",&m);
    getchar();
    while(scanf("%c",&a)!=EOF)
    {
        ans= (ans*10)%m;
        ans+=a-'0';
        ans=ans%m;
    }
    printf("%lld",ans);
}
//by xiaoyezi2007
