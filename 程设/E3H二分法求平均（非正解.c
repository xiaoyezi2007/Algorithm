#include<stdio.h>
#include<math.h>
double data[500001];
double a[500001];
double sum[500001];
double b[500001];
int main()
{
    int n,m,i;
    double ma=20,mi=20000,mid,ans,dp;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&data[i]);
        ma=fmax(ma,data[i]);
        mi=fmin(mi,data[i]);
    }
    while((ma-mi)>0.05)
    {
        mid=(ma+mi)/2;
        for(i=1;i<=n;i++)
        {
            a[i]=data[i]-mid;
            sum[i]=sum[i-1]+a[i];
            b[i]=fmax(b[i-1]+a[i],a[i]);
        }
        ans=sum[m];
        for(i=m+1;i<=n;i++)
        {
            dp=b[i-m+1]+sum[i]-sum[i-m+1];
            if(ans<dp)
            {
                ans=dp;
            }
        }
        if(ans>=0)
        {
            mi=mid;
        }
        else
        {
            ma=mid;
        }

    }
    if((int)(mid*10)%10>=5)
        printf("%d",(int)(mid+1));
    else
        printf("%d",(int)(mid));
}
