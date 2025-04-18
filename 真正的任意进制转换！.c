#include<stdio.h>
#include<math.h>
#include<string.h>
int a[10000];//不可避免的需要定义全局数组
char c[10000];
void f(int m,int n,char c[10000],int i)//功能为从m到n，对数c进行任意进制转换，其中i为c的长度
{
    int j;
    long long int x=0;
    char d;
    x=0;
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
}
int main()//函数使用示例
{
    int t,m,n,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        scanf("%s",&c);
        len=strlen(c);
        f(m,n,c,len);
        printf("\n");
    }
}
