#include<stdio.h>
#include<math.h>
#include<string.h>
int b[200000];//该数组目前来看是必须的
char a[200000];
void f(int m,int n,char a[200000],int len)//功能为输入一个a字符串代表数，将其从m进制转化为n进制，len为数的长度，其中m，n均小于等于10
{
    int i=0,h=0,sum=0,k;
    if(a[0]=='0')//使用时请小心最高位可能有多余0会出错
    {
        printf("0");
    }
    while(i<len)
    {
        k=a[i]-'0';
        sum+=k*pow((double)(m),(double)(len-i-1));//如果时空超限请优化pow
        i++;
    }
    i=0;
    while(sum)
    {
        b[i]=sum%n;
        sum=sum/n;
        h++;
        i++;
    }
    i=h-1;
    while(i+1)
    {
        printf("%d",b[i]);//注意补换行
        i--;
    }
}
int main()//使用示例
{
    int t,m,n,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        scanf("%s",&a);
        len =strlen(a);
        f(m,n,a,len);
        printf("\n");
    }
}
