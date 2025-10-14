#include<stdio.h>
#include<math.h>
#define eps 1e-8
double s(double x);
int x1,x2,y,y2,s1,s2;
int main()
{
    double l,r,mid1,mid2;
    scanf("%d%d%d%d",&x1,&y,&x2,&y2);
    scanf("%d%d",&s1,&s2);
    l=x1;
    r=x2;
    mid1 = (2*l+r)/3;
    mid2 = (l+2*r)/3;
    while(r-l>eps)
    {
        if(s(mid1) > s(mid2))
        {
            l=mid1;
        }
        else
        {
            r=mid2;
        }
        mid1 = (2*l+r)/3;
        mid2 = (l+2*r)/3;
    }
    printf("%.3f %.3f",l,s(l));



}
double s(double x)
{
    return s1*sqrt(y*y+(x-x1)*(x-x1))+s2*sqrt(y2*y2+(x-x2)*(x-x2));
}
