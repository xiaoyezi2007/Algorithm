#include<stdio.h>
#include<math.h>
int main()
{
    long long int x0,y0,x1,y1,x2,y2,n,a1,b1,a2,b2,gcd,a,b,x,y,n0,ans;
    long long unsigned zheng=0,Sz=0,Sx=0,f;

    scanf("%lld",&n);
    n0=n;
    scanf("%lld%lld",&x0,&y0);
    scanf("%lld%lld",&x1,&y1);
    a1=x1-x0;
    b1=y1-y0;
    if(fabs(a1)>=fabs(b1))
    {
        a=fabs(a1);
        b=fabs(b1);
    }
    else
    {
        a=fabs(b1);
        b=fabs(a1);
    }
    gcd=b;
    if(a!=0&&b!=0)
    {
        while(a%gcd)
        {
            b=gcd;
            gcd=a%gcd;
            a=b;

        }
    }
    else if(a==0)
        gcd=b;
    else
        gcd=a;

    zheng+=gcd-1;
    n-=2;
    while(n--)
    {
        scanf("%lld%lld",&x2,&y2);
        a2=x2-x0;
        b2=y2-y0;
        if(a1*b2-b1*a2<0)
            f=b1*a2-a1*b2;
        else
            f=a1*b2-b1*a2;
        Sz+=f/2u;
        if(f%2)
            Sx++;
        x=fabs(x2-x1);
        y=fabs(y2-y1);
        if(x>=y)
        {
            a=x;
            b=y;
        }
        else
        {
            a=y;
            b=x;
        }
        gcd=b;
        if(a!=0&&b!=0)
        {
            while(a%gcd)
            {
                b=gcd;
                gcd=a%gcd;
                a=b;

            }
        }
        else if(a==0)
            gcd=b;
        else
            gcd=a;
        zheng+=gcd-1;
        a1=a2;
        b1=b2;
        x1=x2;
        y1=y2;
    }
    if(fabs(a1)>=fabs(b1))
    {
        a=fabs(a1);
        b=fabs(b1);
    }
    else
    {
        a=fabs(b1);
        b=fabs(a1);
    }
    gcd=b;
    if(a!=0&&b!=0)
    {
        while(a%gcd)
        {
            b=gcd;
            gcd=a%gcd;
            a=b;

        }
    }
    else if(a==0)
        gcd=b;
    else
        gcd=a;

    zheng+=gcd-1;
    zheng+=n0;
    ans=Sz+1u-(-Sx+zheng)/2u;
    printf("%lld",ans);


}
