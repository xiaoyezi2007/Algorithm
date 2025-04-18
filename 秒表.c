#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
    int time=1;
    while(1)
    {
        printf("%d",time);
        int a=time,sum=0;
        while(a!=0)
        {
            a/=10;
            sum++;
        }
        while(sum--)
        {
            printf("\b");
        }
        time++;
        sleep(1);
    }

}
