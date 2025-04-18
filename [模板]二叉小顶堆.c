#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) (a)<(b)?(a):(b)
int d[1000005];
int main()
{
    int n;
    int size=0;
    scanf("%d",&n);
    while(n--)
    {
        int op;
        scanf("%d",&op);
        switch(op)
        {
        case 1: //add a new element
        {
            int x;
            scanf("%d",&x);
            size++;
            d[size]=x;
            int t=size;
            while(t>1&&d[t]<d[t/2])
            {
                int temp=d[t];
                d[t]=d[t/2];
                d[t/2]=temp;
                t/=2;
            }
            break;
        }
        case 2: //print the min
            printf("%d\n",d[1]);
            break;
        case 3: //delete the min
        {
            int temp1=d[1];
            d[1]=d[size];
            d[size]=temp1;
            size--;
            int t=1;
            while(t*2<=size)
            {
                int nxt=2*t;
                if(nxt+1<=size&&d[nxt+1]<d[nxt]) nxt++;
                if(d[nxt]>=d[t]) break;
                int temp2=d[t];
                d[t]=d[nxt];
                d[nxt]=temp2;
                t=nxt;
            }
        }

        }
    }

}
