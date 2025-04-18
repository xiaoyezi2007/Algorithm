#include<stdio.h>
#include<math.h>
int isprime(int a);


int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",isprime(a));
}


int isprime(int a)
{
    int i,step;
    if(a==1)
        return 0;
    else if(a==2||a==3||a==5)
        return 1;
    else if(a%2==0||a%3==0||a%5==0)
        return 0;
    else
    {
        step=2;
        for(i=7;i*i<=a;i+=step)
        {
            if(a%i==0)
            {
                return 0;
            }
            step=6-step;
        }
    }
    return 1;


}
