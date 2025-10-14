#include<stdio.h>
#include<math.h>
int a[30000000]={0};
int main()
{
    long long int n,t;
    int i,j;
    char c;
    scanf("%lld",&n);
    getchar();
    while(n--)
    {
        i=0;
        t=1;
        while(i<=3)
        {

            scanf("%c",&c);
            j=c-97;
            t+=pow((double) (10),(double)(2*i))*j;
            i++;
        }
        getchar();



        if(a[t])
            printf("Moca has already memorized this word!\n");
        else
            printf("Moca memorized a new word!\n");
        a[t]=1;
        }

    }
