#include<stdio.h>
#include<math.h>
//名称
int gcdf(int a,int b);

//测试
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",gcdf(a,b));
}


//函数体,使用请注意单独考虑负数
int gcdf(int a,int b)
{
    int i;
    if(a<b)
        {
            i=a;
            a=b;
            b=i;
        }
    if(b==0)
        return a;
    while(a%b!=0)
    {
        i=a%b;
        a=b;
        b=i;

    }
    return b;
}
