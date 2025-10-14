#include<stdio.h>
#include<math.h>
void f(int n);

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
        printf("1");
    else if(n==2)
        printf("10");
    else
    {
        f(n);
        printf("1");
    }


}

void f(int n)
{
    if(n==3)
    {
        printf("10");
        return;
    }

    else if(n==4)
    {
        printf("100");
        return;
    }
    else
    {
        if(n%2)
        {
            f(n/2+1);
            f(n/2+1);
        }
        else
        {
            f(n/2);
            f(n/2+1);
        }
    }

}
