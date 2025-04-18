#include<stdio.h>
#include<math.h>
int a[10000];
char c[10000];
int main()
{
    int t,m,n,i,j;
    long long int x=0;

    char d;
    scanf("%d",&t);
    while(t--)
    {
        x=0;
        scanf("%d%d",&m,&n);
        i=0;
        scanf(" %c",&c[i]);
        while((c[i]>='0'&&c[i]<='9')||(c[i]>='A'&&c[i]<='Z'))
        {
            i++;
            scanf("%c",&c[i]);


        }
        j=0;
        while(i--)
        {
            if(c[i]>='0'&&c[i]<='9')
                x+=(double)(c[i]-'0')*pow(m,j);
            else
                x+=(double)(c[i]-'A'+10)*pow(m,j);
            j++;
        }
        i=0;
        if(x==0)
            printf("0");
        while(x)
        {
            if(n<0)
            {
                if(x%n<0)
                    a[i]=x%n-n;
                else
                    a[i]=x%n;
            }
            else
                a[i]=x%n;

            if(n<0)
            {
                if(x%n==0)
                    x=x/n;
                else
                    {
                        if(x%n<0)
                            x=x/n+1;
                        else
                            x=x/n;
                    }
            }
            else
                x=x/n;
            i++;
        }
        while(i--)
        {
            if(a[i]<=9)
            {
                printf("%d",a[i]);

            }
            else
            {
                d=a[i]-10+'A';
                printf("%c",d);
            }
        }
        printf("\n");
    }
}
