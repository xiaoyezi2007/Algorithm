#include<stdio.h>
#include<math.h>
#include<string.h>
int b[200000];//������Ŀǰ�����Ǳ����
char a[200000];
void f(int m,int n,char a[200000],int len)//����Ϊ����һ��a�ַ����������������m����ת��Ϊn���ƣ�lenΪ���ĳ��ȣ�����m��n��С�ڵ���10
{
    int i=0,h=0,sum=0,k;
    if(a[0]=='0')//ʹ��ʱ��С�����λ�����ж���0�����
    {
        printf("0");
    }
    while(i<len)
    {
        k=a[i]-'0';
        sum+=k*pow((double)(m),(double)(len-i-1));//���ʱ�ճ������Ż�pow
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
        printf("%d",b[i]);//ע�ⲹ����
        i--;
    }
}
int main()//ʹ��ʾ��
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
