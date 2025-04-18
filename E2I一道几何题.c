#include<stdio.h>
#include<math.h>

int main()
{
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    double a,b,c,p,s,r,A,B,C,t;
    a=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    r=a*b*c/(4*s);
    A=acos(1-a*a/(2*r*r));
    B=acos(1-b*b/(2*r*r));
    C=acos(1-c*c/(2*r*r));
    double n=2;
    long long int n1,a1,b1,c1;
    a1=A*1000000;
    b1=B*1000000;
    c1=C*1000000;
    while(++n)
    {
        n1=(2*acos(-1)/n)*1000000;
        if((a1%n1<=100||a1%n1>=n1-100)&&(b1%n1<=100||b1%n1>=n1-100)&&(c1%n1<=100||c1%n1>=n1-100))
            break;

    }
    t=n*(sqrt(2*r*r*(1-cos(2*acos(-1)/n))));
    printf("%f",t);


}
