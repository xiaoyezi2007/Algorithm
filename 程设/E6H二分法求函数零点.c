#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i,n,r,l,mid;
    scanf("%lld",&n);
    l=1;
    r=n+2;
    while(r-l>1)
    {
        mid=(r+l)/2;
        if((long long int)(mid*log10(mid)+1)>n)
            r=mid;
        else if((long long int)(mid*log10(mid)+1)<n)
        {
            l=mid;
        }
        else
        {
            l=mid;
            break;
        }

    }
    printf("%lld",l);


}
