#include<stdio.h>
#include<math.h>
#include<string.h>
int a[10000];//���ɱ������Ҫ����ȫ������
char c[10000];
void f(int m,int n,char c[10000],int i)//����Ϊ��m��n������c�����������ת��������iΪc�ĳ���
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
int main()//����ʹ��ʾ��
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
